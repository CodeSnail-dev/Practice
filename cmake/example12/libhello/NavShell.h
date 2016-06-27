#ifndef DBZHANG_HELLO_
#define DBZHANG_HELLO_
#if defined _WIN32
	#ifdef WIN32
		#define DllExport __declspec( dllexport )
	#else
		#define DllExport __declspec( dllimport )
	#endif
#else
	#define DllExport
#endif
DllExport void navShellStart(const char* name);
#endif //DBZHANG_HELLO_