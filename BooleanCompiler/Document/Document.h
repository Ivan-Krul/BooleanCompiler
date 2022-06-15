#pragma once
#include <fstream>
#include <string>
#include <list>
#include "../Logger/Logger.h"

class Document {
	std::string _code;
	size_t _strings = 0;

public:
	void write(std::string dir);
	std::string get_code();
	size_t size();
	size_t strings();
	Document& operator=(Document& doc);
};
#include "Document.cpp"
