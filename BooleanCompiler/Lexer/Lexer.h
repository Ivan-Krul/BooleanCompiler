#pragma once
#include "../Define/Define.h"
#include "../Document/Document.h"
#include "../Token/Token.h"
#include "../Logger/Logger.h"

class Lexer {
	Document _code;
	size_t _pos = 0;
	Logger* _log;

	std::list<Token> _token;

public:
	Lexer(Document& code);

	bool next_token();
	std::list<Token> lex_analyse();


	~Lexer();
};
#include "Lexer.cpp"
