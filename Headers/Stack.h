#ifndef UNTITLED5_STACK_H
#define UNTITLED5_STACK_H
#include "Spisok.h"

template <typename T>
class Stack {

private:
    Spisok<T> stack;

public:
    Stack();
    void Push(T value);
    T getTop();
    void pop();
    bool isEmpty();
    int getSize();
};

#endif
