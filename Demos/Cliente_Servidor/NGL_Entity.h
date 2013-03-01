class ngl_entity {
	public:
	ngl_entity(void);
	~ngl_entity(void);

	SDL_Surface *graph;
	SDL_Rect region;

	int x;
	int y;
	unsigned char signal;
	unsigned char mem_signal;
	float angle;
	unsigned char mode_paint; // Control de region
	unsigned char alpha;

	// Grafico
	unsigned char load(const char filename[200]);
	void unload(void);
	
	// Coordenadas X e Y, y signal
	unsigned char set_x(int new_x);
	unsigned char set_y(int new_y);
	unsigned char set_xy(int new_x, int new_y);
	unsigned char set_signal(unsigned char new_signal);
	unsigned char get_signal(void);

	// Region
	void set_region_x(unsigned int new_x);
	void set_region_y(unsigned int new_y);
	void set_region_w(unsigned int new_w);
	void set_region_h(unsigned int new_h);
	unsigned int get_region_x(void);
	unsigned int get_region_y(void);
	unsigned int get_region_w(void);
	unsigned int get_region_h(void);
	
	// Icono (ventana principal)
	void set_main_icon(void);
};

ngl_entity::ngl_entity(void)
{
	x=0;
	y=0;
	signal=0;
	angle=0;
	mode_paint=2;
	alpha=0;
}

ngl_entity::~ngl_entity(void)
{

}

unsigned char
ngl_entity::load(const char filename[200])
{
	graph=IMG_Load(filename);
	if (!graph) {
		return 1; // Error, grafico no cargado
	}

	return 0; // Ok
}

void
ngl_entity::unload(void)
{
	SDL_FreeSurface(graph);
}

unsigned char
ngl_entity::set_x(int new_x)
{
	switch (signal) {
		case 0: // ngl_normal
			x=new_x;
			return 0; // Ok
		break;

		case 1: // ngl_kill
			return 1; // Error, entidad eliminada
		break;

		case 2: // ngl_sleep
			x=new_x;
			return 0; // Ok
		break;

		case 3: // ngl_freeze
			return 2; // Error, entidad congelada
		break;
	}
}

unsigned char
ngl_entity::set_y(int new_y)
{
	switch (signal) {
		case 0: // ngl_normal
			y=new_y;
			return 0; // Ok
		break;

		case 1: // ngl_kill
			return 1; // Error, entidad eliminada
		break;

		case 2: // ngl_sleep
			y=new_y;
			return 0; // Ok
		break;

		case 3: // ngl_freeze
			return 2; // Error, entidad congelada
		break;
	}
}

unsigned char
ngl_entity::set_xy(int new_x, int new_y)
{
	switch (signal) {
		case 0: // ngl_normal
			x=new_x;
			y=new_y;
			return 0; // Ok
		break;

		case 1: // ngl_kill
			return 1; // Error, entidad eliminada
		break;

		case 2: // ngl_sleep
			x=new_x;
			y=new_y;
			return 0; // Ok
		break;

		case 3: // ngl_freeze
			return 2; // Error, entidad congelada
		break;
	}
}

unsigned char
ngl_entity::set_signal(unsigned char new_signal)
{
	switch (signal) {
		case 0: // ngl_normal
			signal=new_signal;
			return 0; // Ok
		break;

		case 1: // ngl_kill
			return 1; // Error, entidad eliminada
		break;

		case 2: // ngl_sleep
			if (new_signal==4) { // Wake up
				signal=new_signal;
				return 0; // Ok
			}
		break;

		case 3: // ngl_freeze
			if (new_signal==4) { // Wake up
				signal=new_signal;
				return 0; // Ok
			}
		break;
	}
}

unsigned char
ngl_entity::get_signal(void)
{
	return signal;
}

void 
ngl_entity::set_region_x(unsigned int region_x)
{
	region.x=region_x;
}

void 
ngl_entity::set_region_y(unsigned int region_y)
{
	region.y=region_y;
}

void 
ngl_entity::set_region_w(unsigned int region_w)
{
	region.w=region_w;
}

void 
ngl_entity::set_region_h(unsigned int region_h)
{
	region.h=region_h;
}

unsigned int
ngl_entity::get_region_x(void)
{
	return region.x;
}

unsigned int
ngl_entity::get_region_y(void)
{
	return region.y;
}

unsigned int
ngl_entity::get_region_w(void)
{
	return region.w;
}

unsigned int
ngl_entity::get_region_h(void)
{
	return region.h;
}

void
ngl_entity::set_main_icon(void)
{
	SDL_WM_SetIcon(graph, NULL);
}
