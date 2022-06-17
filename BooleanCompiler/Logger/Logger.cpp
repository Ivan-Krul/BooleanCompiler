#include "Logger.h"

Logger::Logger(std::string name, bool need_rewrite) {

	time_t now = std::time(0);
	std::string title_time = ctime(&now);
	for(size_t i = 0; i < title_time.size(); i++)
		if(title_time[i] == ':' || title_time[i] == ' ' || title_time[i] == '\n')
			title_time.erase(i, 1);

	_ofs.open((need_rewrite ? "" : title_time + " ") + name + " #" + std::to_string(log_count) + ".log");
	_ofs << "Time start write in - " << std::ctime(&now);
	_ofs << "----------------------------------------------\n";
	log_count++;
}

Logger::~Logger() {
	time_t now = std::time(0);

	_ofs << "----------------------------------------------\n";
	_ofs << "Time end write in   - " << std::ctime(&now);
	_ofs.close();
	log_count--;
}

template<typename T>
std::ostream& Logger::operator<<(T what) {
	_ofs << what;
	return _ofs;
}

