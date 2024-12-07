#pragma once
#ifndef STACKH
#define STACKH

#include <iostream>
#include <stdexcept>

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int topElement();
    bool isEmpty();
    void display();
};

#endif