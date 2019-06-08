#ifndef CPU_H
#define CPU_H

#include <stdint.h>

#define MEMSIZE 4096

typedef struct cpu {
	uint8_t  memory[MEMSIZE];
	uint16_t stack[16];
	uint8_t  v[16];
	uint16_t i;
	uint16_t pc;
	uint8_t  sp;
	uint8_t  sound_timer;
	uint8_t  delay_timer;
} CPU;

CPU* init_cpu();
void close_cpu(CPU **cpu);

void erase_memory(CPU *cpu);
void load_rom_cpu(CPU *cpu, const char *filename);
void memdump(CPU *cpu);
void print_state(CPU *cpu);

uint16_t read_opcode(CPU *cpu);

#endif