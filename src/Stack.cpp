#include "Stack.h"

Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x) {
    if (top == capacity - 1) {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i <= top; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }
    arr[++top] = x;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Стек пуст");
    }
    return arr[top--];
}

int Stack::topElement() {
    if (isEmpty()) {
        throw std::out_of_range("Стек пуст");
    }
    return arr[top];
}

bool Stack::isEmpty() {
    return top == -1;
}

void Stack::display() {
    if (isEmpty()) {
        std::cout << "Стек пуст\n";
        return;
    }
    std::cout << "Элементы стека: ";
    for (int i = 0; i <= top; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}