#include "Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;
	unsigned char impacto;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library BETA 0.3", "");

	ngl_entity graphic1;
	ngl_entity graphic2;
	ngl_entity graphic3;

	graphic1.load("bloque1.png");
	graphic1.x=320;
	graphic1.y=240;

	graphic2.load("bloque2.png");
	graphic2.x=0;
	graphic2.y=240;
	graphic2.angle=0;

	graphic3.load("bloque3.png");
	graphic3.x=320;
	graphic3.y=240;

	ngl_paint(&graphic1);
	ngl_paint(&graphic2);
	ngl_frame();

	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_a);
		if (Tecla>0) {
			ngl_advance(&graphic2, 1);
			impacto=0;
			impacto=ngl_collision(&graphic1, &graphic2);

			ngl_clear_screen();
			ngl_paint(&graphic1);

			if (impacto==1) {
				ngl_paint(&graphic3);
			} else {
				ngl_paint(&graphic1);
			}

			ngl_paint(&graphic2);
			ngl_frame();
		}
		
		Tecla=0;
		Tecla=ngl_key(_s);
		if (Tecla>0) {
			graphic2.x=0;
			ngl_clear_screen();
			ngl_paint(&graphic1);
			ngl_paint(&graphic2);
			ngl_frame();
		}

		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla>0) {
			Salir=1;
		}

		ngl_frame();
	}

	graphic1.unload();
	graphic2.unload();
	graphic3.unload();

	ngl_quit();
	printf("\n");

	return 0;
}
