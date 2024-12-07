#include <menu.h>
void populateManually() {
    Stack stack(10);
    Queue queue(10);
    Deque deque(10);
    LinkedList linkedList;
    Treap bst;
    containerMenu(stack, queue, deque, linkedList,bst);
}
void containerMenu(Stack& stack, Queue& queue, Deque& deque, LinkedList& linkedList, Treap& bst) {
    while (true) {
        std::cout << "����:\n";
        std::cout << "1. ����\n";
        std::cout << "2. �������\n";
        std::cout << "3. ���\n";
        std::cout << "4. ������� ������\n";
        std::cout << "5  ��������� ������\n";
        std::cout << "6. �����\n";
        std::cout << "�������� ��������� ������: ";
        int chose;
        std::cin >> chose;

        switch (chose) {
        case 1:
            stackMenu();
            break;
        case 2:
            queueMenu();
            break;
        case 3:
            dequeMenu();
            break;
        case 4:
            linkedListMenu();
            break;
        case 5:
            DCTMenu();
        case 6:
            return;
        default:
            std::cout << "������������ �����, ���������� �����!" << std::endl;
        }
        std::cout << std::endl;
    }
    return;
}

// ���������� ������� ��� ������ � ����������'
void stackMenu() {
    Stack stack(2);
    int choice, value;
    while (true) {
        std::cout << "���� �����:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Top\n";
        std::cout << "4. Display\n";
        std::cout << "5. �����\n";
        std::cout << "�������� ��������: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "������� ������� ��� ����������: ";
            std::cin >> value;
            stack.push(value);
            break;
        case 2:
            try {
                std::cout << "��������� �������: " << stack.pop() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "������� �������: " << stack.topElement() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            stack.display();
            break;
        case 5:
            return;
        default:
            std::cout << "������������ �����, ���������� �����!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void queueMenu() {
    Queue queue(2);
    int choice, value;
    while (true) {
        std::cout << "���� �������:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Display\n";
        std::cout << "4. �����\n";
        std::cout << "�������� ��������: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "������� ������� ��� ����������: ";
            std::cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            try {
                std::cout << "��������� �������: " << queue.dequeue() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 3:
            queue.display();
            break;
        case 4:
            return;
        default:
            std::cout << "������������ �����, ���������� �����!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void dequeMenu() {
    Deque deque(2);
    int choice, value;
    while (true) {
        std::cout << "���� ����:\n";
        std::cout << "1. �������� � ������\n";
        std::cout << "2. �������� � �����\n";
        std::cout << "3. ������� � ������\n";
        std::cout << "4. ������� � �����\n";
        std::cout << "5. Display\n";
        std::cout << "6. �����\n";
        std::cout << "�������� ��������: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "������� ������� ��� ������� � ������: ";
            std::cin >> value;
            deque.insertRear(value);
            break;
        case 2:
            std::cout << "������� ������� ��� ������� � �����: ";
            std::cin >> value;
            deque.insertRear(value);
            break;
        case 3:
            try {
                std::cout << "��������� �������: " << deque.removeFront() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            try {
                std::cout << "��������� �������: " << deque.removeRear() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 5:
            deque.display();
            break;
        case 6:
            return;
        default:
            std::cout << "������������ �����, ���������� �����!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void linkedListMenu() {
    LinkedList linkedList;
    int choice, value;
    while (true) {
        std::cout << "���� �������� ������:\n";
        std::cout << "1. ��������\n";
        std::cout << "2. �������\n";
        std::cout << "3. Display\n";
        std::cout << "4. �����\n";
        std::cout << "�������� ��������: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "������� ������� ��� �������: ";
            std::cin >> value;
            linkedList.insert(value);
            break;
        case 2:
            std::cout << "������� ������� ��� ��������: ";
            std::cin >> value;
            linkedList.remove(value);
            break;
        case 3:
            linkedList.display();
            break;
        case 4:
            return;
        default:
            std::cout << "������������ �����, ���������� �����!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void DCTMenu() {
    Treap bst;
    int choice,x, l, r;
    while (true) {
        std::cout << "���� ����������� ������:\n";
        std::cout << "1. �������� ����� � ���������\n";
        std::cout << "2. ��������� ������� ����� � ���������\n";
        std::cout << "3. ����� ������ �����, �� ������� x\n";
        std::cout << "4. ����� ���������� ����� � ��������� [l,r]\n";
        std::cout << "5. ������� ����� �� ���������\n";
        std::cout << "6. �����\n";
        std::cout << "��� �����: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "������� ����� ��� ����������: ";
            std::cin >> x;
            bst.insert(x);
            std::cout << x << " ��������� � ���������.\n";
            break;
        case 2:
            std::cout << "������� ����� ��� ��������: ";
            std::cin >> x;
            if (bst.contains(x)) {
                std::cout << x << " ���������� � ���������.\n";
            }
            else {
                std::cout << x << " �� ������� � ���������.\n";
            }
            break;
        case 3:
            std::cout << "������� x ��� ������: ";
            std::cin >> x;
            {
                int lowerBoundValue = bst.lower_bound(x);
                if (lowerBoundValue != -1) {
                    std::cout << "������ �����, �� ������� " << x << ": " << lowerBoundValue << "\n";
                }
                else {
                    std::cout << "��� �����, �� ������� " << x << ".\n";
                }
            }
            break;
        case 4:
            std::cout << "������� �������� [l, r]: ";
            std::cin >> l >> r;
            {
                int count = bst.count_in_range(l, r);
                std::cout << "���������� ����� � ��������� [" << l << ", " << r << "]: " << count << "\n";
            }
            break;
        case 5:
            std::cout << "������� ����� ��� ��������: ";
            std::cin >> x;
            if (bst.contains(x))
            {
                bst.erase(x);
                std::cout << x << " ������� �� ���������.\n";
            }
            else {
                std::cout << x << " �� ������� � ���������.\n";
            }
            break;
        case 6:
            return;
        default:
            std::cout << "������������ �����, ���������� �����!" << std::endl;
        }
        std::cout << std::endl;
    }
}


