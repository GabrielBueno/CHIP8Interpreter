CC        = gcc
OUT       = ./bin/chip8emu
SRC       = ./src/screen.c ./src/keyboard.c ./src/cpu.c ./src/machine.c ./src/instructions.c ./src/main.c 
FLAGS     = -Wall -Wextra -Wno-unused-variable -Wno-unused-parameter
SDL_FLAGS = `sdl2-config --cflags --libs`

all:
	${CC} ${SRC} -o ${OUT} ${FLAGS} ${SDL_FLAGS}