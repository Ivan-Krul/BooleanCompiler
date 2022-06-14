#pragma once
#include "../Define/Define.h"
#include "../Document/Document.h"
#include "../Token/Token.h"

class Lexer {
	Document _code;
	size_t _pos = 0;

	std::list<Token> _token;

public:
	Lexer(Document code);

	std::list<Token> lex_analyse();
	bool next_token();
};
#include "Lexer.cpp"
