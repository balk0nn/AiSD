#ifndef UNTITLED5_SPISOK_H
#define UNTITLED5_SPISOK_H

#include "Node.h"

template <typename T>
class Spisok {
public:
    // Attributes of the Spisok class
    Node<T>* head;
    Node<T>* tail;
    int size;

    //declaration of every method of the Spisok class
    Spisok();
    void append(T value);
    void prepend(T value);
    void insertAt(T value, int position);
    void remove(T value);
    void removeAt(int position);
    int search(T value);
    T getValueAt(int position);
    void printList();
};

#endif
