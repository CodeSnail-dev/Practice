#include "NavShell.h"
#include "MainPart.h"
#include <stdio.h>

int main()
{
    printf("main()\n");

    setCallbackFunction(Show);
	Show(4, 5);
	navShellStart("tony");
	return 0;
}