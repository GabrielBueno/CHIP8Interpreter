#include "machine.h"

#include "instructions.h"

#include <stdio.h>
#include <stdlib.h>

// Util functions

void check_events(Machine *machine);
void do_instruction(Machine *machine);

// machine.h implementation

Machine* initialize_machine() {
	SDL_Init(SDL_INIT_EVERYTHING);

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

	SDL_Quit();

	free(*machine);
	*machine = NULL;
}

void load_rom(Machine *machine, const char *rom_filename) {
	machine->state = MACHINE_ROM_LOADED;

	load_rom_cpu(machine->cpu, rom_filename);
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
	uint16_t opcode = read_opcode(machine->cpu);

	if (opcode == 0x00E0)
		cls(machine, opcode);

	else if (opcode == 0x00EE)
		ret(machine, opcode);

	else if ((opcode & 0xF000) == 0x1000)
		jp_addr(machine, opcode);

	else if ((opcode & 0xF000) == 0x2000)
		call_addr(machine, opcode);

	else if ((opcode & 0xF000) == 0x3000)
		se_vx_byte(machine, opcode);

	else if ((opcode & 0xF000) == 0x4000)
		sne_vx_byte(machine, opcode);

	else if ((opcode & 0xF000) == 0x5000 && (opcode & 0x000F) == 0x0000)
		se_vx_vy(machine, opcode);

	else if ((opcode & 0xF000 )== 0x6000)
		ld_vx_byte(machine, opcode);

	else if ((opcode & 0xF000 )== 0x7000)
		add_vx_byte(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0000)
		ld_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0001)
		or_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0002)
		and_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0003)
		xor_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0004)
		add_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0005)
		sub_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0006)
		shr_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x0007)
		subn_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x8000 && (opcode & 0x000F) == 0x000E)
		shl_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0x9000 && (opcode & 0x000F) == 0x0000)
		sne_vx_vy(machine, opcode);

	else if ((opcode & 0xF000) == 0xA000)
		ld_i_addr(machine, opcode);

	else if ((opcode & 0xF000) == 0xB000)
		jp_v0_addr(machine, opcode);

	else if ((opcode & 0xF000) == 0xC000)
		rnd_vx_byte(machine, opcode);

	else if ((opcode & 0xF000) == 0xD000)
		drw_vx_vy_nibble(machine, opcode);

	else if ((opcode & 0xF000) == 0xE000 && (opcode & 0x00FF) == 0x009E)
		skp_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xE000 && (opcode & 0x00FF) == 0x00A1)
		sknp_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x0007)
		ld_vx_dt(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x000A)
		ld_vx_k(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x0015)
		ld_dt_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x0018)
		ld_st_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x001E)
		add_i_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x0029)
		ld_f_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x0033)
		ld_b_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x0055)
		ld_i_vx(machine, opcode);

	else if ((opcode & 0xF000) == 0xF000 && (opcode & 0x00FF) == 0x0065)
		ld_vx_i(machine, opcode);
}