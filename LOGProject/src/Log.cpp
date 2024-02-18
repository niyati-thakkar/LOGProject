#include <fstream>
#include "../include/Log.h"
void  Lognspace::Log::check_date() {
	Date::Date curDate{ Date::Date::currentDate() };
	//std::cout << curDate.getStringRep();
	if (Log::stored_date != curDate) {
		date_rep = curDate.getStringRep();
	}
}

Lognspace::Log::Log() : m_LogLevel{ Level::LevelInfo }, stored_date{ 1,1,2024 }
{
	check_date();
}

void Lognspace::Log::set_log_level(Log::Level level)
{
	m_LogLevel = level;
}
void Lognspace::Log::build_buffer() {
	buffer += "\n";
}
bool Lognspace::Log::print_to_file() {
	std::ofstream outf{ "Sample.txt", std::ios::app };
	// If we couldn't open the output file stream for writing
	if (!outf)
	{
		// Print an error and exit
		std::cerr << "Uh oh, Sample.txt could not be opened for writing!\n";
		return 0;
	}
	// We'll write two lines into this file
	outf << date_rep << default_message << buffer;
	return 1;
	// When outf goes out of scope, the ofstream
	// destructor will close the file
}
bool Lognspace::Log::load_it(String colored_message) {
	std::cout << date_rep << " " << colored_message << buffer;
	print_to_file();
	buffer = "";
	return 1;
}