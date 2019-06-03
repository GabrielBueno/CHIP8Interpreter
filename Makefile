CC        = gcc
SRC       = ./src/main.cpp
OUT       = ./bin/pong
FLAGS     = -Wall -Wextra
SDL_FLAGS = `sdl2-config --cflags --libs`

all:
	${CC} ${SRC} -o ${OUT} ${FLAGS} ${SDL_FLAGS}