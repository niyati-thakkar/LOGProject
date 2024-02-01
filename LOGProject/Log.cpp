//#include <iostream>
//namespace nspace {
//	
//}

#include "Log.h"


void  Lognspace::Log::updateDate() {
	Date curDate{ Date::currentDate() };
	//std::cout << curDate.getStringRep();
	if (Log::storedDate != curDate) {
		dateRep = curDate.getStringRep();
	}
	
}
Lognspace::Log::Log() : m_LogLevel{ Level::LevelInfo }, storedDate{ 1,1,2024 }
{
	updateDate();
}

void Lognspace::Log::setLogLevel(Log::Level level)
{
	m_LogLevel = level;
}
void Lognspace::Log::Warn(const char* message)
{
	updateDate();
	if (m_LogLevel >= Level::LevelWarning)
		std::cout << "[Warning]: " << message << " " << dateRep << " " << std::endl;
}
void Lognspace::Log::Error(const char* message)
{
	updateDate();
	if (m_LogLevel >= Level::LevelError)
		std::cout << "[Error]: " << message << " " << dateRep << " " << std::endl;
}
void Lognspace::Log::Info(const char* message)
{
	updateDate();
	if (m_LogLevel >= Level::LevelInfo)
		std::cout << "[Info]: " << message << " " << dateRep << " " << std::endl;
}