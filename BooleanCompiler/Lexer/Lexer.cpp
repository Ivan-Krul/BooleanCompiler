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
		auto& tokype = tokentypeval[i];
		auto& regex = tokype.second._regex;
		auto& result = _code.get_code();
		auto size = regex.size();
		
		if(!result.empty()) {
			size_t count = 0;

			for(size_t j = 0; j < size; j++) {
				if(regex[j] == result[_pos + j])
					count++;
			}

			if(count == size) {
				_pos += regex.length();

				if(!_is_comment && tokype.first == "BEGCOMMENT")
					_is_comment = true;
				if(_is_comment && tokype.first == "ENDCOMMENT")
					_is_comment = false;

				if(!_is_comment) {
					Type type = tokype.second;
					Token token(type, regex, _pos);

					_token.push_back(token);

					mainlog.get("Lexer::next_token() -> ");
					mainlog.get(tokype.second._name);
					mainlog.get('\n');

					return true;
				}
			}
		}
		
	}
	if(!_is_comment) {
		auto tokenvarval = AlphabetVar;
		for(size_t i = 0; i < AlphabetVarLen; i++) {
			auto& varype = tokenvarval[i];
			auto& regex = varype.second._regex;
			auto& result = _code.get_code();
			auto size = regex.size();

			if(!result.empty()) {
				if(regex[0] == result[_pos]) {
					Type type = varype.second;
					Token token(type, regex, _pos);
					_pos += regex.length();
					_token.push_back(token);

					mainlog.get("Lexer::next_token() -> ");
					mainlog.get(varype.second._name);
					mainlog.get('\n');
					return true;
				}
			}

		}

		mainlog.get("On position ");
		mainlog.get(_pos);
		mainlog.get(" was detected error\n");
		std::clog << '\a';
		return false;
	}

}

Lexer::~Lexer() {
	mainlog.get("Lexer -> ending up\n");
}
