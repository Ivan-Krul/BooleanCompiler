#pragma once
#include <iostream>
#define SYMTRUE_ '1'
#define SYMFALSE '0'

static std::ostream& log(std::ostream& out) {
	return out << "LOG: ";
}
static std::ostream& err(std::ostream& out) {
	return out << "ERR: ";
}
static std::ostream& out(std::ostream& out) {
	return out << "OUT: ";
}

template<typename T>
char* to_bool(T adr) {
	char* result;
	result = new char[sizeof(T) * 8 + 1];
	result[sizeof(T) * 8] = '\0';

	for(int i = 0; i < sizeof(T) * 8; i++) {
		result[sizeof(T) * 8-i-1] = (adr / int(pow(2,i))) % 2 == 1 ? SYMTRUE_ : SYMFALSE;
	}

	
	return result;
}

template<typename T>
char* to_bools(T adr,char empty_space = '=') {
	char* result;
	result = new char[sizeof(T) * 8 + 1];
	result[sizeof(T) * 8] = '\0';

	bool is_a_num = false;
	for(int i = sizeof(T) * 8-1; i < sizeof(T) * 8; i--) {
		if(!is_a_num)
			if((adr / int(pow(2, i))) % 2 == 1) { 
				is_a_num = true;
				result[sizeof(T) * 8-i-1] = SYMTRUE_;
			}
			else result[sizeof(T) * 8 - i - 1] = empty_space;
		else result[sizeof(T) * 8 - i - 1] = (adr / int(pow(2, i))) % 2 == 1 ? SYMTRUE_ : SYMFALSE;
	}

	return result;
}

