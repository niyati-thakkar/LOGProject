#include "../include/Log.h"
void  Lognspace::Log::checkDate() {
	Date::Date curDate{ Date::Date::currentDate() };
	//std::cout << curDate.getStringRep();
	if (Log::storedDate != curDate) {
		dateRep = curDate.getStringRep();
	}
}

Lognspace::Log::Log() : m_LogLevel{ Level::LevelInfo }, storedDate{ 1,1,2024 }
{
	checkDate();
}

void Lognspace::Log::setLogLevel(Log::Level level)
{
	m_LogLevel = level;
}
void Lognspace::Log::print() {
	std::cout << std::endl;
}