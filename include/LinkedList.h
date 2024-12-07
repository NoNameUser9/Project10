#pragma once
#ifndef LINKEDLISTH
#define LINKEDLISTH

#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();
    void insert(int value);
    void remove(int value);
    void display() const;
};

#endif