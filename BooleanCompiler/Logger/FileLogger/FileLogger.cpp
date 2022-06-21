#include "FileLogger.h"

void FileLogger::init(std::string name) {
	_ofs.open(name+ ".log");
	_colontitle_head(_ofs);
}

template<typename T>
void FileLogger::get(T what) {
	#ifdef LOG_DELAY
	std::this_thread::sleep_for(LOG_DELAY);
	#endif
	_ofs << what;
}

void FileLogger::finit() {
	_colontitle_foot(_ofs);
	_ofs.close();
}

FileLogger::~FileLogger() {
	finit();
}
