#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include <iostream>
#include <memory>
#include "../include/Exceptions.h"
class Node {
public:
    int data{};
    std::shared_ptr<Node> next{};
  Node(int d = 0, std::shared_ptr<Node> temp = nullptr)
        : data{ d }, next{ temp } {};
};

class LinkedList {
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> last;
    unsigned int size;

public:
    LinkedList(unsigned int size = 0);
    int operator[](unsigned int index);

    friend std::ostream& operator<<(std::ostream& stream, const LinkedList& ll);
    void push_back(int d);
    void pop_back();
    void push_front(int d);
    void pop_front();
    void insert_at(int index, int d);
    void delete_at(int index);
    unsigned int get_size();
    void reverse();
    void print();
};
#endif
