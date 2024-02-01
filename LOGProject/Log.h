#ifndef _LOG_H
#define _LOG_H
#include "Date.h"
namespace Lognspace {
	class Log
	{
	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};
		
	private:
		Level m_LogLevel;
		Date storedDate;
		String dateRep;
	public:
		Log();
		void setLogLevel(Level level);
		void Warn(const char* message);
		void Error(const char* message);
		void Info(const char* message);
		void  updateDate();

	};
}
#endif