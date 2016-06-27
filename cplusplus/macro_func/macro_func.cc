#include <stdio.h>

int main()
{
	printf("%d\n", __LINE__);
	printf("%s\n", __func__);
	printf("%s\n", __FUNCTION__);

	return 0;
}
