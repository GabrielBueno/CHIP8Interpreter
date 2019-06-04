CC        = gcc
OUT       = ./bin/chip8emu
SRC       = ./src/screen.c ./src/keyboard.c ./src/main.c 
FLAGS     = -Wall -Wextra
SDL_FLAGS = `sdl2-config --cflags --libs`

all:
	${CC} ${SRC} -o ${OUT} ${FLAGS} ${SDL_FLAGS}