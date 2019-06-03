CC        = gcc
OUT       = ./bin/chip8emu
SRC       = ./src/main.c ./src/screen.c
FLAGS     = -Wall -Wextra
SDL_FLAGS = `sdl2-config --cflags --libs`

all:
	${CC} ${SRC} -o ${OUT} ${FLAGS} ${SDL_FLAGS}