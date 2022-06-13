// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>

int main(size_t args, char* argv[]) {
	for(size_t i = 0; i < args; i++)
		std::cout << argv[i]<<'\n';
	std::cout << "Hello CMake.\n";
	return 0;
}
