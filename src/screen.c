#include "screen.h"

#include <stdio.h>

Screen* init_screen(const char *title, uint32_t width, uint32_t height) {
	Screen *screen = malloc(sizeof(Screen));

	if (screen == NULL)
		fprintf(stderr, "Error allocating memory to struct screen\n");

	screen->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (screen->window == NULL)
		fprintf(stderr, "Error creating window: %s\n", SDL_GetError());

	screen->renderer = SDL_CreateRenderer(screen->window, -1, SDL_RENDERER_ACCELERATED);
	if (screen->renderer == NULL)
		fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());

	screen->pixel_width  = width  / CHIP8EMU_SCREEN_WIDTH;
	screen->pixel_height = height / CHIP8EMU_SCREEN_HEIGHT;

	return screen;
}

void close_screen(Screen **screen) {
	if (screen == NULL || *screen == NULL)
		return;

	SDL_DestroyRenderer((*screen)->renderer);
	SDL_DestroyWindow((*screen)->window);

	free(*screen);
	*screen = NULL;
}

void load_byte(Screen *screen, uint8_t byte, size_t x, size_t y) {
	uint8_t offset_x = 0;

	for (uint8_t bit = 0x80; bit > 0x00; bit = bit >> 1) {
		screen->pixels[y][x + offset_x] = byte & bit;

		offset_x++;
	}
}

void load_bytes(Screen *screen, uint8_t *bytes, size_t bytes_size, size_t x, size_t y) {
	for (size_t byte_index = 0; byte_index < bytes_size; byte_index++) 
		load_byte(screen, bytes[byte_index], x, y + byte_index);
}
