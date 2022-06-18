#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Define/Define.h"

extern int log_count = 0;

class Logger {
protected:
	std::ostream* _out;
	void _colontitle_head(std::ostream& out, time_t now);
	void _colontitle_foot(std::ostream& what, time_t now);
public:
	virtual void init() = 0;
	virtual void finit() = 0;
};
#include "Logger.cpp"

