// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "Define/Define.h"
#include "Document/Document.h"
#include "Token/Token.h"
#include "Lexer/Lexer.h"
#include "Logger/Logger.h"

size_t Logger::count = 0;

int main(int args, char* argv[]) {
	Logger log("main",true);
	log << "function main(size_t args, char* argv[]) is started\n";

	Document doc;
	doc.write("code.bol");
	//Lexer l(doc);
	//l.lex_analyse();
	

	log << "function main(size_t args, char* argv[]) is done\n";
	return 0;
}
