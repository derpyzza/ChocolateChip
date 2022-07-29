small chip-8 interpreter.

TODO rewrite before release / final build / whatever you wanna call it

chip-8 specs

sixteen 8-bit registers ( V0 - VF ),
a 16-bit index register,
a stack that can hold 16 16-bit values
8-bit stack pointer
8-bit delay timer
8-bit sound timer
64x32 bit frame buffer
16-bit program counter

4096 bytes (4kb) of addressable memory

separate interpreter to three modules:
	
	the backend ( core.c )
	the tui frontend ( tui/ )
	the gui frontend ( gui/ )

TODO:

	MAIN:
	[] arg parsing
	[] separate flags for gui and tui modes
	[] idk what im gonna do here im ngl lol
	
	CORE:
	[] interpret instructions
	[] read rom files into memory
	[] create a generic interface for the gui frontends
