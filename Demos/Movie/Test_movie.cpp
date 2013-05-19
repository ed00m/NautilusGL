#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library - Movie", "");
	
	ngl_play_movie("Children of Dune - Inama Nushif.mp4");

	Salir=0;
	while (Salir==0) {
		if (ngl_key(_q)==1) {
			Salir=1;
		}

		ngl_frame();
	}
	
	ngl_quit();
	printf("\n");

	return 0;
}
