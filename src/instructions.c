#include "instructions.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "screen.h"
#include "keyboard.h"

void sys_addr(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction SYS addr (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void cls(Machine *machine, uint16_t opcode) {
	clear_screen(machine->screen);
}

void ret(Machine *machine, uint16_t opcode) {
	machine->cpu->pc = machine->cpu->stack[machine->cpu->sp];

	printf("Stack pointer: %x\nJumping to address: %x\n\n", machine->cpu->sp, machine->cpu->pc);

	machine->cpu->sp -= 1;
}

void jp_addr(Machine *machine, uint16_t opcode) {
	uint16_t addr = opcode & 0x0FFF;

	printf("Jumping to address: %x\n\n", addr);

	(*machine->cpu).pc = addr;
}

void call_addr(Machine *machine, uint16_t opcode) {
	uint16_t addr = opcode & 0x0FFF;

	machine->cpu->sp += 1;
	machine->cpu->stack[machine->cpu->sp] = machine->cpu->pc;

	machine->cpu->pc = addr;
}

void se_vx_byte(Machine *machine, uint16_t opcode) {
	uint8_t reg  = (opcode & 0x0F00) >> 8;
	uint8_t byte = opcode & 0x00FF;

	if (machine->cpu->v[reg] == byte)
		machine->cpu->pc += 2;
}

void sne_vx_byte(Machine *machine, uint16_t opcode) {
	uint8_t reg  = (opcode & 0x0F00) >> 8;
	uint8_t byte = opcode & 0x00FF;

	if (machine->cpu->v[reg] != byte)
		machine->cpu->pc += 2;
}

void se_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg1 = (opcode & 0x0F00) >> 8;
	uint8_t reg2 = (opcode & 0x00F0) >> 4;

	if (machine->cpu->v[reg1] == machine->cpu->v[reg2])
		machine->cpu->pc += 2;
}

void ld_vx_byte(Machine *machine, uint16_t opcode) {
	uint8_t reg  = (opcode & 0x0F00) >> 8;
	uint8_t byte = opcode & 0x00FF;

	machine->cpu->v[reg] = byte;
}

void add_vx_byte(Machine *machine, uint16_t opcode) {
	uint8_t reg  = (opcode & 0x0F00) >> 8;
	uint8_t byte = opcode & 0x00FF;

	machine->cpu->v[reg] += byte;
}

void ld_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[reg_x] = machine->cpu->v[reg_y];
}

void or_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[reg_x] = machine->cpu->v[reg_x] | machine->cpu->v[reg_y];
}

void and_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[reg_x] = machine->cpu->v[reg_x] & machine->cpu->v[reg_y];
}

void xor_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[reg_x] = machine->cpu->v[reg_x] ^ machine->cpu->v[reg_y];
}

void add_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	uint16_t sum = machine->cpu->v[reg_x] + machine->cpu->v[reg_y];

	machine->cpu->v[reg_x] = sum & 0x00FF;
	machine->cpu->v[0x0F]  = (sum >> 8) >= 1;
}

void sub_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[reg_x] = machine->cpu->v[reg_x] - machine->cpu->v[reg_y];
	machine->cpu->v[0x0F]  = machine->cpu->v[reg_x] >= machine->cpu->v[reg_y];
}

void shr_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[0x0F]   = machine->cpu->v[reg_x] & 0x01;
	machine->cpu->v[reg_x] /= 2;
}

void subn_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[reg_x] = machine->cpu->v[reg_y] - machine->cpu->v[reg_x];
	machine->cpu->v[0x0F]  = machine->cpu->v[reg_y] >= machine->cpu->v[reg_x];
}

void shl_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint8_t reg_y = (opcode & 0x00F0) >> 4;

	machine->cpu->v[0x0F]   = machine->cpu->v[reg_x] & 0x80;
	machine->cpu->v[reg_x] *= 2;
}

void sne_vx_vy(Machine *machine, uint16_t opcode) {
	uint8_t reg1 = (opcode & 0x0F00) >> 8;
	uint8_t reg2 = (opcode & 0x00F0) >> 4;

	if (machine->cpu->v[reg1] != machine->cpu->v[reg2])
		machine->cpu->pc += 2;
}

void ld_i_addr(Machine *machine, uint16_t opcode) {
	uint16_t addr = opcode & 0x0FFF;

	machine->cpu->i = addr;
}

void jp_v0_addr(Machine *machine, uint16_t opcode) {
	uint16_t addr = opcode & 0x0FFF;

	machine->cpu->pc = machine->cpu->v[0] + addr;
}

void rnd_vx_byte(Machine *machine, uint16_t opcode) {
	srand(time(NULL));

	uint8_t byte  =  opcode & 0x00FF;
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	uint8_t rnd_byte = rand() % 256;

	machine->cpu->v[reg_x] = rnd_byte & byte;
}

void drw_vx_vy_nibble(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8; 
	uint8_t reg_y = (opcode & 0x00F0) >> 4;
	uint8_t sprite_lenght = opcode & 0x000F;

	uint16_t i = machine->cpu->i;
	uint8_t reg_x_val = machine->cpu->v[reg_x];
	uint8_t reg_y_val = machine->cpu->v[reg_y];

	for (size_t n = 0; n < sprite_lenght; n++) {
		uint8_t byte = machine->cpu->memory[i + n];
		screen_load_byte(machine->screen, byte, reg_x_val, reg_y_val + n);
	}
}

void skp_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	if (machine->keyboard->keystate[reg_x])
		machine->cpu->pc += 2;
}

void sknp_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	if (!machine->keyboard->keystate[reg_x])
		machine->cpu->pc += 2;
}

void ld_vx_dt(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	machine->cpu->v[reg_x] = machine->cpu->delay_timer;
}

void ld_vx_k(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	machine->cpu->v[reg_x] = wait_until_keypress(machine->keyboard);
}

void ld_dt_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	machine->cpu->delay_timer = machine->cpu->v[reg_x];
}

void ld_st_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	machine->cpu->sound_timer = machine->cpu->v[reg_x];
}

void add_i_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	machine->cpu->i += machine->cpu->v[reg_x];
}

void ld_f_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	uint8_t sprite_value = reg_x & 0x0F;

	machine->cpu->i = sprite_value * 5;
}

void ld_b_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;

	uint16_t i = machine->cpu->i;
	uint8_t reg_val = machine->cpu->v[reg_x];

	machine->cpu->memory[i]   = (reg_val / 100) % 10;
	machine->cpu->memory[i+1] = (reg_val / 10) % 10;
	machine->cpu->memory[i+2] = reg_val % 10;
}

void ld_i_vx(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint16_t i = machine->cpu->i;

	for (size_t reg; reg <= reg_x; reg++)
		machine->cpu->memory[i + reg] = machine->cpu->v[reg];
}

void ld_vx_i(Machine *machine, uint16_t opcode) {
	uint8_t reg_x = (opcode & 0x0F00) >> 8;
	uint16_t i = machine->cpu->i;

	for (size_t reg; reg <= reg_x; reg++)
		machine->cpu->v[reg] = machine->cpu->memory[i + reg];
}