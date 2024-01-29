#ifndef _LOG_H
#define _LOG_H

namespace Lognspace {
	class Log
	{
	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};
		
	private:
		Level m_LogLevel;
	public:
		Log() {
			m_LogLevel = Level::LevelInfo;
		}

		inline void SetLogLevel(Level level)
		{
			m_LogLevel = level;
		}
		inline void Warn(const char* message)
		{
			if (m_LogLevel >= Level::LevelWarning)
				std::cout << "[Warning]: " << message << std::endl;
		}
		inline void Error(const char* message)
		{
			if (m_LogLevel >= Level::LevelError)
				std::cout << "[Error]: " << message << std::endl;
		}
		inline void Info(const char* message)
		{
			if (m_LogLevel >= Level::LevelInfo)
				std::cout << "[Info]: " << message << std::endl;
		}
	};
}
using namespace Lognspace;
#endif