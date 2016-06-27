#include <stdio.h>
#include "NavShell.h"
#include "MainPart.h"


CallbackFunction mcb;

void setCallbackFunction(CallbackFunction f)
{
	mcb = f;
}

void navShellStart(const char* name)
{
    mcb(1, 2);
	printf("Hello world! %s\n", name);
}