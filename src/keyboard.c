#include "keyboard.h"

Keyboard* init_keyboard() {
	Keyboard *keyboard = malloc(sizeof(Keyboard));

	keyboard->keymap[0x01] = SDLK_1;
	keyboard->keymap[0x02] = SDLK_2;
	keyboard->keymap[0x03] = SDLK_3;
	keyboard->keymap[0x0C] = SDLK_4;
	keyboard->keymap[0x04] = SDLK_q;
	keyboard->keymap[0x05] = SDLK_w;
	keyboard->keymap[0x06] = SDLK_e;
	keyboard->keymap[0x0D] = SDLK_r;
	keyboard->keymap[0x07] = SDLK_a;
	keyboard->keymap[0x08] = SDLK_s;
	keyboard->keymap[0x09] = SDLK_d;
	keyboard->keymap[0x0E] = SDLK_f;
	keyboard->keymap[0x0A] = SDLK_z;
	keyboard->keymap[0x00] = SDLK_x;
	keyboard->keymap[0x0B] = SDLK_c;
	keyboard->keymap[0x0F] = SDLK_v;

	for (size_t key = 0; key < 16; key++)
		keyboard->keystate[key] = 0;

	return keyboard;
}

void close_keyboard(Keyboard **keyboard) {
	free(*keyboard);
	*keyboard = NULL;
}

void set_key_up(Keyboard *keyboard, SDL_Keycode key) {
	for (size_t k = 0; k < 16; k++) {
		if (keyboard->keymap[k] == key) {
			keyboard->keystate[k] = 0;
			break;
		}
	}
}

void set_key_down(Keyboard *keyboard, SDL_Keycode key) {
	for (size_t k = 0; k < 16; k++) {
		if (keyboard->keymap[k] == key) {
			keyboard->keystate[k] = 1;
			break;
		}
	}
}

SDL_Keycode wait_until_keypress(Keyboard *keyboard) {
	SDL_Event e;
	SDL_Keycode pressed_key;

	while (1) {
		while (SDL_PollEvent(&e)) {
			if (e.type != SDL_KEYDOWN)
				continue;

			pressed_key =  e.key.keysym.sym;

			for (size_t key = 0; key < 16; key++) {
				if (keyboard->keymap[key] == pressed_key)
					return key;
			}
		}
	}
}
