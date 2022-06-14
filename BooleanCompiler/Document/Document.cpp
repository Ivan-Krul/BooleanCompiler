#include "Document.h"

void Document::write(std::string dir) {
	std::ifstream ifs;
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
		std::clog << log << "Document::write(std::string dir) -> string is writed";
	}

	ifs.close();
}

size_t Document::size() {
	return _code.size();
}

Document& Document::operator=(Document& doc) {
	_code = doc._code;
	return doc;
}
