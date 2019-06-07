#ifndef MACHINE_H
#define MACHINE_H

#include "cpu.h"
#include "keyboard.h"
#include "screen.h"

#define MACHINE_INITIALIZED 1
#define MACHINE_ROM_LOADED  2
#define MACHINE_EXECUTING   3
#define MACHINE_PAUSED      4
#define MACHINE_EXITING     5

#define MACHINE_CLOCK_HZ      60
#define MACHINE_TIMER_FREQ_HZ 60

typedef struct machine {
	CPU *cpu;
	Screen *screen;
	Keyboard *keyboard;
	uint8_t state;
} Machine;

Machine* initialize_machine();
void shutdown_machine(Machine **machine);

void load_rom(Machine *machine, const char *rom_filename);
void begin_execution(Machine *machine);

void sound_buzzer();

#endif