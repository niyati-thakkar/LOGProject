#ifndef _STRING_
#define _STRING_

#include <iostream>
#include<cstring>
class String {
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string="", unsigned int n=0);
	String(const String& other);
	String(String&& other) noexcept;
	String& operator=(const String& other);
	String& operator=(String&& other) noexcept;
	~String();
	int getSize();
	friend String operator+(const String& some, const String& other);
	String substring(int start, int end);
	String substring(int start);
	char& operator[](unsigned int index);

	void print() {
		std::cout << m_Buffer;
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string) {
		stream << string.m_Buffer;
		return stream;
	}

	void append(const String& other);
};

#endif