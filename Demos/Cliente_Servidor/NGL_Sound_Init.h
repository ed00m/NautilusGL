unsigned int ngl_num_frecuency;
unsigned int ngl_num_channels;
unsigned int ngl_num_buffer;
Uint16 ngl_num_format;

unsigned char
ngl_sound_init(unsigned int new_frequency, unsigned int new_format, unsigned int new_channels, unsigned int new_buffer)
{
	char tmp;

	tmp=Mix_OpenAudio (ngl_num_frecuency, ngl_num_format, ngl_num_channels, ngl_num_buffer);
	if (tmp==-1) {
		return 1; // Error, sonido no inicializado
	}

	return 0;
}

void
ngl_sound_close(void)
{
	Mix_CloseAudio();
}
