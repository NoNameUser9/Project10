#pragma once
#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    int height;

    Node(T val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

#endif