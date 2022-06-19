#include "Lexer.h"

Lexer::Lexer(Document& code) {
	mainlog.get("Lexer -> starting up\n");
	_code = code;
}

std::list<Token> Lexer::lex_analyse() {
	while(next_token()) {
		mainlog.get("Lexer::lex_analyse() -> next token\n");
	}
	return _token;
}

bool Lexer::next_token() {
	if(!(_pos < _code.size()))
		return false;
	auto tokentypeval = TypeList;
	for(size_t i = 0; i < TypeListLen; i++) {
		auto tokype = tokentypeval[i];
		auto regex = tokype.second._regex;
		auto result = _code.get_code();
		for(size_t i = 0; i < regex.size(); i++) { 
			result.erase(result.begin());
		}
		if(!result.empty()) {
			Type type = tokype.second;
			Token token(type, regex, _pos);
			_pos += regex.length();
			_token.push_back(token);
			mainlog.get("Lexer::next_token() -> ");
			mainlog.get(tokype.second._name);
			mainlog.get('\n');
			return true;
		}
		
	}
	return true;
}

Lexer::~Lexer() {
	mainlog.get("Lexer -> ending up\n");
}
