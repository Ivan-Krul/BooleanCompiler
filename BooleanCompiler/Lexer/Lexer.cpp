#include "Lexer.h"

Lexer::Lexer(Document code) {
	_code = code;
}

std::list<Token> Lexer::lex_analyse() {
	while(next_token()) {
		std::clog << log << "Lexer::lex_analyse() -> Token\n";
	}
	return _token;
}

bool Lexer::next_token() {
	if(!(_pos < _code.size()))
		return false;

	auto tokentype = TypeList;
	for(size_t i = 0; i < TypeListLen; i++) {
		auto tok = tokentype[i];
		auto regex = tok.second._regex;
		auto result = _code.
	}
}
