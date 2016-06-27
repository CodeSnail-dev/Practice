//#include <iostream>
#include <stdio.h>
#include <vector>
#include <iostream>

typedef std::vector<char> Buffer;

struct data_t {
	int a;
	int b;
	Buffer buffer;
};

typedef struct data_t data_t;

int main()
{
//	data_t data = {1, 2};
	data_t data;
	{
	Buffer buffer('c', 'b');
	data = {1, 2, buffer};
	}

//	printf("%d, %d\n", data.a, data.b);
//	printf("%d\n", buffer);
//	std::cout << buffer.size() << std::endl;
//	std::cout << buffer.front() << std::endl;
	std::cout << data.a << std::endl;
	std::cout << data.b << std::endl;
	std::cout << data.buffer.size() << std::endl;
	std::cout << data.buffer.front() << std::endl;

	return 0;
}
