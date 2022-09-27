#include "core.h"
#include "tui/tui.h"
#include <stdio.h>

int
main(void)
{
	printf("this is the main file\n");
	printf("%x\n", ~(0x6000&0xffff));
	CORE_maskTest();
	TUI_test();
}
