#ifndef DCT_H
#define DCT_H

#include <random>
#include <utility>
#include <iostream>
#include <algorithm>

class Treap {
    static std::minstd_rand generator; // ��������� ��������� �����

    struct Node {
        int key, priority; // ���� � ���������
        Node* l = nullptr; // ����� �������� ����
        Node* r = nullptr; // ������ �������� ����
        Node(int key) : key(key), priority(generator()) {} // ����������� ����
    } *root = nullptr; // ������ ������
        // ����������� ���� �����������
    static Node* merge(Node* a, Node* b);
    // ���������� ������ �� ��� ��������� �� �����
    static void split(Node* n, int key, Node*& a, Node*& b);

public:
    Treap() = default; // ����������� �� ���������
    ~Treap(); // ���������� ��� ������� ������

    bool contains(int key); // �������� ������� �����
    void insert(int key); // ������� �����
    void erase(int key); // �������� �����
    int lower_bound(int x); // ���������� ������� �����, �� �������� x
    int count_in_range(int l, int r); // ������� ���������� ����� � ��������� [l, r]

private:
    void clear(Node* node); // ������� ������
    int count_nodes(Node* node); // ������� ����� � ���������
};

#endif // DCT_H