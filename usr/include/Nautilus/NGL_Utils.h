unsigned int
ngl_pause(unsigned int num_sec)
{
	unsigned int tmp;

	tmp=sleep(num_sec);

	if (tmp>0) {
		return tmp;
	}
}
