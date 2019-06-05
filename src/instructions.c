#include "instructions.h"

#include <stdio.h>
#include <stdlib.h>

void sys_addr(CPU *cpu, uint16_t opcode) {
	cpu->pc += 1;
}

void cls(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ret(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void jp_addr(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void call_addr(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void se_vx_byte(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sne_vx_byte(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void se_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_byte(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void add_vx_byte(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void or_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void and_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void xor_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void add_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sub_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void shr_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void subn_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void shl_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sne_vx_vy(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_i_addr(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void jp_v0_addr(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void rnd_vx_byte(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void drw_vx_vy_nibble(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void skp_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void sknp_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_dt(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_k(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_dt_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_st_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void add_i_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_f_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_b_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_i_vx(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}

void ld_vx_i(CPU *cpu, uint16_t opcode) {
	fprintf(stdout, "Instruction (opcode: %d) not implemented. Aborting...\n", opcode);
	exit(1);
}