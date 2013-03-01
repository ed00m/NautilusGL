unsigned char
ngl_init_ttf(void)
{
	unsigned int init_ttf;

	init_ttf=TTF_Init();
	if (init_ttf<0) {
		return 1; // Error de  SDL_ttf, no pudo iniciarse
	}

	return 0;
}

void
ngl_ttf_quit(void)
{
	TTF_Quit();
}

ngl_ttf_font *
ngl_load_font(const char filename[50], int font_size)
{
	ngl_ttf_font *ttf_font_id;

	ttf_font_id=TTF_OpenFont(filename, font_size);
	if (ttf_font_id==NULL) {
		return NULL; // Error, fuente no cargada
	}

	return ttf_font_id;
}

void
ngl_unload_font(ngl_ttf_font *ttf_font_id)
{
	TTF_CloseFont(ttf_font_id);
}

void
ngl_font_set_color(ngl_color *color_id, unsigned char red, unsigned char green, unsigned char blue)
{
	color_id->r=red;
	color_id->g=green;
	color_id->b=blue;
}

unsigned char
ngl_font_text_solid_basic(ngl_entity *entity_id, ngl_ttf_font *ttf_font_id, const char message[255], ngl_color color_id)
{
	entity_id->graph=TTF_RenderText_Solid(ttf_font_id, message, color_id);
	if (!entity_id->graph) {
		return 1; // Error, error, entidad y texto no vinculados
	}

	return 0;
}

unsigned char
ngl_font_text_solid_utf(ngl_entity *entity_id, ngl_ttf_font *ttf_font_id, const char message[255], ngl_color color_id)
{
	entity_id->graph=TTF_RenderUTF8_Solid(ttf_font_id, message, color_id);
	if (entity_id->graph==NULL) {
		return 1; // Error, error, entidad y texto no vinculados
	}

	return 0;
}

unsigned char
ngl_font_text_shaded_basic(ngl_entity *entity_id, ngl_ttf_font *ttf_font_id, const char message[255], ngl_color color_id1, ngl_color color_id2)
{
	entity_id->graph=TTF_RenderText_Shaded(ttf_font_id, message, color_id1, color_id2);
	if (entity_id->graph==NULL) {
		return 1; // Error, error, entidad y texto no vinculados
	}

	return 0;
}

unsigned char
ngl_font_text_shaded_utf(ngl_entity *entity_id, ngl_ttf_font *ttf_font_id, const char message[255], ngl_color color_id1, ngl_color color_id2)
{
	entity_id->graph=TTF_RenderUTF8_Shaded(ttf_font_id, message, color_id1, color_id2);
	if (entity_id->graph==NULL) {
		return 1; // Error, error, entidad y texto no vinculados
	}

	return 0;
}

unsigned char
ngl_font_text_blended_basic(ngl_entity *entity_id, ngl_ttf_font *ttf_font_id, const char message[255], ngl_color color_id1)
{
	entity_id->graph=TTF_RenderText_Blended(ttf_font_id, message, color_id1);
	if (entity_id->graph==NULL) {
		return 1; // Error, error, entidad y texto no vinculados
	}

	return 0;
}

unsigned char
ngl_font_text_blended_utf(ngl_entity *entity_id, ngl_ttf_font *ttf_font_id, const char message[255], ngl_color color_id1)
{
	entity_id->graph=TTF_RenderUTF8_Blended(ttf_font_id, message, color_id1);
	if (entity_id->graph==NULL) {
		return 1; // Error, error, entidad y texto no vinculados
	}

	return 0;
}
