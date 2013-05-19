#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");

	ngl_entity tapiz;
	tapiz.load("tapiz.png");
	tapiz.x=640/2;
	tapiz.y=480/2;
	
	ngl_rand_seed();
	ngl_frame();
	
	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_a);
		if (Tecla==1) {
			ngl_geom_vline(&tapiz, ngl_rand(1, 640), ngl_rand(1, 480), ngl_rand(1, 480), ngl_rand(0, 255), ngl_rand(0, 255), ngl_rand(0, 255), ngl_rand(100, 255));
			ngl_paint(&tapiz);
		}

		Tecla=0;
		Tecla=ngl_key(_s);
		if (Tecla==1) {
			ngl_frame();
		}

		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			break;
		}
	}

	tapiz.unload();

	ngl_quit();
	printf("\n");

	return 0;
}
