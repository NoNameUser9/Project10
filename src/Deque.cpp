#include "Deque.h"

Deque::Deque(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = 0;
}

Deque::~Deque() {
    delete[] arr;
}

void Deque::insertRear(int x) {
    if (front == 0) {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < rear; i++)
            newArr[i + 1] = arr[i];
        delete[] arr;
        arr = newArr;
        front++;
        rear++;
    }
    arr[--front] = x;
}

int Deque::removeFront() {
    if (isEmpty()) {
        throw std::out_of_range("Дек пуст");
    }
    return arr[front++];
}
int Deque::removeRear() {
    if (isEmpty()) {
        throw std::out_of_range("Дек пуст");
    }
    return arr[--rear];
}
bool Deque::isEmpty() {
    return front == rear;
}

void Deque::display() {
    if (isEmpty()) {
        std::cout << "Дек пуст\n";
        return;
    }
    std::cout << "Элементы деки: ";
    for (int i = front; i < rear; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}