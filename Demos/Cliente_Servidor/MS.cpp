#include "Nautilus/Nautilus.h"

int
main(int argc, char* args[] )
{
	unsigned char Salir;
	unsigned char Tecla;
	unsigned char tmp, tmp2;

	ngl_create_screen(m320x240);
	ngl_screen.set_main_text("Nautilus Game Library - Servidor", "");
	
	int Socket_Servidor;
	int Socket_Cliente;
	char Cadena[100];
	
	ngl_entity player;
	player.x=100;
	player.y=100;


	printf ("\nAbriendo socket de servidor...");
	Socket_Servidor = -1;
	while (Socket_Servidor ==-1) {
		if (ngl_key(_q)==1) {
			printf ("\nCancelado socket de servidor");
			exit(1);
		}
		Socket_Servidor = Abre_Socket_Inet ("cpp_java");
	}
	printf ("OK");
	

	printf ("\nAbriendo socket de cliente...");
	Socket_Cliente=-1;
	while (Socket_Cliente==-1) {
		if (ngl_key(_q)==1) {
			printf ("\nCancelado socket de cliente.\n");
			exit(1);
		}
		Socket_Cliente=Acepta_Conexion_Cliente (Socket_Servidor);
	}
	printf ("OK");
	

	tmp2=0;
	Salir=0;
	while (Salir==0) {
		if (ngl_key(_q)==1) {
			printf ("\nServidor: saliendo.");
			Salir=1;
		}

		if (ngl_key(_a)==1) {
			player.x--;
			if (player.x<5) {
				player.x=5;
			}
				
			strcpy (Cadena, "server A");
			Escribe_Socket (Socket_Cliente, Cadena, 100);
			strcpy (Cadena, "");
		}
		
		if (ngl_key(_d)==1) {
			player.x++;
			if (player.x>630) {
				player.x=630;
			}

			strcpy (Cadena, "server D");
			Escribe_Socket (Socket_Cliente, Cadena, 100);
			strcpy (Cadena, "");
		}
		
		if (ngl_key(_w)==1) {
			player.y--;
			if (player.y<5) {
				player.y=5;
			}

			strcpy (Cadena, "server W");
			Escribe_Socket (Socket_Cliente, Cadena, 100);
			strcpy (Cadena, "");
		}

		if (ngl_key(_s)==1) {
			player.y++;
			if (player.y>470) {
				player.y=470;
			}

			strcpy (Cadena, "server S");
			Escribe_Socket (Socket_Cliente, Cadena, 100);
			strcpy (Cadena, "");
		}

		ngl_frame();
	}

	close (Socket_Servidor);
	close (Socket_Cliente);

	ngl_quit();
	printf("\n");

	return 0;
}
