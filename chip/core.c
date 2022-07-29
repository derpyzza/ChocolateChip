#include "core.h"
#include <stdio.h>
#include "debug.h"
#define _mask(opcode,mask) (opcode & mask)

#ifdef DEBUG
	void CORE_maskTest() {
		_asserteq(_mask(0x8124, 0xf00f), 0x8004);	
	}
#endif 

void interpret (); // bulk of the cpu
void run(); // run each instruction. prolly unnecessary.

void disassemble(CODE code) {
		
} // for debuggging purposes.
