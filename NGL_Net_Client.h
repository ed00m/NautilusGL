int
ngl_net_open_localhost(char *Servicio)
{
	int tmp;
	
	tmp=Abre_Conexion_Unix (Servicio);
	
	return tmp;
}

int
ngl_net_open_network(char *Host_Servidor, char *Servicio)
{
	int tmp;
	
	tmp=Abre_Conexion_Inet (Host_Servidor, Servicio);
	
	return tmp;
}

int
ngl_net_close_client(int client_id)
{
	int tmp;
	
	tmp=close(client_id);
	
	if (tmp==0) {
		return 0;
	} else {
		return 1;
	}
}

