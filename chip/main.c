#include <stdio.h>

int
main(void)
{
#ifdef DEBUG
	printf("debug mode\n");
#endif
	printf("bleh\n");
}
