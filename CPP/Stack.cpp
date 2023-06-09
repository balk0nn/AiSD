#include "../Headers/Stack.h"

template<typename T>
Stack<T>::Stack() {
    stack = Spisok<T>();
}

// A method to push the value onto the stack
template<typename T>
void Stack<T>::Push(T value) {
    stack.append(value);
}

// A method to get the value at the top of the stack
template<typename T>
T Stack<T>::getTop() {
    return stack.getValueAt(stack.size - 1);
}

// A method to remove the top element of the stack
template<typename T>
void Stack<T>::pop() {
    stack.removeAt(stack.size - 1);
}

// A method to check if the stack is empty
template<typename T>
bool Stack<T>::isEmpty() {
    return stack.size == 0;
}

// A method to get the size of the stack
template<typename T>
int Stack<T>::getSize() {
    return stack.size;
}

// Explicit instantiations of the Stack class for the supported types
template class Stack<int>;
template class Stack<char>;

