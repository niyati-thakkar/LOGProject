#ifndef _LOG_H
#define _LOG_H
//#include "Date.h"
//#include "String.h"
#include<string>
#include <chrono>
#include <string_view>
#include <unordered_map>
#include<functional>
#include<array>
namespace Lognspace {
	class registry {
		friend class Log;
	public:
		static registry& get_instance() {
			static registry instance;
			return instance;
		}
	private:
		std::unordered_map<unsigned int,std::shared_ptr<Log>> logger_objects;
	};
	class Log
	{
	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};
		
	private:
		int ID;
		Level m_LogLevel;
		std::string buffer;
		std::string file_path;
		bool printToFile;
		

	public:
		inline static std::vector<std::pair<std::string, std::string>> default_message = {
				std::pair<std::string,std::string>{"[Warming]","\033[33m[Warning]:\033[0m"},
				std::pair<std::string,std::string>{"[Error]:","\033[31m[Error]:\033[0m"},
				std::pair<std::string,std::string>{"[Info]:","\033[32m[Info]:\033[0m"}
		};
		Log(Level level = Level::LevelInfo, std::string filep = "", bool to_file = false);
		void set_log_level(Level level);
		template<typename ...eles>
		void Warn(eles...);
		template<typename ...eles>
		void Error(eles...);
		template<typename ...eles>
		void Info(eles...); 
		template<typename T, typename ...eles>
		void build_buffer(T, eles...);
		void build_buffer();
		std::string getDateTime();
		static unsigned int get_id();
		void log_it(int i);
		~Log();
	};
}
template<typename ...eles>
void Lognspace::Log::Warn(eles ...messages)
{
	if (m_LogLevel >= Level::LevelWarning) {
		build_buffer(messages...);
		log_it(1);
	}
		
}
template<typename ...eles>
void Lognspace::Log::Error(eles ...messages)
{
	if (m_LogLevel >= Level::LevelError){
		build_buffer(messages...);
		log_it(2);
	}
}
template<typename ...eles>
void Lognspace::Log::Info(eles ...messages)
{
	if (m_LogLevel >= Level::LevelInfo){
		build_buffer(messages...);
		log_it(0);
	}
}
template<typename T, typename ...eles>
void Lognspace::Log::build_buffer(T first, eles... elements) {
	//std::cout << __FUNCSIG__ << " ";
	buffer = buffer + first + " ";
	build_buffer(elements...);
}

#endif