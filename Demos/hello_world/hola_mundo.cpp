#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m800x600);
	ngl_screen.set_main_text("Nautilus Game Library BETA 0.3", "Hola mundo");
	ngl_entity icon_program;
	icon_program.load("pinguin.png");

	icon_program.set_main_icon();

	ngl_entity hello_world;
	hello_world.load("desktop.png");

	hello_world.x=400;
	hello_world.y=300;
	ngl_paint(&hello_world);
	ngl_frame();

	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			break;
		}
	}

	hello_world.unload();
	icon_program.unload();
	ngl_quit();
	printf("\n");

	return 0;
}
