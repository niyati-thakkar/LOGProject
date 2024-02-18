#ifndef _STRING_
#define _STRING_

#include <iostream>
#include<cstring>
class String {
private:
	char* m_Buffer;
	size_t m_Size=0;
public:
	String(const char* string="");
	String(const String& other) noexcept;
	String(String&& other) noexcept;
	String& operator=(const String& other) noexcept;
	String& operator=(String&& other) noexcept;
	~String();
	size_t getSize();
	friend String operator+(const String& some, const String& other) noexcept;
	bool operator==(const String& other) noexcept;
	bool operator!=(const String& other) noexcept;
	String& operator+=(const String& other) noexcept;
	String substring(size_t start, size_t end);
	String substring(size_t start);
	char& operator[](size_t index);
	static String to_string(int) noexcept;
	static String to_string(const String& s);
	static String to_string(char s);
	void print() noexcept{
		std::cout << m_Buffer;
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);

	void append(const String& other);
	
};

#endif