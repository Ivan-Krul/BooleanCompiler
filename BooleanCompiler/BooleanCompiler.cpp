// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <thread>
#include "Define/Define.h"
#include "Document/Document.h"
#include "Token/Token.h"
#include "Lexer/Lexer.h"
#include "Logger/Logger.h"

int main(int args, char* argv[]) {
	std::clog << log << "function main(size_t args, char* argv[]) is started\n";
	for(int a = 0; a < args; a++) {
		std::clog << log << "argument[" << a << "] -> " << argv[a]<<'\n';
	}

	Document doc;
	doc.write("code.bol");
	Lexer l(doc);
	l.lex_analyse();

	std::clog << log << "function main(size_t args, char* argv[]) is done\n";
	return 0;
}
