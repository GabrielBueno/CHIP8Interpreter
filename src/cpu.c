#include "cpu.h"

#include <stdio.h>
#include <stdlib.h>

void load_sprites(CPU*);

CPU* init_cpu() {
	CPU *cpu = malloc(sizeof(CPU));

	erase_memory(cpu);

	for (size_t i = 0; i < 16; i++) {
		cpu->stack[i] = 0x00;
		cpu->v[i]     = 0x00;
	}

	cpu->i           = 0x00;
	cpu->pc          = 0x200;
	cpu->sp          = 0x00;
	cpu->sound_timer = 0x00;
	cpu->delay_timer = 0x00;

	load_sprites(cpu);

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

	for (size_t index = 0x200; !feof(file) && index <= 0xFFF + 1; index++) {
		if (index == 0xFFF + 1) {
			fprintf(stdout, "Could not load ROM into memory. File is too big.\nExiting...");
			exit(1);
		}

		uint32_t byte = fgetc(file);
		
		if (feof(file))
			break;

		cpu->memory[index] = byte;
	}


	fclose(file);
	file = NULL;
}

void memdump(CPU *cpu) {
	for (uint16_t addr = 0x00; addr <= 0xFFF - 2; addr += 2) {
		fprintf(stdout, "%x ", cpu->memory[addr] << 8 | cpu->memory[addr + 1]);

		if (addr != 0 && addr % 16 == 0)
			fprintf(stdout, "\n");
	}
}

void load_sprites(CPU *cpu) {
	// 0
	cpu->memory[0x00] = 0xF0;
	cpu->memory[0x01] = 0x90;
	cpu->memory[0x02] = 0x90;
	cpu->memory[0x03] = 0x90;
	cpu->memory[0x04] = 0xF0;

	// 1 
	cpu->memory[0x05] = 0x20;
	cpu->memory[0x06] = 0x60;
	cpu->memory[0x07] = 0x20;
	cpu->memory[0x08] = 0x20;
	cpu->memory[0x09] = 0x70;

	// 2
	cpu->memory[0x0A] = 0xF0;
	cpu->memory[0x0B] = 0x10;
	cpu->memory[0x0C] = 0xF0;
	cpu->memory[0x0D] = 0x80;
	cpu->memory[0x0E] = 0xF0;

	// 3
	cpu->memory[0x0F] = 0x20;
	cpu->memory[0x10] = 0x60;
	cpu->memory[0x11] = 0x20;
	cpu->memory[0x12] = 0x20;
	cpu->memory[0x13] = 0x70;

	// 4 
	cpu->memory[0x14] = 0x20;
	cpu->memory[0x15] = 0x60;
	cpu->memory[0x16] = 0x20;
	cpu->memory[0x17] = 0x20;
	cpu->memory[0x18] = 0x70;

	// 5
	cpu->memory[0x19] = 0x20;
	cpu->memory[0x1A] = 0x60;
	cpu->memory[0x1B] = 0x20;
	cpu->memory[0x1C] = 0x20;
	cpu->memory[0x1D] = 0x70;

	// 6 
	cpu->memory[0x1E] = 0x20;
	cpu->memory[0x1F] = 0x60;
	cpu->memory[0x20] = 0x20;
	cpu->memory[0x21] = 0x20;
	cpu->memory[0x22] = 0x70;

	// 7 
	cpu->memory[0x23] = 0x20;
	cpu->memory[0x24] = 0x60;
	cpu->memory[0x25] = 0x20;
	cpu->memory[0x26] = 0x20;
	cpu->memory[0x27] = 0x70;

	// 8 
	cpu->memory[0x28] = 0x20;
	cpu->memory[0x29] = 0x60;
	cpu->memory[0x2A] = 0x20;
	cpu->memory[0x2B] = 0x20;
	cpu->memory[0x2C] = 0x70;

	// 9 
	cpu->memory[0x2D] = 0x20;
	cpu->memory[0x2E] = 0x60;
	cpu->memory[0x2F] = 0x20;
	cpu->memory[0x30] = 0x20;
	cpu->memory[0x31] = 0x70;

	// A
	cpu->memory[0x32] = 0x20;
	cpu->memory[0x33] = 0x60;
	cpu->memory[0x34] = 0x20;
	cpu->memory[0x35] = 0x20;
	cpu->memory[0x36] = 0x70;

	// B 
	cpu->memory[0x37] = 0x20;
	cpu->memory[0x38] = 0x60;
	cpu->memory[0x39] = 0x20;
	cpu->memory[0x3A] = 0x20;
	cpu->memory[0x3B] = 0x70;

	// C 
	cpu->memory[0x3C] = 0x20;
	cpu->memory[0x3D] = 0x60;
	cpu->memory[0x3E] = 0x20;
	cpu->memory[0x40] = 0x20;
	cpu->memory[0x41] = 0x70;

	// D 
	cpu->memory[0x42] = 0x20;
	cpu->memory[0x43] = 0x60;
	cpu->memory[0x44] = 0x20;
	cpu->memory[0x45] = 0x20;
	cpu->memory[0x46] = 0x70;

	// E 
	cpu->memory[0x47] = 0x20;
	cpu->memory[0x48] = 0x60;
	cpu->memory[0x49] = 0x20;
	cpu->memory[0x4A] = 0x20;
	cpu->memory[0x4B] = 0x70;

	// F 
	cpu->memory[0x4C] = 0x20;
	cpu->memory[0x4D] = 0x60;
	cpu->memory[0x4E] = 0x20;
	cpu->memory[0x4F] = 0x20;
	cpu->memory[0x50] = 0x70;
}