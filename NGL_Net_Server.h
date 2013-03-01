int
ngl_net_open_server(char *Servicio)
{
	int tmp;
	
	tmp=Abre_Socket_Unix(Servicio);
	
	return tmp;
}

int
ngl_net_open_net_server(char *Servicio)
{
	int tmp;
	
	tmp=Abre_Socket_Inet (Servicio);
	
	return tmp;
	
}

int
ngl_net_close_server(int server_id)
{
	int tmp;
	
	tmp=close(server_id);
	
	if (tmp==0) {
		return 0;
	} else {
		return 1;
	}
}

int
ngl_net_accept_client(int Descriptor)
{
	int tmp;
	
	tmp=Acepta_Conexion_Cliente(Descriptor);
	
	return tmp;
}
