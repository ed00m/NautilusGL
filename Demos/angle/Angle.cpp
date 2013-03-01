#include "Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;
	unsigned int angle;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library BETA 0.3", "");

	ngl_entity nave;

	nave.load("point.bmp");
	nave.x=320;
	nave.y=240;

	ngl_rand_seed();
	ngl_paint(&nave);
	ngl_frame();

	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_a);
		if (Tecla==1) {
			nave.angle=ngl_rand(0, 360);
		}

		Tecla=0;
		Tecla=ngl_key(_s);
		if (Tecla==1) {
			ngl_advance(&nave, 3);
			ngl_paint(&nave);
			ngl_frame();
		}
		
		Tecla=0;
		Tecla=ngl_key(_d);
		if (Tecla==1) {
			nave.x=320;
			nave.y=240;
		}

		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			Salir=1;
		}

		ngl_frame();
	}

	nave.unload();

	ngl_quit();
	printf("\n");

	return 0;
}
