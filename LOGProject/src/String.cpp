#include <cstring>
#include <iostream>
#include <ostream>
#include <limits>
#include "../include/String.h"
#include "../include/Exceptions.h"

unsigned int String::getSize() {
    return m_Size;
}

String::String(const char* string, unsigned long int n) {
    std::cout << "default constructor 1" << "\n";
    if (n < 0 || n > std::numeric_limits<int>::max()) throw Exception::Overflow{};
    m_Size = strlen(string);
    if (n != 0) m_Size = n > m_Size? n : m_Size;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, string, m_Size);
    m_Buffer[m_Size] = 0;
}

String::String(const String& other) noexcept{
    if (&other != this) {
        std::cout << "default constructor 2 with string" << "\n";
        m_Size = other.m_Size;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }
}

String& String::operator=(const String& other) noexcept{
    std::cout << "assignment operator 1" << " \n";
    delete[] m_Buffer;
    m_Size = other.m_Size;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    return *this;
}

String& String::operator=(String&& other) noexcept {
    std::cout << "Moved assignment!!" << std::endl;
    delete[] m_Buffer;
    m_Size = other.m_Size;
    m_Buffer = std::move(other.m_Buffer);
    // m_Buffer = new char[m_Size + 1];
    // memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    other.m_Size = 0;
    // delete[] other.m_Buffer;
    other.m_Buffer = nullptr;
    return *this;
}

String::String(String&& other) noexcept {
    std::cout << "Moved!!" << std::endl;
    delete[] m_Buffer;
    m_Size = other.m_Size;
    m_Buffer = std::move(other.m_Buffer);
    // m_Buffer = new char[m_Size + 1];
    // memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    // delete[] other.m_Buffer;
    other.m_Size = 0;
    other.m_Buffer = nullptr;
}

String::~String() { delete[] m_Buffer; }


String operator+(const String& some, const String& other) noexcept{
    std::cout << "plus operator here" << " \n";

    auto size = some.m_Size + other.m_Size;
    char* temp = new char[size + 1];
    memcpy(temp, some.m_Buffer, some.m_Size);
    memcpy(temp + some.m_Size, other.m_Buffer, other.m_Size);
    temp[size] = '\0';
    String t{ temp,size };
    delete[] temp;
    // this->m_Size = new_size;
    // this->m_Buffer = new_buffer;
    // *this =  new_buffer;
    return t;
}

String& String::operator+=(const String& other) noexcept{
    std::cout << "plus equalto operator here" << " \n";
    *this = *this + other;
    return *this;
}




char& String::operator[](unsigned int index){ 
    if (index < 0 || index >= m_Size) throw Exception::IndexOutOfBounds{};
    return m_Buffer[index]; 
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
}

bool String::operator==(const String& string) noexcept{
    if (m_Size != string.m_Size) return false;
    if(*(string.m_Buffer) == *(this->m_Buffer))
        return true;
    return false;
}

bool String::operator!=(const String& string) noexcept{
    return !(*this == string);
    return true;
}

void String::append(const String& other){
    *this = *this + other;
}


String String::substring(int start) {
    return substring(start, m_Size);
}


String String::substring(int start, int end) {
    if (end <= start) throw Exception::IndexOutOfBounds{};
    if (end > m_Size) end = this->getSize();
    int size = end - start;
    char* new_buffer = new char[size + 1];
    memcpy(new_buffer, m_Buffer + start, size);
    new_buffer[size] = '\0';
    String temp;
    temp.m_Buffer = new_buffer;
    temp.m_Size = size;
    //std::cout << size; 
    return temp;
}

String String::to_string(int num) noexcept{
    if (num == 0)
    {
        return { "0" };
    }

    auto size{ 0 };
    auto temp{ num };

    if (num < 0)
    {
        size++;
        temp = -num;
    }

    while (temp > 0)
    {
        temp /= 10;
        ++size;
    }

    auto newBuffer = new char[size + 1];
    newBuffer[size] = '\0';

    if (num < 0)
    {
        newBuffer[0] = '-';
        num = -num;
    }

    auto i{ size - 1 };
    while (num > 0)
    {
        newBuffer[i] = num % 10 + '0';
        num /= 10;
        i--;
    }

    String result{ newBuffer };

    delete[] newBuffer;
    newBuffer = nullptr;

    return result;
}