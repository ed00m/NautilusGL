#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");
	
	ngl_scroll_v prueba;
	
	prueba.load("Ground2.png");
	prueba.set_x(320);
	prueba.set_y1(240);
	prueba.set_y2(720);
	prueba.direction=1;
	prueba.init=-240;
	prueba.limit=718;
	prueba.speed=1;
	prueba.paint();
	
	ngl_timer crono;
	crono.start();

	Salir=0;
	while (Salir==0) {
		if (ngl_key(_a)==1) {
			//if (crono.get_ticks()>2) {
				prueba.move();
				ngl_clear_screen();
				prueba.move();
				prueba.paint();
				ngl_frame();
				crono.start();
			//}
		}

		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			Salir=1;
		}
	}
	
	prueba.unload();
	
	ngl_quit();
	printf("\n");

	return 0;
}
