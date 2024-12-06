#include "Queue.h"

Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = rear = 0;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int x) {
    if (rear == capacity) {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < rear; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
    arr[rear++] = x;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("ќчередь пуста");
    }
    return arr[front++];
}

bool Queue::isEmpty() {
    return front == rear;
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "ќчередь пуста\n";
        return;
    }
    std::cout << "Ёлементы очереди: ";
    for (int i = front; i < rear; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}