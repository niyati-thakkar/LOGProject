#include <cstring>
#include <iostream>
#include <ostream>

#include "String.h"

int String::getSize() {
    return m_Size;
}

String::String(const char* string, unsigned int n) {
    std::cout << "default constructor 1" << "\n";
    m_Size = strlen(string);
    if (n != 0) m_Size = n;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, string, m_Size);
    m_Buffer[m_Size] = 0;
}

String::String(const String& other){
    if (&other != this) {
        std::cout << "default constructor 2 with string" << "\n";
        m_Size = other.m_Size;
        m_Buffer = new char[m_Size + 1];
        memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    }
}

String& String::operator=(const String& other) {
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

String operator+(const String& some, const String& other) {
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


String::~String() { delete[] m_Buffer; }

char& String::operator[](unsigned int index) { return m_Buffer[index]; }

void String::append(const String& other) {
    *this = *this + other;
}


String String::substring(int start) {
    return substring(start, m_Size);
}


String String::substring(int start, int end) {
    // if (end <= start) throw "enter valid data";
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