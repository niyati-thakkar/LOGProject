#include<iostream>
#include "Log.h"
int main()
{
	Log log;
	log.SetLogLevel(Log::LevelError);
	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");
	std::cin.get();
}