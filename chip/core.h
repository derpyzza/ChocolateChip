#ifndef CORE_H
#define CORE_H

#include <stdint.h>
#define _byte uint8_t
#define _u16 uint16_t

typedef struct
{
	// registers
	_byte stack_pointer;
	_u16 index_register;
	_u16 program_counter; // program counter. start at 0x200
	_byte registers[16];

	// timers
	
	_byte sound_timer;
	_byte delay_timer;

	// memory and stack
	_u16 return_stack[16];
	_byte memory[4096];

} CORE_cpu; // main chip-8 cpu


void CORE_maskTest();



#endif
