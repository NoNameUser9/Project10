#include <LinkedList.h>

Node::Node(int value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insert(int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::remove(int value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->data == value) {
            if (prev == nullptr) {
                head = current->next; // �������� ������� ��������
            }
            else {
                prev->next = current->next; // �������� �� �������� ��� �����
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void LinkedList::display() const {
    Node* current = head;
    if (current == nullptr) {
        std::cout << "������� ������ ����\n";
        return;
    }
    std::cout << "�������� �������� ������: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}