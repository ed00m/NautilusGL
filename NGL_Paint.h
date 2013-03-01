unsigned char
ngl_paint(ngl_entity *entity_id)
{
	int real_x, real_y;
	
	if (entity_id->graph==NULL) {
		return 1; // Error, entidad sin grafico
	}

	switch (entity_id->signal) {
		case 1: // Kill
			entity_id->unload();
			return 2;
		break;

		case 2: // Sleep, no se pinta
			return 3;
		break;
		
		case 4: // Wakeup
			entity_id->signal=0;
		break;
	}

	switch (entity_id->mode_paint) {
		case 1: // Sin zonas
			SDL_BlitSurface(entity_id->graph, NULL, ngl_screen.graph, NULL);
		break;

		case 2: // Zona en la entidad destino (screen)
			real_x=entity_id->x-(entity_id->graph->w/2);
			real_y=entity_id->y-(entity_id->graph->h/2);
			ngl_screen.region.x=real_x;
			ngl_screen.region.y=real_y;
			SDL_BlitSurface(entity_id->graph, NULL, ngl_screen.graph, &ngl_screen.region);
		break;

		case 3: // Zona en la entidad origen (surface)
			SDL_BlitSurface(entity_id->graph, &entity_id->region, ngl_screen.graph, NULL);
		break;

		case 4: // Zona en ambas entidades
			SDL_BlitSurface(entity_id->graph, &entity_id->region, ngl_screen.graph, &ngl_screen.region);
		break;
	}
	
	return 0;
}

void
ngl_paint_region(ngl_entity *entity_origin, ngl_entity *entity_destiny, unsigned char mode)
{
	switch (mode) {
		case 1: // Sin zonas
			SDL_BlitSurface(entity_origin->graph, NULL, entity_destiny->graph, NULL);
		break;

		case 2: // Zona en destino
			SDL_BlitSurface(entity_origin->graph, NULL, entity_destiny->graph, &entity_destiny->region);
		break;

		case 3: // Zona en origen
			SDL_BlitSurface(entity_origin->graph, &entity_origin->region, entity_destiny->graph, NULL);
		break;

		case 4: // Zona en ambas entidades
			SDL_BlitSurface(entity_origin->graph, &entity_origin->region, entity_destiny->graph, &entity_destiny->region);
		break;
	}
}

void
ngl_paint_entity(ngl_entity *entity_origin, ngl_entity *entity_destiny)
{
	int real_x, real_y;

	real_x=entity_origin->x-(entity_origin->graph->w/2);
	real_y=entity_origin->y-(entity_origin->graph->h/2);
	entity_destiny->region.x=real_x;
	entity_destiny->region.y=real_y;
	SDL_BlitSurface(entity_origin->graph, NULL, entity_destiny->graph, &entity_destiny->region);
}
