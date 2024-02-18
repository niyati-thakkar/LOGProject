#include <fstream>
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
	buffer += "\n";
	printToFile();
	std::cout << buffer;
	buffer = "";
}
bool Lognspace::Log::printToFile() {
	std::ofstream outf{ "Sample.txt", std::ios::app };
	// If we couldn't open the output file stream for writing
	if (!outf)
	{
		// Print an error and exit
		std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
		return 0;
	}
	// We'll write two lines into this file
	outf << buffer;
	return 1;
	// When outf goes out of scope, the ofstream
	// destructor will close the file
}