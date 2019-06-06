#include "instructions.h"

#include <stdio.h>
#include <stdlib.h>

void sys_addr(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void cls(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ret(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void jp_addr(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void call_addr(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void se_vx_byte(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sne_vx_byte(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void se_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_byte(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void add_vx_byte(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void or_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void and_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void xor_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void add_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sub_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void shr_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void subn_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void shl_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sne_vx_vy(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_i_addr(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void jp_v0_addr(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void rnd_vx_byte(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void drw_vx_vy_nibble(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void skp_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sknp_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_dt(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_k(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_dt_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_st_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void add_i_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_f_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_b_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_i_vx(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_i(Machine *machine, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %x) not implemented. Aborting...\n", opcode);
	exit(1);
}