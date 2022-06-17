#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Define/Define.h"

extern int log_count = 0;

class Logger {
	std::ofstream _ofs;
public:
	Logger(std::string name, bool need_rewrite = true);

	template<typename T>
	std::ostream& operator<<(T what);

	~Logger();
};
#include "Logger.cpp"

