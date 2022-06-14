// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "Define/Define.h"

int main(size_t args, char* argv[]) {
	for(size_t i = 0; i < args; i++)
		std::cout << argv[i]<<'\n';

	int a = 10;
	int b = 4;

	std::cout << to_bools<int>(a) << ' '<< to_bools<int>(b)<<'\n';

	a <<= b;

	std::cout << to_bools<int>(a)<< '\n';

	return 0;
}
