#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "../Define/Define.h"

struct Logger {
	std::ofstream ofs;

	Logger(std::string name) {
		time_t now = std::time(0);
		std::string title_time = ctime(&now);
		for(size_t i = 0; i < title_time.size(); i++) {
			if(title_time[i] == ':' || title_time[i] == ' ' || title_time[i] == '\n')
				title_time.erase(i, 1);
		}
		ofs.open(name + " " + title_time + ".log");
		ofs << "Time start write in - " << std::ctime(&now);
		ofs << "----------------------------------------\n";
		std::clog << log << "Logger::Logger(std::string name) -> done\n";
	}

	void operator<<(std::string what) {
		ofs << what << '\n';
	}
	~Logger() {
		time_t now = std::time(0);

		ofs << "----------------------------------------\n";
		ofs << "Time end write in   - " << std::ctime(&now);
		ofs.close();

		std::clog << log << "Logger::~Logger() -> done\n";
	}
};
