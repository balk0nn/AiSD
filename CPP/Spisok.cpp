#include <iostream>
#include "../Headers/Spisok.h"

// Constructor
template<typename T>
Spisok<T>::Spisok() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// A method to insert the value to the back of the list
template<typename T>
void Spisok<T>::append(T value) {

    // Creating a new node
    auto* newNode = new Node<T>(value);

    // If the list is empty, make the new node both the head and the tail
    if (head == nullptr) {
        head = newNode;
        tail = newNode;

        // Otherwise, add the new node after the tail and update the tail pointer
    } else {

        tail->next = newNode;
        tail = newNode;
    }

    // Update the size
    size++;
}

// A method to insert the value to the front of the list
template<typename T>
void Spisok<T>::prepend(T value) {

    // Creating a new node
    auto* newNode = new Node<T>(value);

    // If the list is empty, make the new node both the head and the tail
    if (head == nullptr) {
        head = newNode;
        tail = newNode;

        // Otherwise, make the new node the new head and update the next pointer
    } else {

        newNode->next = head;
        head = newNode;
    }

    // Update the size
    size++;
}

// A method to insert an element at a given position
template<typename T>
void Spisok<T>::insertAt(T value, int position) {

    // Check if the position is out of bounds
    if (position < 0 || position > size) {
        return;
    }

    // If the position is 0, prepend the new node
    if (position == 0) {
        prepend(value);
        return;
    }

    // If the position is the size of the list, append the new node
    if (position == size) {
        append(value);
        return;
    }

    // Otherwise, find the node at the position - 1 and insert the new node after it
    auto* newNode = new Node<T>(value);
    auto* current = head;
    int currentPosition = 0;

    while (currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    newNode->next = current->next;
    current->next = newNode;

    // Update the size
    size++;
}

// A method to remove a first entry of a value from the list
template<typename T>
void Spisok<T>::remove(T value) {
    auto* current = head;
    Node<T>* previous = nullptr;

    while (current != nullptr) {
        if (current->data == value) {

            // If the node with the value is found, update nearby pointers and delete the node
            if (previous == nullptr) {
                head = current->next;

            } else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            // Deleting the node and updating the size
            delete current;
            size--;
            return;
        }
        previous = current;
        current = current->next;
    }
}

// A method to remove the element by its position
template<typename T>
void Spisok<T>::removeAt(int position) {

    // Check if the position is out of bounds
    if (position < 0 || position >= size) {
        return;
    }

    // If the position is 0, remove the head node
    if (position == 0) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;

        // If the list becomes empty, update the tail pointer
        if (size == 1) {
            tail = nullptr;
        }

        // Otherwise, find the node at the end update the nearby pointers
    } else {

        auto* current = head;
        Node<T>* previous = nullptr;
        int currentPosition = 0;

        while (currentPosition < position) {
            previous = current;
            current = current->next;
            currentPosition++;
        }

        previous->next = current->next;

        // If the removed node is the tail, update the tail pointer
        if (current == tail) {
            tail = previous;
        }

        delete current;
    }

    // Updating the size
    size--;
}

// A method to get a first entry (position) of a certain value
template<typename T>
int Spisok<T>::search(T value) {
    auto* current = head;
    int position = 0;

    while (current != nullptr) {

        // If the node with the value is found, return its position
        if (current->data == value) {
            return position;
        }

        current = current->next;
        position++;
    }

    // If the value is not found, return -1 (no such position)
    return -1;
}

// A method to get the value by its position
template<typename T>
T Spisok<T>::getValueAt(int position) {
    
    Node<T>* current = head;
    int currentPosition = 0;

    while (currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    // Return the value of the node at the position
    return current->data;
}

// A method to output the list
template<typename T>
void Spisok<T>::printList() {
    auto* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

template class Spisok<int>;
template class Spisok<char>;
template class Spisok<std::string>;