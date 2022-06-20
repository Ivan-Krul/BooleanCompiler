#pragma once
#include <string>
#include "Type/Type.h"

class Token {
public:
	Type _type;
	std::string _text;
	size_t _pos;

	Token(Type type, std::string text, size_t pos);
};
#include "Token.cpp"
