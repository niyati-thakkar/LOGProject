#include <cstring>
#include <iostream>
#include <ostream>
#include <limits>
#include "../include/SmartString.h"
#include "../include/Exceptions.h"

size_t SmartString::getSize() {
    return m_Size;
}
//auto deleter = [](char* ptr) {delete[] ptr; };
SmartString::SmartString(const char* string, unsigned long int n) {
    // std::cout << "default constructor 1" << "\n";
    if (n < 0 || n > std::numeric_limits<size_t>::max()) throw Exception::Overflow{};
    m_Size = strlen(string);
    if (n != 0) m_Size = n > m_Size ? n : m_Size;
    m_Buffer = std::unique_ptr<char>(new char[m_Size + 1]);
    memcpy(m_Buffer.get(), string, m_Size);
    m_Buffer.get()[m_Size] = 0;
}

SmartString::SmartString(const SmartString& other) noexcept {
    if (&other != this) {
        // std::cout << "default constructor 2 with string" << "\n";
        m_Size = other.m_Size;
        m_Buffer = std::unique_ptr<char>(new char[m_Size + 1]);
        memcpy(m_Buffer.get(), other.m_Buffer.get(), m_Size + 1);
    }
}

SmartString& SmartString::operator=(const SmartString& other) noexcept {
    // std::cout << "assignment operator 1" << " \n";
    m_Size = other.m_Size;
    m_Buffer = std::unique_ptr<char>(new char[m_Size + 1]);
    memcpy(m_Buffer.get(), other.m_Buffer.get(), m_Size + 1);
    return *this;
}

SmartString& SmartString::operator=(SmartString&& other) noexcept {
    // std::cout << "Moved assignment!!" << std::endl;
    m_Size = other.m_Size;
    m_Buffer = std::move(other.m_Buffer);
    return *this;
}

SmartString::SmartString(SmartString&& other) noexcept {
    // std::cout << "Moved!!" << std::endl;
    m_Size = other.m_Size;
    m_Buffer = std::move(other.m_Buffer);
}

SmartString operator+(const SmartString& some, const SmartString& other) noexcept {
    // std::cout << "plus operator here" << " \n";
    SmartString t{};
    t.m_Size = some.m_Size + other.m_Size;
    t.m_Buffer = std::unique_ptr<char>(new char[t.m_Size + 1]);
    memcpy(t.m_Buffer.get(), some.m_Buffer.get(), some.m_Size);
    memcpy(t.m_Buffer.get() + some.m_Size, other.m_Buffer.get(), other.m_Size);
    t.m_Buffer.get()[t.m_Size] = '\0';
    return t;
}

SmartString& SmartString::operator+=(const SmartString& other) noexcept {
    // std::cout << "plus equalto operator here" << " \n";
    *this = *this + other;
    return *this;
}




char& SmartString::operator[](size_t index) {
    if (index < 0 || index >= m_Size) throw Exception::IndexOutOfBounds{};
    return m_Buffer.get()[index];
}

std::ostream& operator<<(std::ostream& stream, const SmartString& string) {
    stream << string.m_Buffer;
    return stream;
}

bool SmartString::operator==(const SmartString& string) noexcept {
    if (m_Size != string.m_Size) return false;
    if (*(string.m_Buffer.get()) == *(this->m_Buffer.get()))
        return true;
    return false;
}

bool SmartString::operator!=(const SmartString& string) noexcept {
    return !(*this == string);
    return true;
}

void SmartString::append(const SmartString& other) {
    *this = *this + other;
}


SmartString SmartString::substring(size_t start) {
    return substring(start, m_Size);
}


SmartString SmartString::substring(size_t start, size_t end) {
    if (end <= start) throw Exception::IndexOutOfBounds{};
    if (end > m_Size) end = this->getSize();
    SmartString s{};
    s.m_Size = end - start;
    s.m_Buffer = std::unique_ptr<char>(new char[m_Size + 1]);
    memcpy(s.m_Buffer.get(), m_Buffer.get() + start, m_Size);
    s.m_Buffer.get()[m_Size] = '\0';
    return s;
}

SmartString SmartString::to_string(int num) noexcept {
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

    SmartString result{ newBuffer };

    delete[] newBuffer;
    newBuffer = nullptr;

    return result;
}