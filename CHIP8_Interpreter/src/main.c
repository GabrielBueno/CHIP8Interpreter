#include <stdio.h>
#include <stdlib.h>

#include "machine.h"

#define DEBUG_OPCODE

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("chip8emu [path to rom file]\n");
		exit(1);
	}

	Machine *machine = initialize_machine();

	load_rom(machine, argv[1]);
	begin_execution(machine);

	shutdown_machine(&machine);

	return 0;
}