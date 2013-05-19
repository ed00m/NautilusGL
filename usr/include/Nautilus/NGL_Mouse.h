SDL_Event ngl_event_mouse;

unsigned int
ngl_mouse_get_x(void)
{
	if (SDL_WaitEvent (&ngl_event_mouse)) {
		switch (ngl_event_mouse.type) {
			case SDL_MOUSEMOTION:
				return ngl_event_mouse.motion.x;
			break;
		}
	}
}

unsigned int
ngl_mouse_get_y(void)
{
	if (SDL_WaitEvent (&ngl_event_mouse)) {
		switch (ngl_event_mouse.type) {
			case SDL_MOUSEMOTION:
				return ngl_event_mouse.motion.y;
			break;
		}
	}
}

unsigned int
ngl_mouse_get_button_state(void)
{
	if (SDL_WaitEvent (&ngl_event_mouse)) {
		switch (ngl_event_mouse.type) {
			case SDL_MOUSEBUTTONDOWN:
				switch (ngl_event_mouse.button.button) {
					case SDL_BUTTON_LEFT:
						return 1;
					break;

					case SDL_BUTTON_RIGHT:
						return 2;
					break;
					}
			break;
		}
	}

	return 0;
}
