#include <stdio.h>

void show();

void called()
{
	show();

	printf("%s\n", __FUNCTION__);
}
