#include "Logger.h"

void Logger::_colontitle_head(std::ostream& out, time_t now = time(0)) {
	out << "Time start write in - " << std::ctime(&now);
	out << "----------------------------------------------\n";
	log_count++;
}

void Logger::_colontitle_foot(std::ostream& out, time_t now = time(0)) {
	out << "----------------------------------------------\n";
	out << "Time end write in   - " << std::ctime(&now);
	log_count--;
}

