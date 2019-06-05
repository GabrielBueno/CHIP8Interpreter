#include "machine.h"

#include <stdio.h>
#include <stdlib.h>

// Util functions

void check_events(Machine *machine);
void do_instruction(Machine *machine);

// machine.h implementation

Machine* initialize_machine() {
	Machine *machine = malloc(sizeof(machine));

	machine->screen   = init_screen("CHIP8 Emulator", 640, 320);
	machine->keyboard = init_keyboard();
	machine->cpu      = init_cpu();

	machine->state = MACHINE_INITIALIZED;

	return machine;
}

void shutdown_machine(Machine **machine) {
	(*machine)->state = MACHINE_EXITING;

	close_screen(&(*machine)->screen);
	close_keyboard(&(*machine)->keyboard);
	close_cpu(&(*machine)->cpu);

	free(*machine);
	*machine = NULL;
}

void load_rom(Machine *machine, const char *rom_filename) {
	machine->state = MACHINE_ROM_LOADED;

	load_rom(machine->cpu, rom_filename);
}

void begin_execution(Machine *machine) {
	machine->state = MACHINE_EXECUTING;

	while (machine->state != MACHINE_EXITING) {
		check_events(machine);
		do_instruction(machine);

		screen_draw(machine->screen);
	}
}

// Util function implementation

void check_events(Machine *machine) {
	SDL_Event e;

	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) 
			machine->state = MACHINE_EXITING;

		if (e.type == SDL_KEYDOWN)
			set_key_down(machine->keyboard, e.key.keysym.sym);

		if (e.type == SDL_KEYUP)
			set_key_up(machine->keyboard, e.key.keysym.sym);
	}
}

void do_instruction(Machine *machine) {

}