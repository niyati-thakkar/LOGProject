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
		Date storedDate;
		String dateRep;
	public:
		Log();
		void setLogLevel(Level level);
		void Warn(String message);
		void Error(String message);
		void Info(String message);
		void  updateDate();

	};
}
#endif