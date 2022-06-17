#include "Lexer.h"

Lexer::Lexer(Document& code) {
	_log = new Logger("lexer");
	_code = code;
}

std::list<Token> Lexer::lex_analyse() {
	while(next_token()) {
		*_log << "Lexer::lex_analyse() -> Token\n";
	}
	return _token;
}

bool Lexer::next_token() {
	if(!(_pos < _code.size()))
		return false;
	*_log << "Lexer::next_token() -> " <<"new call"<< '\n';
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
			*_log << "Lexer::next_token() -> " << tokype.second._name << '\n';
			return true;
		}
		
	}
	return true;
}

Lexer::~Lexer() {
	delete _log;
}
