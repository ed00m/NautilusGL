#define NGL_PLANE_MAX_ENTITY 500

class ngl_plane {
	public:

	ngl_plane(void);
	~ngl_plane(void);

	ngl_entity *list[NGL_PLANE_MAX_ENTITY];
	unsigned int num;

	unsigned char add(ngl_entity *entity_id);
	unsigned char del(void);
	unsigned int get_number(void);
	void paint(void);
	void paint_one(unsigned int selected);
	void paint_group(unsigned int init, unsigned int end);
	void swap(unsigned int init, unsigned int end);
};

ngl_plane::ngl_plane(void)
{
	num=0;
}

ngl_plane::~ngl_plane(void)
{

}

unsigned char
ngl_plane::add(ngl_entity *entity_id)
{
	if (num<NGL_PLANE_MAX_ENTITY) {
		list[num]=entity_id;
		num++;
		
		return 0;
	}
	
	return 1;
}

unsigned char
ngl_plane::del(void)
{
	if (num>NGL_PLANE_MAX_ENTITY) {
		num--;
		
		return 0;
	}
	
	return 1;
}

unsigned int
ngl_plane::get_number(void)
{
	return num;
}

void
ngl_plane::paint(void)
{
	unsigned int init, end;

	init=0;
	end=num;
	
	while (init<end) {
		ngl_paint(list[init]);
		init++;
	}
}

void
ngl_plane::paint_one(unsigned int selected)
{
	ngl_paint(list[selected]);
}

void
ngl_plane::paint_group(unsigned int init, unsigned int end)
{
	while (init<=end) {
		ngl_paint(list[init]);
		init++;
	}
}

void
ngl_plane::swap(unsigned int init, unsigned int end)
{
	ngl_entity *entity_id1;
	ngl_entity *entity_id2;
	
	entity_id1=list[init];
	entity_id2=list[end];
	
	list[init]=entity_id2;
	list[end]=entity_id1;
}
