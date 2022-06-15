#include "Document.h"

void Document::write(std::string dir) {
	std::ifstream ifs;
	_code = "";
	ifs.open(dir);

	if(!ifs.is_open()) {
		std::cerr << err << "Document::write(std::string dir) -> file isn't open\n";
		return;
	}
	if(ifs.fail()) {
		std::cerr << err << "Document::write(std::string dir) -> file is failed\n";
		return;
	}

	std::string str;
	while(ifs) {
		std::getline(ifs, str);
		_code += str; 
		_code += '\n';
		std::clog << log << "Document::write(std::string dir) -> string is writed\n";
		_strings++;
	}

	ifs.close();
}

std::string Document::get_code() {
	return _code;
}

size_t Document::size() {
	return _code.size();
}

size_t Document::strings() {
	return _strings;
}

Document& Document::operator=(Document& doc) {
	_code = doc._code;
	return doc;
}
