#include "screen.h"

#include <stdio.h>
#include <stdlib.h>

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

uint8_t screen_load_byte(Screen *screen, uint8_t byte, size_t x, size_t y) {
	uint8_t bit_erased = 0;
	uint8_t offset_x   = 0;

	for (uint8_t bit = 0x80; bit > 0x00; bit = bit >> 1) {
		uint8_t dest_x = (x + offset_x) % CHIP8EMU_SCREEN_WIDTH;
		uint8_t dest_y = y % CHIP8EMU_SCREEN_HEIGHT;

		uint8_t prev_pixel = screen->pixels[dest_y][dest_x];
		uint8_t next_pixel = byte & bit;

		uint8_t xor_result = (!prev_pixel && next_pixel) || (prev_pixel && !next_pixel);

		screen->pixels[dest_y][dest_x] = xor_result;

		if (prev_pixel && !xor_result)
			bit_erased = 1;

		offset_x++;
	}

	return bit_erased;
}

void screen_load_bytes(Screen *screen, uint8_t *bytes, size_t bytes_size, size_t x, size_t y) {
	for (size_t byte_index = 0; byte_index < bytes_size; byte_index++) 
		screen_load_byte(screen, bytes[byte_index], x, y + byte_index);
}

void clear_screen(Screen *screen) {
	for (size_t y = 0; y < CHIP8EMU_SCREEN_HEIGHT; y++) {
		for (size_t x = 0; x < CHIP8EMU_SCREEN_WIDTH; x++) {
			screen->pixels[y][x] = 0x00;
		}
	}
}

void screen_draw(Screen *screen) {
	SDL_Rect pixel_on_buffer[CHIP8EMU_SCREEN_WIDTH * CHIP8EMU_SCREEN_HEIGHT];
	size_t pixel_on_buffer_count = 0;

	SDL_Rect pixel_off_buffer[CHIP8EMU_SCREEN_WIDTH * CHIP8EMU_SCREEN_HEIGHT];
	size_t pixel_off_buffer_count = 0;

	for (size_t y = 0; y < CHIP8EMU_SCREEN_HEIGHT; y++) {
		for (size_t x = 0; x < CHIP8EMU_SCREEN_WIDTH; x++) {
			SDL_Rect pixel;

			pixel.x = x * screen->pixel_width;
			pixel.y = y * screen->pixel_height;
			pixel.w = screen->pixel_width;
			pixel.h = screen->pixel_height;

			if (screen->pixels[y][x]) {
				pixel_on_buffer[pixel_on_buffer_count] = pixel;
				pixel_on_buffer_count += 1;
			} else {
				pixel_off_buffer[pixel_off_buffer_count] = pixel;
				pixel_off_buffer_count += 1;
			}
		}
	}

	SDL_SetRenderDrawColor(screen->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRects(screen->renderer, pixel_on_buffer, pixel_on_buffer_count);

	SDL_SetRenderDrawColor(screen->renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderFillRects(screen->renderer, pixel_off_buffer, pixel_off_buffer_count);

	SDL_RenderPresent(screen->renderer);
}
