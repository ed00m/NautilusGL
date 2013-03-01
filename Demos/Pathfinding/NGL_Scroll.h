class ngl_scroll_h {
	public:
	ngl_scroll_h(void);
	~ngl_scroll_h(void);

	ngl_entity layer;
	ngl_entity layer_last;
	
	int init;
	int limit;
	unsigned char speed;
	unsigned char direction;

	void load(const char filename[200]);
	void unload(void);
	
	void set_x1(int new_x);
	void set_x2(int new_x);
	void set_y(int new_y);

	void paint(void);
	void move(void);
};

ngl_scroll_h::ngl_scroll_h(void)
{

}

ngl_scroll_h::~ngl_scroll_h(void)
{
	
}

void
ngl_scroll_h::load(const char filename[200])
{
	layer.load(filename);
	layer_last.load(filename);
}

void
ngl_scroll_h::unload(void)
{
	layer.unload();
	layer_last.unload();
}

void
ngl_scroll_h::set_x1(int new_x)
{
	layer.set_x(new_x);
}

void
ngl_scroll_h::set_x2(int new_x)
{
	layer_last.set_x(new_x);
}

void
ngl_scroll_h::set_y(int new_y)
{
	layer.set_y(new_y);
	layer_last.set_y(new_y);
}

void
ngl_scroll_h::paint(void)
{
	ngl_paint(&layer);
	ngl_paint(&layer_last);
}

void
ngl_scroll_h::move(void)
{
	switch (direction) {
		case 1:
			layer.x=layer.x+(speed+1);
			if (layer.x>limit) {
				layer.x=init;
			}
			
			layer_last.x=layer_last.x+(speed+1);
			if (layer_last.x>limit) {
				layer_last.x=init;
			}
		break;

		case 2:
			layer.x=layer.x-(speed+1);
			if (layer.x<init) {
				layer.x=limit;
			}

			layer_last.x=layer_last.x-(speed+1);
			if (layer_last.x<init) {
				layer_last.x=limit;
			}
		break;
	}
}

class ngl_scroll_v {
	public:
	ngl_scroll_v(void);
	~ngl_scroll_v(void);

	ngl_entity layer;
	ngl_entity layer_last;
	
	int init;
	int limit;
	unsigned char speed;
	unsigned char direction;

	void load(const char filename[200]);
	void unload(void);
	
	void set_y1(int new_y);
	void set_y2(int new_y);
	void set_x(int new_x);

	void paint(void);
	void move(void);
};

ngl_scroll_v::ngl_scroll_v(void)
{

}

ngl_scroll_v::~ngl_scroll_v(void)
{
	
}

void
ngl_scroll_v::load(const char filename[200])
{
	layer.load(filename);
	layer_last.load(filename);
}

void
ngl_scroll_v::unload(void)
{
	layer.unload();
	layer_last.unload();
}

void
ngl_scroll_v::set_y1(int new_y)
{
	layer.set_y(new_y);
}

void
ngl_scroll_v::set_y2(int new_y)
{
	layer_last.set_y(new_y);
}

void
ngl_scroll_v::set_x(int new_x)
{
	layer.set_x(new_x);
	layer_last.set_x(new_x);
}

void
ngl_scroll_v::paint(void)
{
	ngl_paint(&layer);
	ngl_paint(&layer_last);
}

void
ngl_scroll_v::move(void)
{
	switch (direction) {
		case 1:
			layer.y=layer.y-(speed+1);
			if (layer.y<init) {
				layer.y=limit;
			}
			
			layer_last.y=layer_last.y-(speed+1);
			if (layer_last.y<init) {
				layer_last.y=limit;
			}
		break;
		
		case 2:
			layer.y=layer.y+(speed+1);
			if (layer.y>limit) {
				layer.y=init;
			}

			layer_last.y=layer_last.y+(speed+1);
			if (layer_last.y>limit) {
				layer_last.y=init;
			}
		break;
	}
}
