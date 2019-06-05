#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "cpu.h"

void sys_addr(CPU *cpu, uint16_t opcode);
void cls(CPU *cpu, uint16_t opcode);
void ret(CPU *cpu, uint16_t opcode);
void jp_addr(CPU *cpu, uint16_t opcode);
void call_addr(CPU *cpu, uint16_t opcode);
void se_vx_byte(CPU *cpu, uint16_t opcode);
void sne_vx_byte(CPU *cpu, uint16_t opcode);
void se_vx_vy(CPU *cpu, uint16_t opcode);
void ld_vx_byte(CPU *cpu, uint16_t opcode);
void add_vx_byte(CPU *cpu, uint16_t opcode);
void ld_vx_vy(CPU *cpu, uint16_t opcode);
void or_vx_vy(CPU *cpu, uint16_t opcode);
void and_vx_vy(CPU *cpu, uint16_t opcode);
void xor_vx_vy(CPU *cpu, uint16_t opcode);
void add_vx_vy(CPU *cpu, uint16_t opcode);
void sub_vx_vy(CPU *cpu, uint16_t opcode);
void shr_vx_vy(CPU *cpu, uint16_t opcode);
void subn_vx_vy(CPU *cpu, uint16_t opcode);
void shl_vx_vy(CPU *cpu, uint16_t opcode);
void sne_vx_vy(CPU *cpu, uint16_t opcode);
void ld_i_addr(CPU *cpu, uint16_t opcode);
void jp_v0_addr(CPU *cpu, uint16_t opcode);
void rnd_vx_byte(CPU *cpu, uint16_t opcode);
void drw_vx_vy_nibble(CPU *cpu, uint16_t opcode);
void skp_vx(CPU *cpu, uint16_t opcode);
void sknp_vx(CPU *cpu, uint16_t opcode);
void ld_vx_dt(CPU *cpu, uint16_t opcode);
void ld_vx_k(CPU *cpu, uint16_t opcode);
void ld_dt_vx(CPU *cpu, uint16_t opcode);
void ld_st_vx(CPU *cpu, uint16_t opcode);
void add_i_vx(CPU *cpu, uint16_t opcode);
void ld_f_vx(CPU *cpu, uint16_t opcode);
void ld_b_vx(CPU *cpu, uint16_t opcode);
void ld_i_vx(CPU *cpu, uint16_t opcode);
void ld_vx_i(CPU *cpu, uint16_t opcode);


#endif