#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;
	unsigned char mouse_button;

	ngl_create_screen(m320x240);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");
	ngl_rand_seed();

	ngl_entity izq;
	izq.load("gris.png");

	izq.x=100;
	izq.y=120;

	ngl_entity dere;
	dere.load("rojo.png");

	dere.x=200;
	dere.y=120;

	ngl_frame();

	Salir=0;
	while (Salir==0) {
		mouse_button=ngl_mouse_get_button_state();

		switch (mouse_button) {
			case 0:
				ngl_clear_screen();
			break;

			case 1: // Izq
				ngl_paint(&izq);
			break;

			case 2: // Dere
				ngl_paint(&dere);
			break;
		}

		ngl_frame();

		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			Salir=1;
		}
	}

	izq.unload();
	dere.unload();

	ngl_quit();
	printf("\n");

	return 0;
}
