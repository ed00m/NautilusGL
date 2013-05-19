#define _esc 0
#define _1 2
#define _2 3
#define _3 4
#define _4 5
#define _5 6
#define _6 7
#define _7 8
#define _8 9
#define _9 10
#define _0 11
#define _minus 12
#define _plus 13
#define _f1 59
#define _f2 60
#define _f3 61
#define _f4 62
#define _f5 63
#define _f6 64
#define _f7 65
#define _f8 66
#define _f9 67
#define _f10 68
#define _f11 87
#define _f12 88
#define _prn_scr 55
#define _scroll_lock 70
#define _wave 41

#define _backspace 14
#define _tab 15
#define _q 16
#define _w 17
#define _e 18
#define _r 19
#define _t 20
#define _y 21
#define _u 22
#define _i 23
#define _o 24
#define _p 25
#define _l_brachet 26
#define _r_brachet 27
#define _enter 28

#define _caps_lock 58
#define _a 30
#define _s 31
#define _d 32
#define _f 33
#define _g 34
#define _h 35
#define _j 36
#define _k 37
#define	_l 38
#define _semicolon 39
#define _apostrophe 40
#define _backslash 43

#define _l_shift 42
#define _z 44
#define _x 45
#define _c 46
#define _v 47
#define _b 48
#define _n 49
#define _m 50
#define _comma 51
#define _point 52
#define _slash 53
#define _r_shift 54

#define _control 29
#define _alt 56
#define _space 57

#define _ins 82
#define _home 71
#define _pgup 73
#define _del 83
#define _end 79
#define _pgdn 81

#define _up 72
#define _down 80
#define _left 75
#define _right 77

unsigned char
ngl_key(unsigned int Tecla)
{
	Uint8 *keystate;
	SDL_Event event;

	SDL_PollEvent (&event);
	keystate=SDL_GetKeyState(NULL);
	
	switch (Tecla)
	{
		case 14:
			if (keystate[SDLK_BACKSPACE]) {
				return 1;
			}
		break;

		case 15:
			if (keystate[SDLK_TAB]) {
				return 1;
			}
		break;

		case 16:
			if (keystate[SDLK_q]) {
				return 1;
			}
		break;

		case 17:
			if (keystate[SDLK_w]) {
				return 1;
			}
		break;

		case 18:
			if (keystate[SDLK_e]) {
				return 1;
			}
		break;

		case 19:
			if (keystate[SDLK_r]) {
				return 1;
			}
		break;

		case 20:
			if (keystate[SDLK_t]) {
				return 1;
			}
		break;

		case 21:
			if (keystate[SDLK_y]) {
				return 1;
			}
		break;

		case 22:
			if (keystate[SDLK_u]) {
				return 1;
			}
		break;

		case 23:
			if (keystate[SDLK_i]) {
				return 1;
			}
		break;

		case 24:
			if (keystate[SDLK_o]) {
				return 1;
			}
		break;

		case 25:
			if (keystate[SDLK_p]) {
				return 1;
			}
		break;

		case 26:
			if (keystate[SDLK_LEFTBRACKET]) {
				return 1;
			}
		break;

		case 27:
			if (keystate[SDLK_RIGHTBRACKET]) {
				return 1;
			}
		break;

		case 28:
			if (keystate[SDLK_RETURN]) {
				return 1;
			}
		break;

		case 30:
			if (keystate[SDLK_a]) {
				return 1;
			}
		break;

		case 31:
			if (keystate[SDLK_s]) {
				return 1;
			}
		break;

		case 32:
			if (keystate[SDLK_d]) {
				return 1;
			}
		break;

		case 33:
			if (keystate[SDLK_f]) {
				return 1;
			}
		break;

		case 34:
			if (keystate[SDLK_g]) {
				return 1;
			}
		break;

		case 35:
			if (keystate[SDLK_h]) {
				return 1;
			}
		break;

		case 36:
			if (keystate[SDLK_j]) {
				return 1;
			}
		break;

		case 37:
			if (keystate[SDLK_k]) {
				return 1;
			}
		break;

		case 38:
			if (keystate[SDLK_l]) {
				return 1;
			}
		break;

		case 39:
			if (keystate[SDLK_SEMICOLON]) {
				return 1;
			}
		break;

		case 40:
			if (keystate[SDLK_BACKQUOTE]) {
				return 1;
			}
		break;

		case 43:

		break;

		case 42:
			if (keystate[SDLK_LSHIFT]) {
				return 1;
			}
		break;

		case 44:
			if (keystate[SDLK_z]) {
				return 1;
			}
		break;

		case 45:
			if (keystate[SDLK_x]) {
				return 1;
			}
		break;

		case 46:
			if (keystate[SDLK_c]) {
				return 1;
			}
		break;

		case 47:
			if (keystate[SDLK_v]) {
				return 1;
			}
		break;

		case 48:
			if (keystate[SDLK_b]) {
				return 1;
			}
		break;

		case 49:
			if (keystate[SDLK_n]) {
				return 1;
			}
		break;

		case 50:
			if (keystate[SDLK_m]) {
				return 1;
			}
		break;

		case 51:
			if (keystate[SDLK_COMMA]) {
				return 1;
			}
		break;

		case 52:
			if (keystate[SDLK_PERIOD]) {
				return 1;
			}
		break;

		case 53:
			if (keystate[SDLK_UNDERSCORE]) {
				return 1;
			}
		break;

		case 54:
			if (keystate[SDLK_RSHIFT]) {
				return 1;
			}
		break;

		case 29:
			if (keystate[SDLK_LCTRL]) {
				return 1;
			}
		break;

		case 56:
			if (keystate[SDLK_LALT]) {
				return 1;
			}
		break;

		case 57:
			if (keystate[SDLK_SPACE]) {
				return 1;
			}
		break;

		case 82:
			if (keystate[SDLK_INSERT]) {
				return 1;
			}
		break;

		case 71:
			if (keystate[SDLK_HOME]) {
				return 1;
			}
		break;

		case 73:
			if (keystate[SDLK_PAGEUP]) {
				return 1;
			}
		break;

		case 83:

		break;

		case 79:
			if (keystate[SDLK_END]) {
				return 1;
			}
		break;

		case 81:
			if (keystate[SDLK_PAGEDOWN]) {
				return 1;
			}
		break;

		case 72:
			if (keystate[SDLK_UP]) {
				return 1;
			}
		break;

		case 80:
			if (keystate[SDLK_DOWN]) {
				return 1;
			}
		break;

		case 75:
			if (keystate[SDLK_LEFT]) {
				return 1;
			}
		break;

		case 77:
			if (keystate[SDLK_RIGHT]) {
				return 1;
			}
		break;
	}

	return 0;
}
