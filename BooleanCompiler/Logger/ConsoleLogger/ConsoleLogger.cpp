#include "ConsoleLogger.h"

void ConsoleLogger::init(std::string name) {
	_colontitle_head(std::clog);
}

template<typename T>
void ConsoleLogger::get(T what) {
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(50ms);
	std::clog << what;
}

void ConsoleLogger::finit() {
	_colontitle_foot(std::clog);
}

ConsoleLogger::~ConsoleLogger() {
	finit();
}
