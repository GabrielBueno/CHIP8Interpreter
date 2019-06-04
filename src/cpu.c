#include "cpu.h"

#include <stdio.h>
#include <stdlib.h>

CPU* init_cpu() {
	CPU *cpu = malloc(sizeof(CPU));

	erase_memory(cpu);

	for (size_t i = 0; i < 16; i++) {
		cpu->stack[i] = 0x00;
		cpu->v[i]     = 0x00;
	}

	cpu->i           = 0x00;
	cpu->pc          = 0x00;
	cpu->sp          = 0x00;
	cpu->sound_timer = 0x00;
	cpu->delay_timer = 0x00;

	return cpu;
}

void close_cpu(CPU **cpu) {
	free(*cpu);
	*cpu = NULL;
}

void erase_memory(CPU *cpu) {
	for (size_t mempos = 0; mempos < MEMSIZE; mempos++) 
		cpu->memory[mempos] = 0x00;
}

void load_rom(CPU *cpu, const char *filename) {
	FILE *file = fopen(filename, "rb");

	if (file == NULL) {
		fprintf(stderr, "Error loading file %s\n", filename);
		exit(1);
	}

	fgets(&cpu->memory[2], 0x2000, file);

	fclose(file);
	file = NULL;
}

void memdump(CPU *cpu) {
	for (uint16_t addr = 0x00; addr <= 0xFFF; addr += 2) {
		fprintf(stdout, "%x ", cpu->memory[addr] << 8 | cpu->memory[addr + 1]);

		if (addr != 0 && addr % 16 == 0)
			fprintf(stdout, "\n");
	}
}