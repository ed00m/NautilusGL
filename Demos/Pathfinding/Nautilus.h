/*
 	C/C++
*/
#include "time.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include <iostream> // Pathfinding
#include <iomanip>
#include <queue>
#include <string.h>
#include <math.h>
#include <ctime>

/*
	SDL
*/
#define SDL_Surface ngl_surface
#define SDL_Rect ngl_rectangle
#define SDL_Color ngl_color
#include "SDL/SDL.h"

/*
	SDL_image
*/
#include "SDL/SDL_image.h"

/*
	SDL_gfx
*/
#include "SDL/SDL_gfxPrimitives.h"
#include "SDL/SDL_rotozoom.h"
#include "SDL/SDL_framerate.h"
#include "SDL/SDL_imageFilter.h"
#include "SDL/SDL_gfxBlitFunc.h"

/*
	SDL_ttf
*/
#define TTF_Font ngl_ttf_font
#include "SDL/SDL_ttf.h"

/*
	SDL_Mixer
*/
#include "SDL/SDL_mixer.h"

/*
	SDL_ffmpeg
*/
#include "SDL/SDL_ffmpeg.h"

/*
	LAN, Internet
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include "Server.h"
#include "Client.h"
#include "Socket.h"


/*
	Nautilus Game Library - NGL
*/
#include "NGL_MainScreen.h"
#include "NGL_Keyboard.h"
#include "NGL_Entity.h"
#include "NGL_Paint.h"
#include "NGL_Math.h"
#include "NGL_Plane.h"
#include "NGL_GFX.h"
#include "NGL_Mouse.h"
#include "NGL_Text.h"
#include "NGL_Sound_Init.h"
#include "NGL_Sound_Chunk.h"
#include "NGL_Sound_Music.h"
#include "NGL_Node.h"
#include "NGL_Timer.h"
#include "NGL_Scroll.h"
#include "NGL_Utils.h"

#include "NGL_Pathfinding.h"
#include "NGL_Movie.h"
#include "NGL_Net_Server.h"
#include "NGL_Net_Client.h"
#include "NGL_Net_Socket.h"
