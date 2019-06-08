@Echo off
SETLOCAL

SET CC=gcc
SET IPATH=./include/SDL2
SET LPATH=./lib
SET SRC=./src/screen.c ./src/keyboard.c ./src/cpu.c ./src/machine.c ./src/instructions.c ./src/main.c
SET OUT=./bin/mingw/chip8.exe
SET FLAGS=-Wall -Wextra -Wno-unused-variable -Wno-unused-parameter
SET LINKER_FLAGS=-lmingw32 -lSDL2main -lSDL2

@Echo on

%CC% -I%IPATH% -L%LPATH% -o %OUT% %SRC% %FLAGS% %LINKER_FLAGS%

@Echo off

ENDLOCAL