#include "machine.h"

int main(int argc, char **argv) {
	Machine *machine = initialize_machine();

	load_rom(machine, "./roms/pong.rom");
	begin_execution(machine);

	shutdown_machine(&machine);

	return 0;
}