#pragma once
#include <string>
#include <list>
#include "Type/Type.h"

const std::pair<std::string, Type> TypeList[] = {
	{"BOOL",{"BOOL","bool"}},
	{"VARIABLE",{"VARIABLE","[a-z]*"}},
	{"SEMICOLON",{"SEMICOLON",";"}},
	{"SPACE",{"SPACE","\t\n\r "}},
	{"TRUE",{"TRUE","true"}},
	{"FALSE",{"FALSE","false"}},
	{"ASSIGN",{"ASSIGN","="}},
	{"INPUT",{"INPUT","in"}},
	{"OUTPUT",{"OUTPUT","out"}},
	{"INJECTIN",{"INJECTIN","<"}},
	{"INJECTOUT",{"INJECTOUT","<"}},
	{"AND",{"AND","and"}},
	{"OR",{"OR","or"}},
	{"NOT",{"NOT","not"}},
	{"LPAR",{"LPAR","{"}},
	{"RPAR",{"RPAR","}"}}
};

static size_t TypeListLen = std::size(TypeList);

struct Token {
	Type _type;
	std::string _text;
	size_t _pos;

	Token(Type type, std::string text, size_t pos);
};
#include "Token.cpp"
