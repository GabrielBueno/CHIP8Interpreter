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

	for (size_t y = 0; y < CHIP8EMU_SCREEN_HEIGHT; y++) {
		for (size_t x = 0; x < CHIP8EMU_SCREEN_WIDTH; x++) {
			screen->pixels[y][x] = 0x00;
		}
	}

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

void screen_load_byte(Screen *screen, uint8_t byte, size_t x, size_t y) {
	uint8_t offset_x = 0;

	for (uint8_t bit = 0x80; bit > 0x00; bit = bit >> 1) {
		screen->pixels[y][x + offset_x] = byte & bit;

		// fprintf(stdout, "%x & %x (x: %d y: %d)\n", byte, bit, x + offset_x, y);

		offset_x++;
	}
}

void screen_load_bytes(Screen *screen, uint8_t *bytes, size_t bytes_size, size_t x, size_t y) {
	for (size_t byte_index = 0; byte_index < bytes_size; byte_index++) 
		screen_load_byte(screen, bytes[byte_index], x, y + byte_index);
}

void screen_draw(Screen *screen) {
	SDL_SetRenderDrawColor(screen->renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(screen->renderer);

	SDL_Rect rect_buffer[CHIP8EMU_SCREEN_WIDTH * CHIP8EMU_SCREEN_HEIGHT];
	size_t rect_buffer_count = 0;

	for (size_t y = 0; y < CHIP8EMU_SCREEN_HEIGHT; y++) {
		for (size_t x = 0; x < CHIP8EMU_SCREEN_WIDTH; x++) {
			if (!screen->pixels[y][x])
				continue;

			rect_buffer[rect_buffer_count].x = x * screen->pixel_width;
			rect_buffer[rect_buffer_count].y = y * screen->pixel_height;
			rect_buffer[rect_buffer_count].w = screen->pixel_width;
			rect_buffer[rect_buffer_count].h = screen->pixel_height;

			// fprintf(stdout, "x: %d y: %d w: %d h: %d\n", rect_buffer[rect_buffer_count].x, rect_buffer[rect_buffer_count].y, rect_buffer[rect_buffer_count].w, rect_buffer[rect_buffer_count].h);

			rect_buffer_count++;
		}
	}

	SDL_SetRenderDrawColor(screen->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRects(screen->renderer, rect_buffer, rect_buffer_count);

	SDL_RenderPresent(screen->renderer);
}
