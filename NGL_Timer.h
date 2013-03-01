class ngl_timer {
	public:

	ngl_timer(void);
	~ngl_timer(void);

	unsigned int start_ticks;
	unsigned int paused_ticks;

	unsigned char paused;
	unsigned char started;

	void start(void);
	void stop(void);
	unsigned int get_ticks(void);
	unsigned int pause(void);
	void unpause(void);

	unsigned char is_started(void);
	unsigned char is_paused(void);
};

ngl_timer::ngl_timer(void)
{
	start_ticks=0;
	paused_ticks=0;
	paused=0;
	started=0;
}

ngl_timer::~ngl_timer(void)
{

}

void
ngl_timer::start(void)
{
	started=1;
	paused=0;
	start_ticks=SDL_GetTicks();
}

void
ngl_timer::stop(void)
{
	started=0;
	paused =0;
}

unsigned int
ngl_timer::get_ticks(void)
{
	if (started>0) {
        	if (paused>0) {
				return paused_ticks;
        	} else {
				return SDL_GetTicks()-start_ticks;
        	}
	}
}

unsigned int
ngl_timer::pause(void)
{
	if ((started>0) && (paused<1)) {
		paused=1;
		paused_ticks=SDL_GetTicks()-start_ticks;
	}
}

void
ngl_timer::unpause(void)
{
	if (paused>0) {
        	paused=0;
        	start_ticks=SDL_GetTicks()- paused_ticks;
        	paused_ticks=0;
	}
}

unsigned char
ngl_timer::is_started(void)
{
	return started;
}

unsigned char
ngl_timer::is_paused(void)
{
	return paused;
}
