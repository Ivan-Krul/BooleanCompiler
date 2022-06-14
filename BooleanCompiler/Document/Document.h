#pragma once
#include <fstream>
#include <string>
#include <list>

class Document {
	std::string _code;

public:
	void write(std::string dir);
	std::string get_code();
	size_t size();
	Document& operator=(Document& doc);
};
#include "Document.cpp"
