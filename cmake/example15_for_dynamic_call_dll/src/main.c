#include <stdio.h>
#include <windows.h>

typedef void (*f)(char *);
typedef int TYPE_INT;

int main()
{
    TYPE_INT a;
    f show_hello = NULL;
    
	HINSTANCE hdll = LoadLibrary("hello.dll");
	if (hdll == NULL) {
		FreeLibrary(hdll);
		printf("LoadLibrary libhello.dll failed!\n");

		return 1;
	}

//	f show_hello;
//	abc func_abc;
    if (show_hello == NULL) {
        printf("show_hello is NULL");
    }
    
	show_hello = (f)GetProcAddress(hdll, "hello");
	
    if (show_hello == NULL) {
        printf("show_hello is NULL");
    }

//	hello("Form hello World");
	show_hello("tony");

	return 0;
} 