// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include "Define/Define.h"
#include "Document/Document.h"
#include "Token/Token.h"
#include "Lexer/Lexer.h"
#include "Logger/Logger.h"

int main(int args, char* argv[]) {
	std::clog << log << "function main(size_t args, char* argv[]) is started\n";

	/*Document doc;
	doc.write("code.bol");
	Lexer l(doc);
	l.lex_analyse();
	*/
	Logger l("test");

	l << "heya";
	

	std::clog << log << "function main(size_t args, char* argv[]) is done\n";
	return 0;
}
