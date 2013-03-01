// SDL
void
ngl_alpha(ngl_entity *entity_id)
{
	SDL_SetAlpha(entity_id->graph, SDL_RLEACCEL | SDL_SRCALPHA, entity_id->alpha);
}

void
ngl_mask(ngl_entity *entity_id, unsigned char red, unsigned char green, unsigned char blue)
{
	Uint32 colorkey;

	colorkey=SDL_MapRGB(entity_id->graph->format, red, green, blue);
	SDL_SetColorKey(entity_id->graph,SDL_SRCCOLORKEY,colorkey );
}

void
putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	int bpp = surface->format->BytesPerPixel;
	int tmp;

	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	
	
	tmp=SDL_LockSurface(surface);
	if (tmp<0) {
		printf("\nngl error - putpixel - entidad no bloqueada");
	}

	switch (bpp) {
		case 1:
			*p = pixel;
		break;

		case 2:
			*(Uint16 *)p = pixel;
		break;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
				p[0] = (pixel >> 16) & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = pixel & 0xff;
			} else {
				p[0] = pixel & 0xff;
				p[1] = (pixel >> 8) & 0xff;
				p[2] = (pixel >> 16) & 0xff;
        		}
		break;
		case 4:
			*(Uint32 *)p = pixel;
		break;
	}

	SDL_UnlockSurface(surface);
}

void
ngl_put_pixel(ngl_entity *entity_id, unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	Uint32 color;

	color=SDL_MapRGB(entity_id->graph->format, r, g, b);
	putpixel(entity_id->graph, x, y, color);
}


Uint32
getpixel(SDL_Surface *surface, int x, int y)
{
	int bpp = surface->format->BytesPerPixel;

	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp) {
		case 1:
			return *p;
		break;

		case 2:
			return *(Uint16 *)p;
		break;

		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;
			break;

			case 4:
				return *(Uint32 *)p;
			break;

			default:
				return 0;
	}
}

unsigned int
ngl_get_pixel_r(ngl_entity *entity_id, unsigned int x, unsigned int y)
{
	Uint32 color;
	Uint8 Result;
	int tmp;

	tmp=SDL_LockSurface(entity_id->graph);
	if (tmp<0) {
		return 300; // Error, entidad no bloqueada
	}

	color=getpixel(entity_id->graph,x, y);
	Result=color>>16;
	SDL_UnlockSurface(entity_id->graph);

	return Result;
}

unsigned int
ngl_get_pixel_g(ngl_entity *entity_id, unsigned int x, unsigned int y)
{
	Uint32 color;
	Uint8 Result;
	int tmp;

	tmp=SDL_LockSurface(entity_id->graph);
	if (tmp<0) {
		return 300; // Error, entidad no bloqueada
	}

	color=getpixel(entity_id->graph,x, y);
	Result=color>>8;
	SDL_UnlockSurface(entity_id->graph);

	return Result;
}

unsigned int
ngl_get_pixel_b(ngl_entity *entity_id, unsigned int x, unsigned int y)
{
	Uint32 color;
	Uint8 Result;
	int tmp;

	tmp=SDL_LockSurface(entity_id->graph);
	if (tmp<0) {
		return 300; // Error, entidad no bloqueada
	}

	color=getpixel(entity_id->graph,x, y);
	Result=color & 0xFF;
	SDL_UnlockSurface(entity_id->graph);

	return Result;
}

// SDL_rotozoom
void
ngl_rotate(ngl_entity *entity_destiny, ngl_entity *entity_origin)
{
	entity_destiny->graph=rotozoomSurface(entity_origin->graph, entity_origin->angle, 1.0, 0);
}

// SDL_framerate
FPSmanager ngl_fps_manager;

void
ngl_set_fps(unsigned int new_rate)
{
	SDL_setFramerate (&ngl_fps_manager, new_rate);
}

unsigned int
ngl_get_fps(void)
{
	return SDL_getFramerate (&ngl_fps_manager);
}

/*
	Linea: hlineRGBA, nlineRGBA, lineRGBA, aalineRGBA, thickLineRGBA
	Rectangle: rectangleRGBA, roundedRectangleRGBA
	Box: boxRGBA, roundedBoxRGBA
	Circle: circleRGBA, aacircleRGBA, filledCircleRGBA
	Arc: arcRGBA
	Ellipse: ellipseRGBA, aaellipseRGBA, filledEllipseRGBA
	Pie: pieRGBA, filledPieRGBA
*/

// hline, vline, line, aaline, thickLine
unsigned char
ngl_geom_hline(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;
	
	tmp=hlineRGBA (entity_destiny->graph, x1, x2, y, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_vline(ngl_entity *entity_destiny, unsigned int x, unsigned int y1, unsigned int y2, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=vlineRGBA(entity_destiny->graph, x, y1, y2, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_line(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=lineRGBA(entity_destiny->graph, x1, y1, x2, y2, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_line_aa(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	char tmp;
	
	tmp=aalineRGBA(entity_destiny->graph, x1, y1, x2, y2, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}


unsigned char
ngl_geom_line_thick(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, Uint8 width, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=thickLineRGBA (entity_destiny->graph, x1, y1, x2, y2, width, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

// rectangle, boundedRectangle
unsigned char
ngl_geom_rectangle(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=rectangleRGBA(entity_destiny->graph, x1, y1, x2, y2, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_rectangle_rounded(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, Sint16 rad, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;
	
	tmp=roundedRectangleRGBA (entity_destiny->graph, x1, y1, x2, y2, rad, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}
	
	return 1; // Error
}

// box, roundedBox
unsigned char
ngl_geom_box(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=boxRGBA(entity_destiny->graph, x1, y1, x2, y2, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_roundedbox(ngl_entity *entity_destiny, unsigned int x1, unsigned int x2, unsigned int y1, unsigned int y2, unsigned int rad, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=roundedBoxRGBA(entity_destiny->graph, x1, y1, x2, y2, rad, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

// circle, aacircle, filledCircle
unsigned char
ngl_geom_circle(ngl_entity *entity_destiny, unsigned int x, unsigned int y, unsigned int rad, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=circleRGBA (entity_destiny->graph, x, y, rad, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_circle_aa(ngl_entity *entity_destiny, unsigned int x, unsigned int y, unsigned int rad, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=aacircleRGBA (entity_destiny->graph, x, y, rad, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_circle_filled(ngl_entity *entity_destiny, unsigned int x, unsigned int y, unsigned int rad, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=filledCircleRGBA(entity_destiny->graph, x, y, rad, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

// arcRGBA
unsigned char
ngl_geom_arc(ngl_entity *entity_destiny, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	char tmp;
	
	tmp=arcRGBA (entity_destiny->graph, x, y, rad, start, end, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

// ellipseRGBA, aaellipseRGBA, filledEllipseRGBA
unsigned char
ngl_geom_ellipse(ngl_entity *entity_destiny, unsigned int x, unsigned int y, unsigned int rx, unsigned char ry, Uint32 r, Uint32 g, Uint32 b, Uint32 a)
{
	char tmp;

	tmp=ellipseRGBA (entity_destiny->graph, x, y, rx, ry, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_ellipse_aa(ngl_entity *entity_destiny, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	char tmp;

	tmp=aaellipseRGBA(entity_destiny->graph, x, y, rx, ry, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_ellipse_filled(ngl_entity *entity_destiny, Sint16 x, Sint16 y, Sint16 rx, Sint16 ry, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	char tmp;

	tmp=filledEllipseRGBA(entity_destiny->graph, x, y, rx, ry, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

// pieRGBA, filledPieRGBA
unsigned char
ngl_geom_pie(ngl_entity *entity_destiny, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	char tmp;
	
	tmp=pieRGBA (entity_destiny->graph, x, y, rad, start, end, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_geom_pie_filled(ngl_entity *entity_destiny, Sint16 x, Sint16 y, Sint16 rad, Sint16 start, Sint16 end, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	char tmp;
	
	tmp=filledPieRGBA (entity_destiny->graph, x, y, rad, start, end, r, g, b, a);
	if (tmp==0) {
		return 0; // Ok
	}

	return 1; // Error
}

unsigned char
ngl_fill(ngl_entity *entity_id, Uint8 r, Uint8 g, Uint8 b)
{
	int tmp;
	Uint32 color;
	
	color=SDL_MapRGB(entity_id->graph->format, r, g, b);
	
	tmp=SDL_FillRect(entity_id->graph, NULL, color);
}
