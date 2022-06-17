// BooleanCompiler.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <thread>
#include "Define/Define.h"
#include "Document/Document.h"
#include "Token/Token.h"
#include "Lexer/Lexer.h"
#include "Logger/Logger.h"

void moaoion() {
	Logger log("main");
	log << "function main(size_t args, char* argv[]) is started\n";

	Document doc;
	doc.write("code.bol");
	Lexer l(doc);
	l.lex_analyse();

	log << "function main(size_t args, char* argv[]) is done\n";
}

int main(int args, char* argv[]) {
	auto beg = std::chrono::system_clock::now();
	std::unique_ptr<std::thread>(moaoion);
	moaoion->detach();
	while(
		std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - beg).count() < 5
		);


	return 0;
}
