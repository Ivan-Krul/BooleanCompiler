#pragma once
#include "../Logger.h"

class ConsoleLogger : public Logger {
public:
	void init(std::string name) override;

	template<typename T>
	void get(T what);

	void finit() override;
};
#include "ConsoleLogger.cpp"
