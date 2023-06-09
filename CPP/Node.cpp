#include <string>
#include "../Headers/Node.h"

// Node class represents a single node in the linked list
template <typename T>
Node<T>::Node(T value) {
    data = value;
    next = nullptr;
}

template class Node<int>;
template class Node<char>;
template class Node<std::string>;