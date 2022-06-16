#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Define/Define.h"

class Logger {
	static size_t count;
	std::ofstream _ofs;
	bool _need_title;
public:
	Logger(std::string name, bool need_title = false) {
		_need_title = need_title;

		time_t now = std::time(0);
		std::string title_time = ctime(&now);
		for(size_t i = 0; i < title_time.size(); i++)
			if(title_time[i] == ':' || title_time[i] == ' ' || title_time[i] == '\n')
				title_time.erase(i, 1);

		_ofs.open(title_time +" "+name + " #" + std::to_string(count) + ".log");
		_ofs << "Time start write in - " << std::ctime(&now);
		_ofs << "----------------------------------------------\n";
		if(_need_title) {
			#ifdef OUT_LOG_IN_CONSOLE
			std::clog << "Time start write in - " << std::ctime(&now);
			std::clog << "----------------------------------------------\n";
			#endif
		}
		count++;
	}

	
	std::ostream& operator<<(std::string what) {
		_ofs << what;
		#ifdef OUT_LOG_IN_CONSOLE
		std::clog << what;
		#endif
		return _ofs;
	}
	std::ostream& operator<<(int what) {
		_ofs << what;
		#ifdef OUT_LOG_IN_CONSOLE
		std::clog << what;
		#endif
		return _ofs;
	}
	std::ostream& operator<<(char what) {
		_ofs << what;
		#ifdef OUT_LOG_IN_CONSOLE
		std::clog << what;
		#endif
		return _ofs;
	}
	std::ostream& operator<<(float what) {
		_ofs << what;
		#ifdef OUT_LOG_IN_CONSOLE
		std::clog << what;
		#endif
		return _ofs;
	}
	std::ostream& operator<<(size_t what) {
		_ofs << what;
		#ifdef OUT_LOG_IN_CONSOLE
		std::clog << what;
		#endif
		return _ofs;
	}
	std::ostream& operator<<(long long what) {
		_ofs << what;
		#ifdef OUT_LOG_IN_CONSOLE
		std::clog << what;
		#endif
		return _ofs;
	}

	~Logger() {
		time_t now = std::time(0);

		_ofs << "----------------------------------------------\n";
		_ofs << "Time end write in   - " << std::ctime(&now);
		if(_need_title) {
			#ifdef OUT_LOG_IN_CONSOLE
			std::clog << "----------------------------------------------\n";
			std::clog << "Time end write in   - " << std::ctime(&now);
			#endif
		}
		_ofs.close();
		count--;
	}
};
