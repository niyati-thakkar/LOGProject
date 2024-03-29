#include <fstream>
#include<iostream>
//#include <iomanip>
#include<chrono>
//#include<put_time>
#include <format>
#include "../include/Log.h"

namespace Lognspace {
	Log::Log(Level level, std::string filep, bool to_file) : m_LogLevel{ level }, buffer{ NULL }, file_path{ filep }, printToFile{ to_file }
	{
		ID = get_id();
		registry r = registry::get_instance();
		if (to_file && filep.length() == 0) {
			file_path = "Logging" + (ID / 100);
		}
		else if (filep.length() > 0) {
			printToFile = true;
		}
		auto ptr = std::make_shared<Log>(*this);
		r.logger_objects[ID] = ptr;
	}

	


	Log::~Log() {
		registry r = registry::get_instance();
		r.logger_objects.erase(ID);
	}


	unsigned int Log::Log::get_id() {
		if(((RAND_MAX + 1u) / 1000000) != 0)
			return 1 + std::rand() / ((RAND_MAX + 1u) / 1000000);
		return -1;
	}

	void Log::set_log_level(Log::Level level)
	{
		m_LogLevel = level;
	}


	void Log::build_buffer() {
	}


	void Log::log_it(int i) {
		std::string date = getDateTime();
		//std::string message = default_message[i].first;
		std::cout << date << " " << default_message[i].second << " " << buffer << "\n";
		if (printToFile) {
			std::ofstream outf{ file_path, std::ios::app };
			if (!outf)
			{
				std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
			}
			outf << date << " " << default_message[i].first << " " << buffer << "\n";
		}
		buffer = "";

	}

	std::string Log::getDateTime() {
		auto _Time = std::chrono::system_clock::now();
		const auto time_tt = std::chrono::system_clock::to_time_t(_Time);
		std::tm tm;
		localtime_s(&tm, &time_tt);
		char date_buf[26];
		std::strftime(date_buf, sizeof(date_buf), "%d-%m-%Y %H:%M:%S", &tm);
		return date_buf;
	}
}