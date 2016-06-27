#include <stdio.h>

extern void called();

void show()
{
	printf("%s\n", __FUNCTION__);
	printf("%s\n", __func__);
	printf("%d\n", __LINE__);
}

int main()
{
	show();
	called();

	return 0;
}
