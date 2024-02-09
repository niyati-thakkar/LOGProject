#ifndef _STRING_
#define _STRING_

#include <iostream>
#include<cstring>
class String {
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	String(const char* string="", unsigned long int n=0);
	String(const String& other) noexcept;
	String(String&& other) noexcept;
	String& operator=(const String& other) noexcept;
	String& operator=(String&& other) noexcept;
	~String();
	unsigned int getSize();
	friend String operator+(const String& some, const String& other) noexcept;
	bool operator==(const String& other) noexcept;
	bool operator!=(const String& other) noexcept;
	String& operator+=(const String& other) noexcept;
	String substring(int start, int end);
	String substring(int start);
	char& operator[](unsigned int index);
	static String to_string(int) noexcept;
	void print() noexcept{
		std::cout << m_Buffer;
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	void append(const String& other);
};

#endif