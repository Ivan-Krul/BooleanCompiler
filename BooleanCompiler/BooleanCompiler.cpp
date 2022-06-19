// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Define/Define.h"
//#include "Document/Document.h"
//#include "Token/Token.h"
//#include "Lexer/Lexer.h"
#include "Logger/FileLogger/FileLogger.h"

int main(int args, char* argv[]) {
	auto* mainlog = new FileLogger();
	mainlog->init("main");
	mainlog->get("function main(size_t args, char* argv[]) is started\n");
	for(int a = 0; a < args; a++) {
		mainlog->get("argument[");
		mainlog->get(a);
		mainlog->get("] -> ");
		mainlog->get(argv[a]);
		mainlog->get('\n');
	}

	using namespace std::chrono_literals;
	std::this_thread::sleep_for(5s);
	//Document doc;
	//doc.write("code.bol");
	//Lexer l(doc);
	//l.lex_analyse();


	mainlog->get("function main(size_t args, char* argv[]) is done\n");
	mainlog->finit();
	delete mainlog;
	return 0;
}
