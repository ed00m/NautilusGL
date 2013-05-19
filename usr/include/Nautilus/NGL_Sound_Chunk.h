class ngl_sound {
	public:
	ngl_sound();
	~ngl_sound();
	
	unsigned int level_volume;
	Mix_Chunk *mix_sound_id;
	
	unsigned char load(const char filename[50]);
	void unload(void);
	void play(void);
	void play_num(unsigned char num);
	
	void volume(unsigned char new_volume);
	void volume_up(void);
	void volume_down(void);
};
 
ngl_sound::ngl_sound()
{
	level_volume=50;
}

ngl_sound::~ngl_sound()
{
  
}

unsigned char
ngl_sound::load(const char filename[50])
{
	mix_sound_id=Mix_LoadWAV(filename); // Valida para WAVE, AIFF, RIFF, OGG, and VOC files
	if (!mix_sound_id) {
		return 1; // Error, archivo no cargado
	}

	Mix_VolumeChunk(mix_sound_id, level_volume);

	return 0; // Ok
}

void
ngl_sound::unload(void)
{
	Mix_FreeChunk(mix_sound_id);
}

void
ngl_sound::play(void)
{
	 Mix_PlayChannel(-1, mix_sound_id, 0);
}

void
ngl_sound::play_num(unsigned char num)
{
	 Mix_PlayChannel(num, mix_sound_id, 0);
}

void
ngl_sound::volume(unsigned char new_volume)
{
	if (new_volume>128) {
		new_volume=128;
	}

	level_volume=new_volume;
	Mix_VolumeChunk(mix_sound_id, level_volume);
}

void
ngl_sound::volume_up(void)
{
	if (level_volume<128) {
		level_volume++;
	}

	Mix_VolumeChunk(mix_sound_id, level_volume);
}

void
ngl_sound::volume_down(void)
{
	if (level_volume>0) {
		level_volume--;
	}

	Mix_VolumeChunk(mix_sound_id, level_volume);
}
