class ngl_music {
	public:
	ngl_music();
	~ngl_music();
	
	unsigned int level_volume;
	Mix_Music *mix_music_id;
	
	unsigned char load(const char filename[50]);
	void unload(void);
	void play(void);
	void stop(void);
	void pause(void);
	void resume(void);
	void rewind(void);
	void volume(unsigned int new_volume);
};

ngl_music::ngl_music()
{

}

ngl_music::~ngl_music()
{

}

unsigned char
ngl_music::load(const char filename[50])
{
	mix_music_id=Mix_LoadMUS (filename); // This can load WAVE, MOD, MIDI, OGG, MP3, FLAC
	if (!mix_music_id) {
		return 1; // Error, archivo no cargado
	}
	
	return 0;
}

void
ngl_music::unload(void)
{
	Mix_HaltMusic();
	Mix_FreeMusic(mix_music_id);
	mix_music_id=NULL;
}

void
ngl_music::play(void)
{
	Mix_PlayMusic (mix_music_id, -1);
}

void
ngl_music::stop(void)
{
	Mix_HaltMusic();
	Mix_FreeMusic (mix_music_id);
	mix_music_id=NULL;
}

void
ngl_music::pause(void)
{
	Mix_PauseMusic();
}

void
ngl_music::resume(void)
{
	Mix_ResumeMusic();
}

void
ngl_music::rewind(void)
{
	Mix_RewindMusic();
}

void
ngl_music::volume(unsigned int new_volume)
{
	if (new_volume>128) {
		new_volume=128;
	}

	Mix_VolumeMusic (new_volume);
}
 