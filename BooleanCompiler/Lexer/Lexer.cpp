#include "Lexer.h"

size_t Lexer::_find_similar(std::string& a, std::string& b) {
	size_t count = 0;

	for(size_t j = 0; j < std::min(a.size(),b.size()); j++) {
		if(a[j] == b[j])
			count++;
	}

	return count;
}

void Lexer::_write_token_in_log(Token& tok) {
	mainlog.get("Lexer::next_token() -> ");
	mainlog.get(tok._type._name);
	mainlog.get('\n');
}

Lexer::Lexer(Document& code) {
	mainlog.get("Lexer -> starting up\n");
	_code = code;
}

std::list<Token> Lexer::lex_analyse() {
	while(next_token()) {
		//mainlog.get("Lexer::lex_analyse() -> next token\n");
	}
	return _token;
}

bool Lexer::next_token() {
	if(!(_pos < _code.size()))
		return false;

	auto& result = _code.get_code();
	auto tokentypeval = TypeList;
	for(size_t i = 0; i < TypeListLen; i++) {
		auto& tokype = tokentypeval[i];
		if(_is_comment && tokype.first != "ENDBIGCOMMENT") continue;

		auto& regex = tokype.second._regex;
		auto size = regex.size();

		if(!result.empty()) {
			std::string s;
			s = result.substr(_pos, size);
			if(_find_similar(regex, s) == size) {
				if(tokype.first == "BEGBIGCOMMENT") {
					_is_comment = true;

					Type type = tokype.second;
					Token token(type, regex, _pos);
					_token.push_back(token);

					_write_token_in_log(token);

					_pos += regex.length();
				}
				else if(tokype.first == "ENDBIGCOMMENT") {
					_is_comment = false;
					_pos += regex.length();
				}

				if(!_is_comment) {
					_pos += regex.length();
					Type type = tokype.second;
					Token token(type, regex, _pos);

					_token.push_back(token);

					if(regex == "\n") _line++;

					_write_token_in_log(token);

					return true;
				}
			}
		}
		
	}
	if(!_is_comment) {
		{
			auto tokenvarval = AlphabetVar;
			for(size_t i = 0; i < AlphabetVarLen; i++) {
				auto& varype = tokenvarval[i];
				auto& regex = varype.second._regex;
				auto size = regex.size();

				if(!result.empty()) {
					if(regex[0] == result[_pos]) {
						Type type = varype.second;
						Token token(type, regex, _pos);
						_pos += regex.length();
						_token.push_back(token);

						_write_token_in_log(token);
						return true;
					}
				}

			}
		}
		{
			auto tokennumval = NumberVar;
			for(size_t i = 0; i < NumberVarLen; i++) {
				auto& varype = tokennumval[i];
				auto& regex = varype.second._regex;
				auto size = regex.size();

				if(!result.empty()) {
					if(regex[0] == result[_pos]) {
						Type type = varype.second;
						Token token(type, regex, _pos);
						_pos += regex.length();
						_token.push_back(token);

						_write_token_in_log(token);
						return true;
					}
				}

			}
		}

		mainlog.get("On position ");
		mainlog.get(_pos);
		mainlog.get(" was detected error on line ");
		mainlog.get(_line);
		mainlog.get("\n");
		std::clog << '\a';
		return false;
	}
	else {
		if(result[_pos] == '\n') _line++;
		_pos++;
		return true;
	}

}

Lexer::~Lexer() {
	mainlog.get("Lexer -> ending up\n");
}
