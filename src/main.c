#include "screen.h"

int main(int argc, char **argv) {
	Screen *s = init_screen("TESTE", 680, 480);
	int running = 1;

	screen_load_byte(s, 0xF5, 26, 24);
	screen_load_byte(s, 0x55, 26, 25);
	screen_load_byte(s, 0xAA, 26, 26);

	while (running) {
		SDL_Event e;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				running = 0;
		}

		screen_draw(s);
	}

	close_screen(&s);

	return 0;
}