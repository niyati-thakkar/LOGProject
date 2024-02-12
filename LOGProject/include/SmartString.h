
#ifndef _SMARTSTRING_
#define _SMARTSTRING_

#include <iostream>
#include<cstring>
class SmartString {
private:
	std::shared_ptr<char> m_Buffer;
	unsigned int m_Size;
public:
	SmartString(const char* string = "", unsigned long int n = 0);
	SmartString(const SmartString& other) noexcept;
	SmartString(SmartString&& other) noexcept;
	SmartString& operator=(const SmartString& other) noexcept;
	SmartString& operator=(SmartString&& other) noexcept;
	unsigned int getSize();
	friend SmartString operator+(const SmartString& some, const SmartString& other) noexcept;
	bool operator==(const SmartString& other) noexcept;
	bool operator!=(const SmartString& other) noexcept;
	SmartString& operator+=(const SmartString& other) noexcept;
	SmartString substring(int start, int end);
	SmartString substring(int start);
	char& operator[](unsigned int index);
	static SmartString to_string(int) noexcept;
	void print() noexcept {
		std::cout << m_Buffer;
	}

	friend std::ostream& operator<<(std::ostream& stream, const SmartString& string);

	void append(const SmartString& other);
};

#endif