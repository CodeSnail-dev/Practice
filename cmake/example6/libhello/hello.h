#ifndef DBZHANG_HELLO_
#define DBZHANG_HELLO_
#if defined _WIN32
	#if LIBHELLO_BUILD
		#define LIBHELLO_API __declspec(dllexport)
	#else
		#define LIBHELLO_API __declspec(dllimport)
	#endif
#else
	#define LIBHELLO_API
#endif
void LIBHELLO_API hello(const char* name);
#endif //DBZHANG_HELLO_