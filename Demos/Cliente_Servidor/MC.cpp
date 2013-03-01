#include "Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;

	ngl_create_screen(m640x480);
	ngl_screen.set_main_text("Nautilus Game Library - Cliente", "");
	
	int Socket_Con_Servidor;
	char Cadena[100];

	Socket_Con_Servidor=-1;
	while (Socket_Con_Servidor==-1) {
		Socket_Con_Servidor = Abre_Conexion_Inet ("localhost", "cpp_java");
	}

	ngl_entity player;
	player.load("blue.png");
	player.x=100;
	player.y=100;
	
	Salir=0;
	while (Salir==0) {
		if (ngl_key(_e)==1) {
			printf ("\nCliente: saliendo.\n");
			Salir=1;
		}
		
		if (Salir==0) {
			Lee_Socket (Socket_Con_Servidor, Cadena, 100);
			if (strlen(Cadena)>2) {
				if (strcmp(Cadena,"server A")==0) {
					player.x--;
					if (player.x<5) {
						player.x=5;
					}
				}

				if (strcmp(Cadena,"server D")==0) {
					player.x++;
					if (player.x>630) {
						player.x=630;
					}
				}
			
				if (strcmp(Cadena,"server W")==0) {
					player.y--;
					if (player.y<5) {
						player.y=5;
					}
				}

				if (strcmp(Cadena,"server S")==0) {
					player.y++;
					if (player.y>470) {
						player.y=470;
					}
				}
			}
		}

		ngl_clear_screen();
		ngl_paint(&player);

		ngl_frame();
	}
	
	close (Socket_Con_Servidor);
	player.unload();
	
	ngl_quit();
	printf("\n");

	return 0;
}
