#define m320x240 1
#define m640x480 2
#define m800x600 3
#define m1024x768 4

class ngl_screen_data {
	public:
	unsigned int width;
	unsigned int height;
	unsigned int bpp;

	SDL_Surface *graph;
	SDL_Rect region;

	void set_bpp(unsigned int new_bpp);
	unsigned char get_bpp(void);

	void set_main_text(const char title[200], const char icon[200]);
	void create_screen(unsigned char set_mode);

	void clear_screen(void);
	void frame(void);

	void quit(void);

	void set_region_x(unsigned int new_x);
	void set_region_y(unsigned int new_y);
	void set_region_w(unsigned int new_w);
	void set_region_h(unsigned int new_h);

	unsigned int get_region_x(void);
	unsigned int get_region_y(void);
	unsigned int get_region_w(void);
	unsigned int get_region_h(void);
} ngl_screen;

void 
ngl_screen_data::set_bpp(unsigned int new_bpp)
{
	switch (new_bpp) {
		case 16:
			bpp=new_bpp;
		break;

		case 24:
			bpp=new_bpp;
		break;

		case 32:
			bpp=new_bpp;
		break;
		
		default:
			bpp=16;
		break;
	}
}

unsigned char 
ngl_screen_data::get_bpp(void)
{
	return bpp;
}

void
ngl_screen_data::set_main_text(const char title[200], const char icon[50])
{
	SDL_WM_SetCaption(title, icon);
}

void
ngl_screen_data::create_screen(unsigned char set_mode)
{
	char init;

	switch (set_mode) {
		case 1:
			width=320;
			height=240;
		break;

		case 2:
			width=640;
			height=480;
		break;

		case 3:
			width=800;
			height=600;
		break;

		case 4:
			width=1024;
			height=768;
		break;
	}

	init=SDL_Init(SDL_INIT_EVERYTHING);
	if (init==0) {
		graph=SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE );
		if (graph==NULL) {
			printf("\ncreate_screen: error creando la ventana");
			exit(1);
		}
	}
}

void
ngl_screen_data::clear_screen(void)
{
	unsigned int tmp;

	tmp=SDL_FillRect(SDL_GetVideoSurface(), NULL, 0);
	if (tmp==-1) {
		printf("\nclear_screen: error, screen no borrada"); }
}

void
ngl_screen_data::frame(void)
{
	unsigned int tmp;

	tmp=SDL_Flip(ngl_screen.graph);
	if (tmp<0) {
		printf("\nerror en SDL_Flip"); }
}

void
ngl_screen_data::quit(void)
{
	SDL_Quit();
}

void
ngl_screen_data::set_region_x(unsigned int new_x)
{
	region.x=new_x;
}

void
ngl_screen_data::set_region_y(unsigned int new_y)
{
	region.y=new_y;
}

void
ngl_screen_data::set_region_w(unsigned int new_w)
{
	region.w=new_w;
}

void
ngl_screen_data::set_region_h(unsigned int new_h)
{
	region.h=new_h;
}

unsigned int
ngl_screen_data::get_region_x(void)
{
	return region.x;
}

unsigned int
ngl_screen_data::get_region_y(void)
{
	return region.y;
}

unsigned int
ngl_screen_data::get_region_w(void)
{
	return region.w;
}

unsigned int
ngl_screen_data::get_region_h(void)
{
	return region.h;
}

void ngl_screen_set_bpp(unsigned int new_bpp);
unsigned char ngl_screen_get_bpp(void);
void ngl_screen_set_main(const char title[200], const char icon[50]);
void ngl_create_screen(unsigned char set_mode);
void ngl_clear_screen(void);
void ngl_frame(void);
void ngl_quit(void);
void ngl_screen_set_region_x(unsigned int new_x);
void ngl_screen_set_region_y(unsigned int new_y);
void ngl_screen_set_region_w(unsigned int new_w);
void ngl_screen_set_region_h(unsigned int new_h);
unsigned int ngl_screen_get_region_x(void);
unsigned int ngl_screen_get_region_y(void);
unsigned int ngl_screen_get_region_w(void);
unsigned int ngl_screen_get_region_h(void);

void
ngl_screen_set_bpp(unsigned int new_bpp)
{
	ngl_screen.set_bpp(new_bpp);
}

unsigned char
ngl_screen_get_bpp(void)
{
	unsigned char tmp;

	tmp=ngl_screen.get_bpp();

	return tmp;
}

void
ngl_screen_set_main(const char title[200], const char icon[50])
{
	ngl_screen.set_main_text(title,icon);
}

void
ngl_create_screen(unsigned char set_mode)
{
	ngl_screen.create_screen(set_mode);
}

void
ngl_clear_screen(void)
{
	ngl_screen.clear_screen();
}

void
ngl_frame(void)
{
	ngl_screen.frame();
}

void
ngl_quit(void)
{
	ngl_screen.quit();
}

void
ngl_screen_set_region_x(unsigned int new_x)
{
	ngl_screen.set_region_x(new_x);
}

void
ngl_screen_set_region_y(unsigned int new_y)
{
	ngl_screen.set_region_y(new_y);
}

void
ngl_screen_set_region_w(unsigned int new_w)
{
	ngl_screen.set_region_w(new_w);
}

void
ngl_screen_set_region_h(unsigned int new_h)
{
	ngl_screen.set_region_h(new_h);
}

unsigned int
ngl_screen_get_region_x(void)
{
	unsigned int tmp;

	tmp=ngl_screen.get_region_x();

	return tmp;
}

unsigned int
ngl_screen_get_region_y(void)
{
	unsigned int tmp;

	tmp=ngl_screen.get_region_y();

	return tmp;
}

unsigned int
ngl_screen_get_region_w(void)
{
	unsigned int tmp;

	tmp=ngl_screen.get_region_w();

	return tmp;
}

unsigned int
ngl_screen_get_region_h(void)
{
	unsigned int tmp;

	tmp=ngl_screen.get_region_h();

	return tmp;
}
