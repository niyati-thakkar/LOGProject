#include<iostream>
#include "../include/Log.h"
#include "../include/SmartString.h"
#include "../include/LinkedList.h"
int main()
{
	Lognspace::Log log;
	log.setLogLevel(Lognspace::Log::Level::LevelError);
	log.Info("Fine!", "Okay", "Doing Good");
	log.Warn("Carefull!");
	log.Error("Stop!", "Can do better", "Cheer Up", "Error:", -342, 'd');
	std::cin.get();
}

//int main() {
//	String string = "QickStep";
//	String second = std::move(string);
//	//string = "ksgfkdf";
//	String s3 = string + second;
//	std::cout << s3 << "\n";
//	String s4 = "fdhak";
//	s3 = s4 + s3;
//	std::cout << s3 << std::endl;
//	std::cout << second << std::endl;
//	String string1 = "QickStep";
//	String second2 = "Harishankar";
//	string1 = string1 + second2;
//	std::cout << string1 << std::endl;
//	std::cout << second2 << std::endl;
//	String s1 = "hello";
//	String s2 = "something";
//	s1 = s2.substring(1,2);
//	std::cout << s1;
//}
//#include<limits>
//SmartString func(SmartString s) {
//	std::cout << s << "\n";
//	return s;
//}
//int main() {
//	SmartString string = "QickStep";
//	SmartString s2{ string };
//	s2[2] = 'l';
//	string = s2;
//	std::cout << string << "\n";
//	std::cout << s2 << "\n";
//	s2 = "hiiieeee" + string;
//	SmartString second = std::move(string);
//	std::cout << s2 << " \n";
//	SmartString s1{ "hello" };
//	std::cout << "okay1 \n";
//	try {
//		std::cout << "okay2 \n";
//		SmartString s4{"k"};
//		s4[4];
//		//Date d{ 5,43,3243 };
//	}
//	catch (std::runtime_error& e) {
//		std::cout << "okay3 \n";
//		std::cout << e.what();
//	}
//	s2 = s1;
//	SmartString s3 = s1 + s2;
//	std::cout << static_cast<void*>(nullptr) << std::endl;
//	string = "ksgfkdf";
//	s3 = string + second;
//	std::cout << s3 << "\n";
//	SmartString s4 = "fdhak";
//	s3 = s4 + s3;
//	std::cout << s3 << std::endl;
//	std::cout << second << std::endl;
//	SmartString string1 = "QickStep";
//	SmartString second2 = "Harishankar";
//	string1 = string1 + second2;
//	std::cout << string1 << std::endl;
//	std::cout << second2 << std::endl;
//	s1 = "hello";
//	s2 = "hello";
//	std::cout << (s1 == s2)<<"hii\n";
//	s1 = s2.substring(1, 2);
//	std::cout << s1;
//	s1.append(s2);
//	s2 = s2;
//	SmartString s10{ "jiojlj"};
//	std::cout << s1;
//	SmartString s11 = func(s10);
//	std::cout << s11 << "\n";
//}
//int main() {
//    LinkedList<int> ll;
//    ll.push_front(9);
//    ll.push_front(7);
//    ll.push_back(18);
//    ll.push_back(13);
//    ll.push_back(534);
//    ll.push_front(543);
//    ll.push_front(43);
//    ll.insert_at(2, 34);
//    //std::cout << ll;
//    ll.delete_at(3);
//    // ll.reverse();
//    ll.print();
//    try {
//        std::cout << ll[65];
//    }
//    catch (std::runtime_error& e) {
//        //std::cout << "okay3 \n";
//        std::cout << e.what();
//    }
//     std::cout << ll[1];
//}
//int main() {
//	// generic linkedlist
//	LinkedList<String> ll;
//	ll.push_back("hello");
//	ll.push_front("hii");
//	ll.insert_at(1, "greetings");
//	ll.print();
//	ll.pop_back();
//	ll.push_back("good morning");
//	ll.pop_front();
//	ll.print();
//
//
//}
//int main() {
//	SmartString s = "hello";
//	SmartString* t1 = &s;
//	SmartString* t2 = t1;
//	std::cout << *t2;
//
//}