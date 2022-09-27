#ifndef DEBUG_H
#define DEBUG_H

// assert macro.
// NOTE: improve later on to include strict typing.
#define _asserteq(x,y) {\
		if(x!=y)\
		{\
		fprintf(stderr, "\033[31m[ASSERT ERROR]\033[m expected %i, got %i instead\n", y, x);}}


#endif
