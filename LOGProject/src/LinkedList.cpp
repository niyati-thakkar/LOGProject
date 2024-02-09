#include <iostream>
#include <memory>

#include "../include/LinkedList.h"
LinkedList::LinkedList(unsigned int size) : head{ nullptr }, size{ size } {
    if (size != 0) {
        for (unsigned int i = 0; i < size; i++) push_back(0);
    }
}
int LinkedList::operator[](unsigned int index) {
    if (index < 0 || index >= size) throw Exception::IndexOutOfBounds{};
    auto temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

void LinkedList::push_back(int d) {
    if (last == nullptr) {
        last = std::make_shared<Node>(d);
        head = last;
    }
    else {
        last->next = std::make_shared<Node>(d);
        last = last->next;
    }
    size++;
}
void LinkedList::pop_back() {
    if (last == nullptr) {
        throw "cannot delete empty linkedlist";
    }
    else {
        auto temp = head;
        std::shared_ptr<Node> prev = nullptr;
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
void LinkedList::push_front(int d) {
    auto temp = std::make_shared<Node>(d);
    if (head != nullptr) {
        temp->next = head;
    }
    else {
        last = temp;
    }
    head = temp;
    size++;
}
void LinkedList::pop_front() {
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
void LinkedList::insert_at(int index, int d) {
    if (index < 0 || index >= size) throw Exception::IndexOutOfBounds{};
    auto temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }
    auto next = temp->next;
    auto cur = std::make_shared<Node>(d);
    temp->next = cur;
    cur->next = next;
}
void LinkedList::delete_at(int index) {
    if (index < 0 || index >= size) throw Exception::IndexOutOfBounds{};
    auto temp = head;
    std::shared_ptr<Node> prev = nullptr;
    for (int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp = nullptr;
}
unsigned int LinkedList::get_size() { return size; }
void LinkedList::reverse() {
    auto temp = head;
    std::shared_ptr<Node> prev = nullptr;
    auto next = temp->next;
    while (temp != nullptr) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}
void LinkedList::print() {
    auto temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}
std::ostream& operator<<(std::ostream& stream, const LinkedList& ll) {
    auto temp = ll.head;
    for (unsigned int i = 0; i < ll.size; i++) {
        stream << temp->data << " ";
        temp = temp->next;
    }
    stream << "\n";
    return stream;
}
