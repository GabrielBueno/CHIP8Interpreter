#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct rom {
	uint8_t *buffer;
	size_t size;
} Rom;

Rom read_rom(const char*);
void dump_rom(Rom);
void close_rom(Rom*);

int main(int argc, char **argv) {
	if (argc < 2) {
		fprintf(stderr, "romdump [path to rom]");
		exit(1);
	}

	Rom rom = read_rom(argv[1]);

	dump_rom(rom);
	close_rom(&rom);
}

Rom read_rom(const char *filename) {
	Rom rom;

	FILE *file          = fopen(filename, "rb");
	uint32_t filesize   = 0;
	uint8_t *rom_buffer = NULL;

	if (file == NULL) {
		fprintf(stderr, "Error reading file %s\n", filename);
		exit(1);
	}

	fseek(file, 0, SEEK_END);
	filesize = ftell(file);
	rewind(file);

	rom_buffer = malloc(filesize * sizeof(uint8_t));

	for (size_t index = 0; !feof(file) && index < filesize; index++) {
		rom_buffer[index] = fgetc(file);
	}

	fclose(file);

	rom.buffer = rom_buffer;
	rom.size   = filesize;

	return rom;
}

void dump_rom(Rom rom) {
	for (uint32_t i; i < rom.size; i++) {
		fprintf(stdout, "0x%X: %x\n", i + 0x200, rom.buffer[i]);
	}
}

void close_rom(Rom *rom) {
	free(rom->buffer);
	rom->buffer = NULL;

	rom->size = 0;
}