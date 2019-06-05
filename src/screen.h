#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
#include <stdint.h>

#define CHIP8EMU_SCREEN_WIDTH  64
#define CHIP8EMU_SCREEN_HEIGHT 32

typedef struct screen {
	SDL_Window   *window;
	SDL_Renderer *renderer;

	uint8_t  pixels[CHIP8EMU_SCREEN_HEIGHT][CHIP8EMU_SCREEN_WIDTH];
	uint32_t pixel_width;
	uint32_t pixel_height;
} Screen;

Screen* init_screen(const char *title, uint32_t width, uint32_t height);
void close_screen(Screen **screen);

void screen_load_byte(Screen *screen, uint8_t byte, size_t x, size_t y);
void screen_load_bytes(Screen *screen, uint8_t *bytes, size_t bytes_size, size_t x, size_t y);

void screen_draw(Screen *screen);

#endif
