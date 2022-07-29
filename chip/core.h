#ifndef CORE_H
#define CORE_H

#include <stdint.h>
#define _byte uint8_t
#define _u16 uint16_t

/* NOTE, i took the liberty of renaming some of these myself. the spec sheet i used ( http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#3.1 ),
 * used lots of repeating instruction names with differring arguements, which i couldn't figure out how to stuff in an enum,
 * so i made up my own names according to what i felt made the most sense. I will be renaming these in the future, but for now, we're stuck with these :)
 */
typedef enum
{
	CLS		= 0x00E0, // clear screen.
	RET 	= 0x00EE, // return from a subroutine.
	JPAD  = 0x1000, // 1nnn, jump to location nnn.
	CALL	=	0x2000, // 2nnn, call subroutine at location nnn.
	SEB 	= 0x3000, // 3xkk, skip next instruction if Vx == kk. SE renamed to SEB for clarity.
	SNEB 	= 0x4000, // 4xkk, skip next instruction if Vx != kk.
	SERY	= 0x5000, // 5xy0, skip next instruction if Vx == Vy. SE renamed to SEQ for clarity.
	LDB		= 0x6000, // 6xkk, Set Vx = kk.
	ADDB	= 0x7000, // 7xkk, Set Vx = Vx + kk.
	LDRY 	= 0x8000, // 8xy0, Set Vx = Vy.
	OR		= 0x8001, // 8xy1, Set Vx = Vx OR Vy.
	AND 	= 0x8002, // 8xy2, Set Vx = Vx AND Vy.
	XOR		=	0x8003, // 8xy3, Set Vx = Vx XOR Vy.
	ADRY	=	0x8004, // 8xy4, Set Vx = Vx + Vy, set VF = carry.
	SUB		= 0x8005, // 8xy5, Set Vx = Vx - Vy, set VF = NOT borrow.
	SHR		= 0x8006,	// 8xy6, Set Vx = Vx SHR 1.
	SUBN	= 0x8007, // 8xy7, Set Vx = Vy - Vx, set VF = NOT borrow
	SHL		= 0x800E, // 8xyE, Set Vx = Vx SHL 1.
	SNEY 	= 0x9000, // 9xy0, Skip next instruction if Vx != Vy.
	LDA		= 0xA000, // Annn, Set i = nnn.
	JPI		= 0xB000, // Bmmm, Jump to location nnn + V0.
	RND		= 0xC000, // Cxkk, Set Vx = random byte AND kk.
	DRW		= 0xD000, // Dxyn, Display n-byte sprite starting at memory location I at (Vx, Vy), set VF = collision.
	SKP		= 0xE09E, // Ex9E, Skip next instruction if key with the value of Vx is pressed.
	SKNP	= 0xE0A1, // ExA1, Skip next instruction if key with the value of Vx is not pressed.
	LDDT	= 0xF007, // Fx07, Set Vx = delay timer value.
	LDXK 	= 0xF00A, // Fx0A, Wait for a key press, store the value of the key in Vx.
	LDDX	= 0xF015, // Fx15, Set delay timer = Vx.
	LDST	= 0xF018, // Fx18, Set sound timer = Vx.
	ADIX	= 0xF01E, // Fx1E, Set I = I + Vx.
	LDFX	= 0xF029, // Fx29, Set I = location of sprite for digit Vx.
	LDBX	= 0xF033, // Fx33, Store BCD representation of Vx in memory locations I, I+1, and I+2.
	LDXI	= 0xF055, // Fx55, Store registers V0 through Vx in memory starting at location I.
	LDII	= 0xF065, // Fx65, Read registers V0 through Vx from memory starting at location I.
} CODE;

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

} CPU; // main chip-8 cpu


void CORE_maskTest();



#endif
