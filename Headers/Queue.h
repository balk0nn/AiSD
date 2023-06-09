#ifndef UNTITLED5_QUEUE_H
#define UNTITLED5_QUEUE_H

#include <string>
#include "Spisok.h"

class Queue {
private:
    Spisok<std::string> queue;
public:
    void push(char x);
    void push(std::string x);
    bool isEmpty();
    void pop();
    std::string front();
    void popFront();
    std::string back();
};


#endif
