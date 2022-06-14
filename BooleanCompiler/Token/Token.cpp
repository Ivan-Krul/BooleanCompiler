#include "Token.h"

Token::Token(Type type, std::string text, size_t pos) {
	_type = type;
	_text = text;
	_pos = pos;
}
