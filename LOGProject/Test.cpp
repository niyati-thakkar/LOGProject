#include<iostream>
#include "Log.h"
#include "String.h"

//int main()
//{
//	Lognspace::Log log;
//	log.setLogLevel(Lognspace::Log::Level::LevelError);
//	log.Info("Fine!");
//	log.Warn("Carefull!");
//	log.Error("Stop!");
//	std::cin.get();
//}

//int main() {
//	String string = "QickStep";
//	String second = std::move(string);
//	//string = "ksgfkdf";
//	String s3 = string + second;
//	std::cout << s3 << "\n";
//	String s4 = "fdhak";
//	s3 = s4 + s3;
//	std::cout << s3 << std::endl;
//	/*std::cout << second << std::endl;
//	String string1 = "QickStep";
//	String second2 = "Harishankar";
//	string1 = string1 + second2;
//	std::cout << string1 << std::endl;
//	std::cout << second2 << std::endl;
//	String s1 = "hello";
//	String s2 = "something";
//	s1 = s2.substring(1,2);
//	std::cout << s1;*/
//}
int main() {
	String string = "QickStep";
	String s2{ string };
	s2[2] = 'l';
	string = s2;
	std::cout << string << "\n";
	std::cout << s2 << "\n";
	s2 = "hiiieeee" + string;
	String second = std::move(string);
	std::cout << s2 << " \n";
	String s1{ "hello" };

	s2 = s1;
	String s3 = s1 + s2;
	std::cout << static_cast<void*>(nullptr) << std::endl;
	string = "ksgfkdf";
	s3 = string + second;
	std::cout << s3 << "\n";
	String s4 = "fdhak";
	s3 = s4 + s3;
	std::cout << s3 << std::endl;
	std::cout << second << std::endl;
	String string1 = "QickStep";
	String second2 = "Harishankar";
	string1 = string1 + second2;
	std::cout << string1 << std::endl;
	std::cout << second2 << std::endl;
	s1 = "hello";
	s2 = "something";
	s1 = s2.substring(1, 2);
	std::cout << s1;
	s1.append(s2);
	s2 = s2;
	String s10{ s10 };
	std::cout << s1;
}