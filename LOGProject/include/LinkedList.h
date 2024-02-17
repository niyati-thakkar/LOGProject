#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include <iostream>
#include <memory>
#include "../include/Exceptions.h"
template<typename T>
class Node{
public:
    T data{};
    std::shared_ptr<Node<T>> next{};
  Node<T>(T d = 0, std::shared_ptr<Node<T>> temp = nullptr)
        : data{ d }, next{ temp } {};
};
template<typename T>
class LinkedList {
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> last;
    unsigned int size;

public:
    LinkedList(unsigned int size = 0);
    int operator[](unsigned int index);

    //friend std::ostream& operator<<(std::ostream& stream, const LinkedList& ll);
    void push_back(T d);
    void pop_back();
    void push_front(T d);
    void pop_front();
    void insert_at(unsigned int index, T d);
    void delete_at(unsigned int index);
    unsigned int get_size();
    void reverse();
    void print();
};
template<typename T>
LinkedList<T>::LinkedList(unsigned int size) : head{ nullptr }, size{ size } {
    if (size != 0) {
        for (unsigned int i = 0; i < size; i++) push_back(0);
    }
}
template<typename T>
int LinkedList<T>::operator[](unsigned int index) {
    if (index < 0 || index >= size) throw Exception::IndexOutOfBounds{};
    auto temp = head;
    for (unsigned int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}
template<typename T>
void LinkedList<T>::push_back(T d) {
    if (last == nullptr) {
        last = std::make_shared<Node<T>>(d);
        head = last;
    }
    else {
        last->next = std::make_shared<Node<T>>(d);
        last = last->next;
    }
    size++;
}
template<typename T>
void LinkedList<T>::pop_back() {
    if (last == nullptr) {
        throw "cannot delete empty linkedlist";
    }
    else {
        auto temp = head;
        std::shared_ptr<Node<T>> prev = nullptr;
        while (temp->next != nullptr) {
            // std::cout << temp->data<<"\n";
            prev = temp;
            temp = temp->next;
        }
        // std::cout << temp->data<<"\n";
        temp = nullptr;
        prev->next = nullptr;
        // std::cout << temp->data<<"\n";
        last = prev;
    }
    size--;
}
template<typename T>
void LinkedList<T>::push_front(T d) {
    auto temp = std::make_shared<Node<T>>(d);
    if (head != nullptr) {
        temp->next = head;
    }
    else {
        last = temp;
    }
    head = temp;
    size++;
}
template<typename T>
void LinkedList<T>::pop_front() {
    if (head == nullptr) {
        throw "cannot delete empty linkedlist";
    }
    else {
        auto temp = head;
        head = head->next;
        temp = nullptr;
    }
    size--;
}
template<typename T>
void LinkedList<T>::insert_at(unsigned int index, T d) {
    if (index < 0 || index >= size) throw Exception::IndexOutOfBounds{};
    auto temp = head;
    for (unsigned int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    auto next = temp->next;
    auto cur = std::make_shared<Node<T>>(d);
    temp->next = cur;
    cur->next = next;
}
template<typename T>
void LinkedList<T>::delete_at(unsigned int index) {
    if (index < 0 || index >= size) throw Exception::IndexOutOfBounds{};
    auto temp = head;
    std::shared_ptr<Node<T>> prev = nullptr;
    for (unsigned int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp = nullptr;
}
template<typename T>
unsigned int LinkedList<T>::get_size() { return size; }
template<typename T>
void LinkedList<T>::reverse() {
    auto temp = head;
    std::shared_ptr<Node<T>> prev = nullptr;
    auto next = temp->next;
    while (temp != nullptr) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}
template<typename T>
void LinkedList<T>::print() {
    auto temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}
//template<typename T>
//std::ostream& operator<<(std::ostream& stream, const LinkedList<T>& ll) {
//    auto temp = ll.head;
//    for (unsigned int i = 0; i < ll.size; i++) {
//        stream << temp->data << " ";
//        temp = temp->next;
//    }
//    stream << "\n";
//    return stream;
//}
#endif
//class std::basic_ostream<char, struct std::char_traits<char> >& __cdecl operator<<(class std::basic_ostream<char, struct std::char_traits<char> >&, class LinkedList<int> const&)
