#pragma once
#include "../Logger.h"

class FileLogger : public Logger {
	std::ofstream _ofs;
public:
	void init(std::string name);

	template<typename T>
	void get(T what);

	void finit() override;
	~FileLogger();
};
#include "FileLogger.cpp"

