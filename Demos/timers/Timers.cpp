#include "Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;
	unsigned int altura;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");

	ngl_entity graphic1;
	graphic1.load("fighter.bmp");
	graphic1.x=220;
	graphic1.y=40;

	ngl_entity graphic2;
	graphic2.load("fighter.bmp");
	graphic2.x=320;
	graphic2.y=40;

	ngl_entity graphic3;
	graphic3.load("fighter.bmp");
	graphic3.x=420;
	graphic3.y=40;

	ngl_timer Timer1;
	ngl_timer Timer2;
	ngl_timer Timer3;

	ngl_paint(&graphic1);
	ngl_paint(&graphic2);
	ngl_paint(&graphic3);

	ngl_frame();

	Timer1.start();
	Timer2.start();
	Timer3.start();

	Salir=0;
	while (Salir<1) {
		if (Timer1.get_ticks()>100) {
			Timer1.start();
			graphic1.y++;
		}

		if (graphic1.y>480) {
			graphic1.y=-10;
		}

		if (Timer2.get_ticks()>50) {
			Timer2.start();
			graphic2.y++;
		}

		if (graphic2.y>480) {
			graphic2.y=-10;
		}

		if (Timer3.get_ticks()>25) {
			Timer3.start();
			graphic3.y++;
		}

		if (graphic3.y>480) {
			graphic3.y=-10;
		}

		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			Salir=1;
		}

		ngl_clear_screen();
		ngl_paint(&graphic1);
		ngl_paint(&graphic2);
		ngl_paint(&graphic3);
		ngl_frame();
	}

	graphic1.unload();
	graphic2.unload();
	graphic3.unload();

	ngl_quit();
	printf("\n");

	return 0;
}
