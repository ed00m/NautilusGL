#if 0
#!/bin/sh
g++ -Wall `sdl-config --cflags` client.c -o client `sdl-config --libs` -lSDL_net
 
exit
#endif
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "SDL_net.h"

IPaddress ip;
TCPsocket sd;
int quit, len;
char buffer[512];
char identi[15];
char completo[15];
char remotehost[15];
unsigned int remoteport;

void
ngl_net_open(void)
{
	if (SDLNet_Init()<0) {
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
}

void
ngl_net_close(void)
{
	SDLNet_Quit();
}

void
ngl_net_open_client(void)
{
	/* Resolve the host we are connecting to */
	if (SDLNet_ResolveHost(&ip, remotehost, remoteport)< 0) {
		fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Open a connection with the IP provided (listen on the host's port) */
	if (!(sd = SDLNet_TCP_Open(&ip))) {
		fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
}

void
ngl_net_close_client(void)
{
	SDLNet_TCP_Close(sd);
}

void
ngl_net_write_client(void)
{
	if (SDLNet_TCP_Send(sd, (void *)completo, len) < len) {
		fprintf(stderr, "SDLNet_TCP_Send: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
}
 
int main(int argc, char **argv)
{
	char conexion, mensaje;

	strcpy(remotehost, "localhost");
	remoteport=2000;

	ngl_net_open();
	conexion=1;
	mensaje=0;

	quit = 0;
	while (quit==0)
	{
		if (conexion==1) {
			ngl_net_open_client();
			conexion=0;
			mensaje=1;
		}

		if (mensaje==1) {
			printf("Write something:\n>");
			gets(buffer);
			strcpy(identi, "Cliente 1: ");
			strcpy(completo, "");
			strcat(completo, identi);
			strcat(completo, buffer);

			len = strlen(completo) + 1;
			ngl_net_write_client();
 
			if (strcmp(buffer, "quit") == 0) {
				quit = 1;
			}
		}
	}
 
	ngl_net_close_client();
	ngl_net_close();
 
	return EXIT_SUCCESS;
}
