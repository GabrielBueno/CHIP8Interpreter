#include "screen.h"

int main(int argc, char **argv) {
	Screen *s = init_screen("TESTE", 680, 480);
	int running = 1;

	while (running) {
		SDL_Event e;

		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				running = 0;
		}
	}

	close_screen(&s);

	return 0;
}