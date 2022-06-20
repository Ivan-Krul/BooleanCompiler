#include "FileLogger.h"

void FileLogger::init(std::string name) {
	_ofs.open(name+ ".log");
	_colontitle_head(_ofs);
}

template<typename T>
void FileLogger::get(T what) {
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(50ms);
	_ofs << what;
}

void FileLogger::finit() {
	_colontitle_foot(_ofs);
	_ofs.close();
}

FileLogger::~FileLogger() {
	finit();
}
