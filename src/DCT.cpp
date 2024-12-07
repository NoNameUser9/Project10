#include <DCT.h>

std::minstd_rand Treap::generator;

Treap::~Treap() {
    clear(root);
}

bool Treap::contains(int key) {
    Node* less = nullptr;
    Node* equal = nullptr;
    Node* greater = nullptr;

    split(root, key, less, greater);
    split(greater, key + 1, equal, greater);

    bool result = equal != nullptr; // ���������, ���������� �� ���� � ������ ������
    root = merge(merge(less, equal), greater); // ��������������� ������
    return result; // ���������� ���������
}

void Treap::insert(int key) {
    Node* less = nullptr;
    Node* greater = nullptr;

    split(root, key, less, greater); // ��������� �� �����
    root = merge(merge(less, new Node(key)), greater); // ���������� � ����� �����
}

void Treap::erase(int key) {
    Node* less = nullptr;
    Node* equal = nullptr;
    Node* greater = nullptr;

    split(root, key, less, greater);
    split(greater, key + 1, equal, greater);

    root = merge(less, greater); // ���������� ���������� ����
    delete equal; // ����������� ������ ��� ����
}

void Treap::clear(Node* node) {
    if (!node) return; // ���� ���� ����, �������
    clear(node->l); // ���������� ������� ����� ���������
    clear(node->r); // ���������� ������� ������ ���������
    delete node; // ����������� ������
}

Treap::Node* Treap::merge(Node* a, Node* b) {
    if (!a || !b) return a ? a : b; // ���������� �������� ���������

    if (a->priority > b->priority) { // ���������� ����������
        a->r = merge(a->r, b); // ���������� ������ ���������
        return a; // ���������� ������ ������� ���������
    }
    else {
        b->l = merge(a, b->l); // ���������� ����� ���������
        return b; // ���������� ������ ������� ���������
    }
}

void Treap::split(Node* n, int key, Node*& a, Node*& b) {
    if (!n) {
        a = b = nullptr; // ���� ���� ����, ���������� nullptr
        return;
    }
    if (n->key < key) { // ���� ���� ���� ������ ���������
        split(n->r, key, n->r, b); // ���������� ��������� ������ ���������
        a = n; // ������������� ����� �����
    }
    else {
        split(n->l, key, a, n->l); // ���������� ��������� ����� ���������
        b = n; // ������������� ������ �����
    }
}

// ����� ��� ���������� ������� �����, �� �������� x
int Treap::lower_bound(int x) {
    Node* current = root;
    Node* answer = nullptr;

    while (current) {
        if (current->key < x) { // ���� ������� ���� ������ x, ���� ������
            current = current->r;
        }
        else { // �����, ��������� ���� � ���� �����
            answer = current;
            current = current->l;
        }
    }
    return answer ? answer->key : -1; // ���������� ��������� ����� ��� -1, ���� ������� �� ������
}

// ����� ��� �������� ���������� ����� � ��������� [l, r]
int Treap::count_in_range(int l, int r) {
    Node* less = nullptr;
    Node* equal = nullptr;
    Node* greater = nullptr;

    split(root, r + 1, less, greater); // ��������� �� r
    split(less, l, less, equal); // ��������� �� l

    int count = count_nodes(equal); // ������������ ���������� ����� � ����������
    root = merge(merge(less, equal), greater); // �������������� ������
    return count;
}

// ����� ��� �������� ����� � ���������
int Treap::count_nodes(Node* node) {
    if (!node) return 0;
    return 1 + count_nodes(node->l) + count_nodes(node->r);
}