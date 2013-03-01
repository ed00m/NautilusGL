#define BUF_SIZE 10

SDL_ffmpegFile *file = 0;
SDL_ffmpegAudioFrame *audioFrame[BUF_SIZE];
uint64_t ngl_sync = 0, offset = 0;

uint64_t ngl_getSync()
{
    if ( file )
    {
        if ( SDL_ffmpegValidAudio( file ) )
        {
            return ngl_sync;
        }
        if ( SDL_ffmpegValidVideo( file ) )
        {
            return ( SDL_GetTicks() % SDL_ffmpegDuration( file ) ) + offset;
        }
    }
    return 0;
}

SDL_mutex *mutex = 0;

void audioCallback( void *data, Uint8 *stream, int length )
{
    SDL_LockMutex( mutex );

    if ( audioFrame[0]->size == length )
    {
        ngl_sync = audioFrame[0]->pts;
        memcpy( stream, audioFrame[0]->buffer, audioFrame[0]->size );
        audioFrame[0]->size = 0;
        SDL_ffmpegAudioFrame *f = audioFrame[0];
        int i;
        for ( i = 1; i < BUF_SIZE; i++ ) audioFrame[i-1] = audioFrame[i];
        audioFrame[BUF_SIZE-1] = f;
    }
    else
    {
        memset( stream, 0, length );
    }

    SDL_UnlockMutex( mutex );

    return;
}

void
ngl_play_movie(const char nompeli[250])
{
	 file = SDL_ffmpegOpen(nompeli);
    mutex = SDL_CreateMutex();
    SDL_ffmpegSelectVideoStream( file, 0 );
    SDL_ffmpegStream *stream = SDL_ffmpegGetVideoStream( file, 0 );
    SDL_ffmpegSelectAudioStream( file, 0 );
    stream = SDL_ffmpegGetAudioStream( file, 0 );
    SDL_AudioSpec specs = SDL_ffmpegGetAudioSpec( file, 512, audioCallback );

	 int w, h;
    SDL_ffmpegGetVideoSize( file, &w, &h );
    SDL_ffmpegVideoFrame *videoFrame = SDL_ffmpegCreateVideoFrame();
	 videoFrame->surface = ngl_screen.graph;

    /* create a SDL_Rect for blitting of image data */
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = w;
    rect.h = h;

    if ( SDL_ffmpegValidAudio( file ) )
    {
        if ( SDL_OpenAudio( &specs, 0 ) < 0 )
        {
            fprintf( stderr, "Couldn't open audio: %s\n", SDL_GetError() );
            SDL_Quit();
            //return -1;
        }

        int frameSize = specs.channels * specs.samples * 2;
        int i;
        for ( i = 0; i < BUF_SIZE; i++ )
        {
            audioFrame[i] = SDL_ffmpegCreateAudioFrame( file, frameSize );
            if ( !audioFrame[i] )
            {
                /* no frame could be created, this is fatal */
                //goto CLEANUP_DATA;
            }
            SDL_ffmpegGetAudioFrame( file, audioFrame[i] );
        }
        SDL_PauseAudio( 0 );
    }

    int done = 0, mouseState = 0, fullscreen = 0;

    while ( !done )
    {
        SDL_Event event;
        while ( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
               case SDL_KEYDOWN:
						if ( event.key.keysym.sym == SDLK_q ) {
						  done = 1;
						}
                break;
            }
        }

        if ( mouseState )
        {
            int x, y;
            SDL_GetMouseState( &x, &y );
            uint64_t time = ( uint64_t )((( double )x / ( double )w ) * SDL_ffmpegDuration( file ) );
            SDL_LockMutex( mutex );
            if ( videoFrame ) videoFrame->ready = 0;
            if ( SDL_ffmpegValidAudio( file ) )
            {
                int i;
                for ( i = 0; i < BUF_SIZE; i++ )
                {
                    audioFrame[i]->size = 0;
                }
            }
            SDL_ffmpegSeek( file, time );
            offset = time - ( ngl_getSync() - offset );
            SDL_UnlockMutex( mutex );
        }
        if ( SDL_ffmpegValidAudio( file ) )
        {
            SDL_LockMutex( mutex );

				int i;
            for ( i = 0; i < BUF_SIZE; i++ )
            {
                if ( !audioFrame[i]->size )
                {
                    SDL_ffmpegGetAudioFrame( file, audioFrame[i] );
                }
            }
            SDL_UnlockMutex( mutex );
        }

        if ( videoFrame )
        {
            if ( !videoFrame->ready )
            {
                SDL_ffmpegGetVideoFrame( file, videoFrame );
            }
            else if ( videoFrame->pts <= ngl_getSync() )
            {
                if ( videoFrame->overlay )
                {
                    SDL_DisplayYUVOverlay( videoFrame->overlay, &rect );
                }
                else if ( videoFrame->surface )
                {
						  SDL_BlitSurface( videoFrame->surface, 0, ngl_screen.graph, 0 );
						  SDL_Flip(ngl_screen.graph);
                }
                videoFrame->ready = 0;
            }
        }
    }

CLEANUP_DATA:

    if ( SDL_ffmpegValidAudio( file ) )
    {
        SDL_PauseAudio( 1 );
        int i;
        for ( i = 0; i < BUF_SIZE; i++ )
        {
            SDL_ffmpegFreeAudioFrame( audioFrame[i] );
        }
    }

	if ( videoFrame )
    {
        SDL_ffmpegFreeVideoFrame( videoFrame );
    }
    SDL_ffmpegFree( file );
}
