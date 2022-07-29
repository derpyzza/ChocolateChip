#include "core.h"
#include "tui/tui.h"
#include <stdio.h>

int
main(void)
{
	printf("this is the main file\n");
	CORE_maskTest();
	TUI_test();
}
