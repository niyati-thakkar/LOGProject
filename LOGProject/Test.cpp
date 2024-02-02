#include<iostream>
#include "Log.h"
#include "String.h"

int main()
{
	Lognspace::Log log;
	log.setLogLevel(Lognspace::Log::Level::LevelError);
	log.Info("Fine!");
	log.Warn("Carefull!");
	log.Error("Stop!");
	std::cin.get();
}
//int main() {
//	/*String string = "QickStep";
//	String second = string;
//	string[2] = 'u';
//	std::cout << string << std::endl;
//	std::cout << second << std::endl;
//	String string1 = "QickStep";
//	String second2 = "Harishankar";
//	string1 = string1 + second2;
//	std::cout << string1 << std::endl;
//	std::cout << second2 << std::endl;*/
//	String s1 = "hello";
//	String s2 = "something";
//	s2.append(s1);
//	std::cout << s2;
//}