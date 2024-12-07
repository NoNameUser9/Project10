#pragma once
#ifndef QUEUEH
#define QUEUEH

#include <iostream>
#include <stdexcept>

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    void display();
};

#endif