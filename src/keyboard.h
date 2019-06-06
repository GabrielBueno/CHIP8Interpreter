#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SDL.h>

typedef struct keyboard {
	SDL_Keycode keymap[16];
	uint8_t keystate[16];
} Keyboard;

Keyboard* init_keyboard();
void close_keyboard(Keyboard **keyboard);

void set_key_up(Keyboard *keyboard, SDL_Keycode key);
void set_key_down(Keyboard *keyboard, SDL_Keycode key);

SDL_Keycode wait_until_keypress(Keyboard *keyboard);

#endif