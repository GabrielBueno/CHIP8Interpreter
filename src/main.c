#include "screen.h"
#include "keyboard.h"

int main(int argc, char **argv) {
	SDL_Init(SDL_INIT_VIDEO);

	Screen *s = init_screen("TESTE", 680, 480);
	Keyboard *k = init_keyboard();
	int running = 1;

	screen_load_byte(s, 0xF5, 26, 24);
	screen_load_byte(s, 0x55, 26, 25);
	screen_load_byte(s, 0xAA, 26, 26);

	while (running) {
		SDL_Event e;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				running = 0;

			if (e.type == SDL_KEYDOWN) 
				set_key_down(k, e.key.keysym.sym);

			if (e.type == SDL_KEYUP)
				set_key_up(k, e.key.keysym.sym);
		}

		fprintf(stdout, "%d\n", k->keystate[0x0A]);
		screen_draw(s);
	}

	close_screen(&s);

	SDL_Quit();

	return 0;
}