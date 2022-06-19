#include "Document.h"

Document::Document() {
	mainlog.get("Document -> starting up\n");
}

void Document::write(std::string dir) {
	std::ifstream ifs;
	_code = "";
	ifs.open(dir);

	if(!ifs.is_open()) {
		mainlog.get("Document::write(std::string dir) -> file isn't open\n");
		return;
	}
	if(ifs.fail()) {
		mainlog.get("Document::write(std::string dir) -> file is failed\n");
		return;
	}

	std::string str;
	while(ifs) {
		std::getline(ifs, str);
		_code += str; 
		_code += '\n';
		mainlog.get("Document::write(std::string dir) -> string is writed\n");
		_strings++;
	}

	ifs.close();
}

std::string Document::get_code() {
	return _code;
}

void Document::set_code(std::string what) {
	mainlog.get("Document::set_code(std::string what) -> reset _code\n");
	_code = what;
}

size_t Document::size() {
	return _code.size();
}

size_t Document::strings() {
	return _strings;
}

Document& Document::operator=(Document& doc) {
	mainlog.get("Document::operator=(Document& doc) -> copying\n");
	_code = doc._code;
	return doc;
}

Document::~Document() {
	mainlog.get("Document -> ending up\n");
}
