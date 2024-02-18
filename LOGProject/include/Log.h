#ifndef _LOG_H
#define _LOG_H
#include "Date.h"
#include "String.h"

namespace Lognspace {
	class Log
	{
	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};
		
	private:
		Level m_LogLevel;
		Date::Date stored_date;
		String date_rep;
		String buffer;
		String default_message;

	public:
		Log();
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
		void check_date();
		bool print_to_file();
		bool load_it(String colored_message);

	};
}
template<typename ...eles>
void Lognspace::Log::Warn(eles ...messages)
{
	check_date();
	if (m_LogLevel >= Level::LevelWarning) {
		default_message = "[Warming]:";
		build_buffer(messages...);
		load_it("\033[33m[Warning]:\033[0m");
	}
		
}
template<typename ...eles>
void Lognspace::Log::Error(eles ...messages)
{
	check_date();
	if (m_LogLevel >= Level::LevelError){
		default_message = "[Error]:";
		build_buffer(messages...);
		load_it("\033[31m[Error]:\033[0m");
	}
}
template<typename ...eles>
void Lognspace::Log::Info(eles ...messages)
{
	check_date();
	if (m_LogLevel >= Level::LevelInfo){
		default_message = "[Info]:";
		build_buffer(messages...);
		load_it("\033[32m[Info]:\033[0m");

	}
}
template<typename T, typename ...eles>
void Lognspace::Log::build_buffer(T first, eles... elements) {
	//std::cout << __FUNCSIG__ << " ";
	buffer = buffer + String::to_string(first) + " ";
	build_buffer(elements...);
}
#endif