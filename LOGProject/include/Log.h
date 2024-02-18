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
		Date::Date storedDate;
		String dateRep;
		String buffer;

	public:
		Log();
		void setLogLevel(Level level);
		template<typename ...eles>
		void Warn(eles...);
		template<typename ...eles>
		void Error(eles...);
		template<typename ...eles>
		void Info(eles...); 
		template<typename T, typename ...eles>
		void print(T, eles...);
		void print();
		void  checkDate();
		bool printToFile();

	};
}
template<typename ...eles>
void Lognspace::Log::Warn(eles ...messages)
{
	checkDate();
	if (m_LogLevel >= Level::LevelWarning)
		print(dateRep, "[Warning]:", messages...);
}
template<typename ...eles>
void Lognspace::Log::Error(eles ...messages)
{
	checkDate();
	if (m_LogLevel >= Level::LevelError)
		print(dateRep, "[Error]:", messages...);
}
template<typename ...eles>
void Lognspace::Log::Info(eles ...messages)
{
	checkDate();
	if (m_LogLevel >= Level::LevelInfo)
		print(dateRep, "[Info]:", messages...);
}
template<typename T, typename ...eles>
void Lognspace::Log::print(T first, eles... elements) {
	//std::cout << __FUNCSIG__ << " ";
	buffer =buffer + String::to_string(first) + " ";
	print(elements...);
}
#endif