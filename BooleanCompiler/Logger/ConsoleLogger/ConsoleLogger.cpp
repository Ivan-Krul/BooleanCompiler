#include "ConsoleLogger.h"

void ConsoleLogger::init(std::string name) {
	_colontitle_head(std::clog);
}

template<typename T>
void ConsoleLogger::get(T what) {
	std::clog << what;
}

void ConsoleLogger::finit() {
	_colontitle_foot(std::clog);
}
