#include "Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;
	unsigned char fase;
	char ctest;

	int eje_x;
	int eje_y;

	ngl_create_screen(m800x600);
	ngl_screen.set_main_text("Nautilus Game Library 0.3", "");
	ngl_init_ttf();

	ngl_entity fondo;
	ngl_entity mensaje;
	ngl_entity mensaje2;

	ngl_ttf_font *fuente;
	ngl_ttf_font *fuente2;
	ngl_ttf_font *fuente3;
	ngl_ttf_font *fuente4;
	ngl_ttf_font *fuente5;
	ngl_ttf_font *fuente6;
	
	ngl_color color_texto;
	ngl_color color_texto2;
	
	fondo.load("fondo.png");
	fondo.x=400;
	fondo.y=300;
	
	fuente=ngl_load_font("Amaze.ttf", 60);
	fuente2=ngl_load_font("Armenschrift.ttf", 60);
	fuente3=ngl_load_font("Battlestar.ttf", 25);
	fuente4=ngl_load_font("Bearpaw.ttf", 50);
	fuente5=ngl_load_font("Blade-Runner-Movie-Font.ttf", 20);
	fuente6=ngl_load_font("Brushed.ttf", 40);
	
	ngl_font_set_color(&color_texto, 0, 255, 0);
	ngl_font_set_color(&color_texto2, 0, 0, 128);

	mensaje.x=400;
	mensaje.y=150;

	mensaje2.x=400;
	mensaje2.y=300;

	fase=1;

	ngl_rand_seed();
	
	ngl_timer crono;
	ngl_timer crono2;
	
	Salir=0;
	while (Salir==0) {
		if (ngl_key(_a)>0) {
			Salir=1;
		}
	}
	
	crono.start();

	Salir=0;
	while (Salir==0) {
		ngl_clear_screen();

		switch (fase) {
			case 1:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Modo solid", color_texto);
					ngl_font_text_solid_basic(&mensaje2, fuente, "Nautilus Game Library", color_texto);
				} else {
					fase=2;
					crono.start();
				}
			break;

			case 2:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Modo shaded", color_texto);
					ngl_font_text_shaded_basic(&mensaje2, fuente, "Nautilus Game Library", color_texto, color_texto2);
				} else {
					fase=3;
					crono.start();
					crono2.start();
				}
			break;

			// Animacion de colores
			case 3:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Color dinamico", color_texto);
					
					if (crono2.get_ticks()>250) {
						ngl_font_set_color(&color_texto2, ngl_rand(0, 255), ngl_rand(0, 255), ngl_rand(0, 255));
						crono2.start();
					}
					
					ngl_font_text_solid_basic(&mensaje2, fuente, "Nautilus Game Library", color_texto2);
				} else {
					fase=4;
					crono.start();
				}
			break;

			case 4:
				if (crono.get_ticks()<5000) {
					if (crono2.get_ticks()>250) {
						ngl_font_set_color(&color_texto2, ngl_rand(0, 255), ngl_rand(0, 255), ngl_rand(0, 255));
						crono2.start();
					}

					ngl_font_text_solid_basic(&mensaje, fuente, "Fondo dinamico", color_texto);
					ngl_font_text_shaded_basic(&mensaje2, fuente, "Nautilus Game Library", color_texto, color_texto2);
				} else {
					fase=5;
					crono2.stop();
					crono.start();
				}
			break;
			
			// Tipos de letra
			case 5:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Fuente Armenschrift", color_texto);
					ngl_font_text_solid_basic(&mensaje2, fuente2, "Nautilus Game Library", color_texto);
				} else {
					fase=6;
					crono.start();
				}
			break;

			case 6:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Fuente Battlestar", color_texto);
					ngl_font_text_solid_basic(&mensaje2, fuente3, "Nautilus Game Library", color_texto);
				} else {
					fase=7;
					crono.start();
				}
			break;

			case 7:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Fuente Bearpaw", color_texto);
					ngl_font_text_solid_basic(&mensaje2, fuente4, "Nautilus Game Library", color_texto);
				} else {
					fase=8;
					crono.start();
				}
			break;

			case 8:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Fuente Blade Runner", color_texto);
					ngl_font_text_solid_basic(&mensaje2, fuente5, "Nautilus Game Library", color_texto);
				} else {
					fase=9;
					crono.start();
				}
			break;

			case 9:
				if (crono.get_ticks()<5000) {
					ngl_font_text_solid_basic(&mensaje, fuente, "Fuente Brushed", color_texto);
					ngl_font_text_solid_basic(&mensaje2, fuente6, "Nautilus Game Library", color_texto);
				} else {
					fase=9;
					crono.start();
				}
			break;
		}

		ngl_paint(&fondo);
		ngl_paint(&mensaje);
		ngl_paint(&mensaje2);
		ngl_frame();

		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			Salir=1;
		}
	}
	
	fondo.unload();

	ngl_unload_font(fuente);
	ngl_unload_font(fuente2);
	ngl_unload_font(fuente3);
	ngl_unload_font(fuente4);
	ngl_unload_font(fuente5);
	ngl_unload_font(fuente6);

	ngl_ttf_quit();
	ngl_quit();
	printf("\n");

	return 0;
}
