#include "Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m320x240);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");

	ngl_sound_init(44100, MIX_DEFAULT_FORMAT, 2, 4096);

	ngl_music musica;
	musica.load("chariots_of_fire_vangelis.mp3");
	musica.play();

	ngl_frame();

	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla>0) {
			Salir=1;
		}

		Tecla=0;
		Tecla=ngl_key(_a);
		if (Tecla>0) {
			musica.pause();
		}

		Tecla=0;
		Tecla=ngl_key(_s);
		if (Tecla>0) {
			musica.resume();
		}

		Tecla=0;
		Tecla=ngl_key(_d);
		if (Tecla>0) {
			musica.rewind();
		}

		Tecla=0;
		Tecla=ngl_key(_f);
		if (Tecla>0) {
			musica.volume(10);
		}

		Tecla=0;
		Tecla=ngl_key(_g);
		if (Tecla>0) {
			musica.volume(50);
		}

	}

	musica.unload();

	ngl_sound_close();
	ngl_quit();
	printf("\n");

	return 0;
}
