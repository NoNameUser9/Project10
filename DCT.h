#ifndef DCT_H
#define DCT_H

#include <random>
#include <utility>
#include <iostream>
#include <algorithm>

class Treap {
    static std::minstd_rand generator; // Генератор случайных чисел

    struct Node {
        int key, priority; // Ключ и приоритет
        Node* l = nullptr; // Левый дочерний узел
        Node* r = nullptr; // Правый дочерний узел
        Node(int key) : key(key), priority(generator()) {} // Конструктор узла
    } *root = nullptr; // Корень дерева
        // Объединение двух поддеревьев
    static Node* merge(Node* a, Node* b);
    // Разделение дерева на два поддерева по ключу
    static void split(Node* n, int key, Node*& a, Node*& b);

public:
    Treap() = default; // Конструктор по умолчанию
    ~Treap(); // Деструктор для очистки памяти

    bool contains(int key); // Проверка наличия ключа
    void insert(int key); // Вставка ключа
    void erase(int key); // Удаление ключа
    int lower_bound(int x); // Нахождение первого числа, не меньшего x
    int count_in_range(int l, int r); // Подсчет количества чисел в диапазоне [l, r]

private:
    void clear(Node* node); // Очистка памяти
    int count_nodes(Node* node); // Подсчет узлов в поддереве
};

#endif // DCT_H