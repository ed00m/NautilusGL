#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m320x240);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");

	ngl_sound_init(22050, MIX_DEFAULT_FORMAT, 2, 4096);

	ngl_sound sonido1;
	sonido1.load("applause.wav");

	ngl_sound sonido2;
	sonido2.load("space.wav");

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
			sonido1.play_num(1);
		}

		Tecla=0;
		Tecla=ngl_key(_s);
		if (Tecla>0) {
			sonido2.play_num(2);
		}

		Tecla=0;
		Tecla=ngl_key(_w);
		if (Tecla>0) {
			sonido1.volume(10);
		}

		Tecla=0;
		Tecla=ngl_key(_e);
		if (Tecla>0) {
			sonido1.volume(100);
		}

	}

	sonido1.unload();
	sonido2.unload();

	ngl_sound_close();
	ngl_quit();
	printf("\n");

	return 0;
}
