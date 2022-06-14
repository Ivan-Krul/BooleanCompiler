// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "Define/Define.h"
#include "Document/Document.h"
#include "Token/Token.h"
#include "Lexer/Lexer.h"

int main(int args, char* argv[]) {
	std::clog << log << "function main(size_t args, char* argv[]) is started\n";
	Document doc;
	doc.write("code.bol");
	std::cout<< out<<doc.size()<<'\n';
	std::cout << out <<"\""<< doc.get_code() << "\"\n";

	std::clog << log << "function main(size_t args, char* argv[]) is done\n";
	return 0;
}
