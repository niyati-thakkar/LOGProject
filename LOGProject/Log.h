#ifndef _LOG_H
#define _LOG_H
#endif
struct Log
{
public:
	enum Level {
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level m_LogLevel = LevelInfo;
public:
	void SetLogLevel(Level level)
	{
		m_LogLevel = level;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[Warning]: " << message << std::endl;
	}
	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[Error]: " << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[Info]: " << message << std::endl;
	}
};