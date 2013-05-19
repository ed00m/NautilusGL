#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;
	unsigned char busqueda;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library - Pathfinding 1", "");

	ngl_entity player;
	player.x=212;
	player.y=121;
	
	ngl_entity target;
	target.x=113;
	target.y=107;
	
	ngl_entity escenario;
	escenario.load("laberinto1.png");
	escenario.x=320;
	escenario.y=240;
	
	ngl_entity zonas;
	zonas.load("laberinto1.png");
	
	ngl_geom_circle(&escenario, player.x, player.y, 5, 255, 0, 0, 255);
	ngl_geom_circle(&escenario, target.x, target.y, 5, 0, 255, 0, 255);
	
	ngl_blocks(&zonas);
	ngl_route sendero;
	sendero=ngl_path_find(player.x, player.y, target.x, target.y);

	unsigned int barrido;
	barrido=0;
	
	ngl_timer crono;
	crono.start();
	busqueda=0;
	
	Salir=0;
	while (Salir==0) {
		Tecla=0;
		Tecla=ngl_key(_q);
		if (Tecla==1) {
			break;
		}
		
		if (ngl_key(_a)==1) {
			if (busqueda==0) {
				busqueda=1;
				sendero=ngl_path_find(player.x, player.y, target.x, target.y);
			}
		}
		
		if (crono.get_ticks()>25) {
			crono.start();
			if (ngl_key(_s)==1) {
				barrido++;
				if (barrido>9000) {
					barrido=9000;
				}
				
				player.x=sendero.get_x(barrido);
				player.y=sendero.get_y(barrido);
				ngl_put_pixel(&escenario, player.x, player.y, 255, 0, 0, 0);

				ngl_paint(&escenario);
			}
		}

		ngl_frame();
	}
	
	escenario.unload();
	zonas.unload();

	ngl_quit();
	printf("\n");

	return 0;
}
