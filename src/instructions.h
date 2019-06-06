#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "machine.h"

void sys_addr(Machine *machine, uint16_t opcode);
void cls(Machine *machine, uint16_t opcode);
void ret(Machine *machine, uint16_t opcode);
void jp_addr(Machine *machine, uint16_t opcode);
void call_addr(Machine *machine, uint16_t opcode);
void se_vx_byte(Machine *machine, uint16_t opcode);
void sne_vx_byte(Machine *machine, uint16_t opcode);
void se_vx_vy(Machine *machine, uint16_t opcode);
void ld_vx_byte(Machine *machine, uint16_t opcode);
void add_vx_byte(Machine *machine, uint16_t opcode);
void ld_vx_vy(Machine *machine, uint16_t opcode);
void or_vx_vy(Machine *machine, uint16_t opcode);
void and_vx_vy(Machine *machine, uint16_t opcode);
void xor_vx_vy(Machine *machine, uint16_t opcode);
void add_vx_vy(Machine *machine, uint16_t opcode);
void sub_vx_vy(Machine *machine, uint16_t opcode);
void shr_vx_vy(Machine *machine, uint16_t opcode);
void subn_vx_vy(Machine *machine, uint16_t opcode);
void shl_vx_vy(Machine *machine, uint16_t opcode);
void sne_vx_vy(Machine *machine, uint16_t opcode);
void ld_i_addr(Machine *machine, uint16_t opcode);
void jp_v0_addr(Machine *machine, uint16_t opcode);
void rnd_vx_byte(Machine *machine, uint16_t opcode);
void drw_vx_vy_nibble(Machine *machine, uint16_t opcode);
void skp_vx(Machine *machine, uint16_t opcode);
void sknp_vx(Machine *machine, uint16_t opcode);
void ld_vx_dt(Machine *machine, uint16_t opcode);
void ld_vx_k(Machine *machine, uint16_t opcode);
void ld_dt_vx(Machine *machine, uint16_t opcode);
void ld_st_vx(Machine *machine, uint16_t opcode);
void add_i_vx(Machine *machine, uint16_t opcode);
void ld_f_vx(Machine *machine, uint16_t opcode);
void ld_b_vx(Machine *machine, uint16_t opcode);
void ld_i_vx(Machine *machine, uint16_t opcode);
void ld_vx_i(Machine *machine, uint16_t opcode);


#endif