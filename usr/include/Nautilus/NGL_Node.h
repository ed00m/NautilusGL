#define NGL_MAX_NODE 100

#define ngl_normal 0
#define ngl_kill 1
#define ngl_sleep 2
#define ngl_freeze 3
#define ngl_wakeup 4

class ngl_node
{
	public:
	ngl_node();
	~ngl_node();

	ngl_entity *list[NGL_MAX_NODE];
	unsigned int num;
	unsigned char signal;

	unsigned int add(ngl_entity *entity_id);
	unsigned int del();
	void set_signal(unsigned char signal_id);
	unsigned char get_signal();
	unsigned int count();
};

ngl_node::ngl_node()
{
	num=0;
	signal=0;
}

ngl_node::~ngl_node()
{

}

unsigned int
ngl_node::add(ngl_entity *entity_id)
{
	if (num<=NGL_MAX_NODE) {
		list[num]=entity_id;
		num++;

		return num;
	}

	return 200;
}

unsigned int
ngl_node::del()
{
	if (num>0) {
		num--;

		return num;
	}

	return 0;
}

void
ngl_node::set_signal(unsigned char signal_id)
{
	unsigned int init, end;

	init=0;
	end=num;

	while (init<end) {
		list[init]->signal=signal_id;
		init++;
	}
}

unsigned char
ngl_node::get_signal()
{
	return signal;
}

unsigned int
ngl_node::count()
{
	return num;
}
