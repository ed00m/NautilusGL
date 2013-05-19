int
ngl_net_read(int fd, char *Datos, int Longitud)
{
	int tmp;
	
	tmp=Lee_Socket (fd, Datos, Longitud);
	
	return tmp;
}

int
ngl_net_write(int fd, char *Datos, int Longitud)
{
	int tmp;
	
	tmp=Escribe_Socket (fd, Datos, Longitud);
	
	return tmp;
}
