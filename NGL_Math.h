unsigned char
ngl_collision(ngl_entity *entity_id1, ngl_entity *entity_id2)
{
	double left1, left2;
	double right1, right2;
	double top1, top2;
	double bottom1, bottom2;

	if (entity_id1->signal==0) {
		if (entity_id2->signal==0) {
			left1=entity_id1->x+(entity_id1->graph->w*0.1);
			left2=entity_id2->x+(entity_id2->graph->w*0.1);

			top1=entity_id1->y+(entity_id1->graph->h*0.1);
			top2=entity_id2->y+(entity_id2->graph->h*0.1);

			right1=entity_id1->x+(entity_id1->graph->w*0.9);
			right2=entity_id2->x+(entity_id2->graph->w*0.9);

			bottom1=entity_id1->y+(entity_id1->graph->h*0.9);
			bottom2=entity_id2->y+(entity_id2->graph->h*0.9);

			if (bottom1<top2) { return 0; }
			if (top1>bottom2) { return 0; }
			if (right1<left2) { return 0; }
			if (left1>right2) { return 0; }

		return 1; // Colision detectada
		}
	}

	return 0;
}

float
ngl_get_angle(ngl_entity *entity_id1, ngl_entity *entity_id2)
{
	double PI_detail;
	float x1, y1, x2, y2;
	float angulo;

	angulo=0;
	
	if (entity_id1->signal==0) {
		if (entity_id1->signal==0) {
			PI_detail=3.141592;
			x1=entity_id1->x;
			y1=entity_id1->y;
			x2=entity_id2->x;
			y2=entity_id2->y;

			angulo=atan2((x2-x1),(y2-y1))*180/PI_detail;
			angulo=angulo-90;

			// Si el angulo resultante es negativo, se le suma un giro positivo completo (360º)
			if (angulo<0) { angulo += 360; }
			return angulo;
		}
	}
	
	return 400;
}

unsigned int
ngl_get_dist(ngl_entity *entity_id1, ngl_entity *entity_id2)
{
	unsigned int Xdif, Ydif;
	
	if (entity_id1->signal==0) {
		if (entity_id2->signal==0) {
			Xdif=abs(entity_id1->x-entity_id2->x);
			Ydif=abs(entity_id1->y-entity_id2->y);

			if (Xdif>Ydif) {
				return Xdif;
			}

			if (Ydif>Xdif) {
				return Ydif;
			}

			if (Xdif==Ydif) {
				return Xdif;
			}
		}
	}
}

void
ngl_advance(ngl_entity *entity_id, unsigned int distance)
{
	float radian;
	unsigned char tmp;
	
	int Dx, Dy;

	tmp=0;
	// Angulos perpendiculares
	if (entity_id->signal==0) {
		switch ((int) entity_id->angle)
		{
			case 0:
				entity_id->x=entity_id->x+distance;
				tmp=1;
			break;

			case 90:
				entity_id->y=entity_id->y-distance;
				tmp=1;
			break;

			case 180:
				entity_id->x=entity_id->x-distance;
				tmp=1;
			break;

			case 270:
				entity_id->y=entity_id->y+distance;
				tmp=1;
			break;

			// Angulos negativos
			case -270:
				entity_id->y=entity_id->y+distance;
				tmp=1;
			break;

			case -180:
				entity_id->x=entity_id->x-distance;
				tmp=1;
			break;

			case -90:
				entity_id->y=entity_id->y-distance;
				tmp=1;
			break;
		}
		
		// Resto de casos
		if (tmp==0) {
			radian = (float)(3.1415926535897931/180)*entity_id->angle;
			Dx=distance*cos(radian);
			Dy=distance*sin(radian);
			
			entity_id->x=entity_id->x+Dx;
			entity_id->y=entity_id->y-Dy;
		}
	}
}

void
ngl_rand_seed(void)
{
	srand(time(NULL));
}

unsigned int
ngl_rand (unsigned int min_value, unsigned int max_value)
{
	unsigned int tmp;

	if (min_value<max_value) {
		tmp=(rand()%max_value)+ min_value;

		return tmp;
	}

	return 0;
}
