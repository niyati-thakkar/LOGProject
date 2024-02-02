#include <cstring>
#include <iostream>
#include <ostream>

#include "String.h"

String::String(const char* string, int n) {
    m_Size = strlen(string);
    if (n != 0) m_Size = n;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, string, m_Size);
    m_Buffer[m_Size] = 0;
}
String::String(const String& other) : m_Size(other.m_Size) {
    m_Buffer = new char[other.m_Size + 1];
    memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
}
String& String::operator=(const String& other) {
    m_Size = other.m_Size;
    m_Buffer = new char[m_Size + 1];
    memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
    return *this;
}
String String::operator+(const String& other) {
    unsigned int new_size = this->m_Size + other.m_Size;
    char* new_buffer = new char[new_size + 1];
    memcpy(new_buffer, this->m_Buffer, m_Size);
    memcpy(new_buffer + m_Size, other.m_Buffer, other.m_Size);
    new_buffer[new_size] = '\0';
    // this->m_Size = new_size;
    // this->m_Buffer = new_buffer;
    // *this =  new_buffer;
    return String{ new_buffer };
}
String::~String() { delete[] m_Buffer; }
char& String::operator[](unsigned int index) { return m_Buffer[index]; }
void String::append(const String& other) {
    *this = *this + other;
}
String String::operator+(const char* s1, const String& other) {
    String temp{ s1 };
    return temp + other;
}