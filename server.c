#if 0
#!/bin/sh
g++ -Wall `sdl-config --cflags` server.c -o server `sdl-config --libs` -lSDL_net
exit
#endif
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "SDL_net.h"

TCPsocket sd, csd0, csd1, csd2;
IPaddress ip;

unsigned int quit;

char buffer0[512];
char buffer1[512];
char buffer2[512];

char waiting0, waiting1, waiting2;
char reading0, reading1, reading2;

unsigned int localport;

void
ngl_net_open(void)
{
	if (SDLNet_Init()<0) {
		fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
		exit(EXIT_FAILURE);
	}
 
	/* Resolving the host using NULL make network interface to listen */
	if (SDLNet_ResolveHost(&ip, NULL, localport)<0) {
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
ngl_net_close(void)
{
	SDLNet_TCP_Close(sd);
	SDLNet_Quit();
}

void
ngl_net_open_client(char num)
{
	if (num==0) {
		if ((csd0 = SDLNet_TCP_Accept(sd))) {
			waiting0=0;
			reading0=1;
			printf("\nConectado el 0\n");
		}
	}

	if (num==1) {
		if ((csd1 = SDLNet_TCP_Accept(sd))) {
			waiting1=0;
			reading1=1;
			printf("\nConectado el 1\n");
		}
	}

	if (num==2) {
		if ((csd2 = SDLNet_TCP_Accept(sd))) {
			waiting2=0;
			reading2=1;
			printf("\nConectado el 2\n");
		}
	}
}

void
ngl_net_close_client(char num)
{
	if (num==0) {
		SDLNet_TCP_Close(csd0);
		quit=1;
		waiting0=1;
		reading0=0;
		printf("\nDesconectado el 0\n");
	}

	if (num==1) {
		SDLNet_TCP_Close(csd1);
		waiting1=1;
		reading1=0;
		printf("\nDesconectado el 1\n");
	}

	if (num==2) {
		SDLNet_TCP_Close(csd1);
		waiting2=1;
		reading2=0;
		printf("\nDesconectado el 2\n");
	}
}

unsigned char
ngl_net_read_client(char num)
{
	if (num==0) {
		if (SDLNet_TCP_Recv(csd0, buffer0, 512) > 0) {
			return 1;
		}

		return 0;
	}

	if (num==1) {
		if (SDLNet_TCP_Recv(csd1, buffer1, 512) > 0) {
			return 1;
		}

		return 0;
	}

	if (num==2) {
		if (SDLNet_TCP_Recv(csd2, buffer2, 512) > 0) {
			return 1;
		}

		return 0;
	}

	return 0;
}
 
int main(int argc, char **argv)
{
	localport=2000;

	waiting0=1;
	waiting1=1;
	waiting2=1;
	reading0=0;
	reading1=0;
	reading2=0;

	ngl_net_open();

	quit=0;
	while (quit==0) {
		if (waiting0==1) {
			ngl_net_open_client(0);
		}

		if (reading0==1) {
			if (ngl_net_read_client(0)==1) {
				puts(buffer0);

				if (strcmp(buffer0, "Cliente 0: quit") == 0) {
					ngl_net_close_client(0);
					quit=1;
				}
			}
		}

		if (waiting1==1) {
			ngl_net_open_client(1);
		}

		if (reading1==1) {
			if (ngl_net_read_client(1)==1) {
				puts(buffer1);

				if (strcmp(buffer1, "Cliente 1: quit") == 0) {
					ngl_net_close_client(1);
				}
			}
		}

		if (waiting2==1) {
			ngl_net_open_client(2);
		}

		if (reading2==1) {
			if (ngl_net_read_client(2)==1) {
				puts(buffer2);

				if (strcmp(buffer2, "Cliente 2: quit") == 0) {
					ngl_net_close_client(2);
				}
			}
		}
	}
 
	ngl_net_close();
 
	return EXIT_SUCCESS;
}
