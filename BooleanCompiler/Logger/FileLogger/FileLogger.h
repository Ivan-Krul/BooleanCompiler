#pragma once
#include "../Logger.h"

class FileLogger : public Logger {
	std::ofstream _ofs;
public:
	init(std::string name, bool need_rewrite = true);

	template<typename T>
	std::ostream& operator<<(T what);

	~FileLogger();
};
