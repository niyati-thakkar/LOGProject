#ifndef _STRING_
#define _STRING_

#include <iostream>
#include<cstring>
class String {
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string="", int n=0);
	String(const String& other);
	String& operator=(const String& other);
	String operator+(const String& other);
	~String();
	char& operator[](unsigned int index);
	friend std::ostream& operator<<(std::ostream& stream, const String&
		string);
};
#endif