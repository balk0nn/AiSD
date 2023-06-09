#include "../Headers/Queue.h"

void Queue::push(char x) {
    queue.append(std::string(1, x));
}

bool Queue::isEmpty() {
    return queue.size == 0;
}

void Queue::pop() {
    queue.removeAt(queue.size - 1);
}

std::string Queue::front() {
    return queue.getValueAt(0);
}

void Queue::popFront() {
    queue.removeAt(0);
}

std::string Queue::back() {
    return queue.getValueAt(queue.size - 1);
}

void Queue::push(std::string x) {
    queue.append(x);
}
