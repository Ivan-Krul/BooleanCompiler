// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "Define/Define.h"
#include "Document/Document.h"
#include "Token/Token.h"
#include "Lexer/Lexer.h"

int main(size_t args, char* argv[]) {
	std::clog << log << "function main(size_t args, char* argv[]) is started\n";
	Document doc;
	doc.write("code.bol");

	std::clog << log << "function main(size_t args, char* argv[]) is done\n";
	return 0;
}
