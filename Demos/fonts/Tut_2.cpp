#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;


	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");
	ngl_init_ttf();

	ngl_entity mensaje;
	ngl_ttf_font *fuente;
	ngl_color color_texto;

	fuente=ngl_load_font("amazon.ttf", 65);
	ngl_font_text_solid_utf(&mensaje, fuente, "Nautilus Game Library", color_texto);

	mensaje.x=320;
	mensaje.y=240;

	ngl_paint(&mensaje);
	ngl_frame();

	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			Salir=1;
		}
	}

	ngl_unload_font(fuente);
	mensaje.unload();

	ngl_ttf_quit();
	ngl_quit();
	printf("\n");

	return 0;
}
