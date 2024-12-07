#pragma once
#ifndef DEQUEH
#define DEQUEH

#include <iostream>
#include <stdexcept>

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Deque(int size);
    ~Deque();
    void insertFront(int x);
    void insertRear(int x);
    int removeFront();
    int removeRear();
    bool isEmpty();
    void display();
};

#endif