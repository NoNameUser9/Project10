#include "menu.h"
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
        std::cout << "Меню:\n";
        std::cout << "1. Стек\n";
        std::cout << "2. Очередь\n";
        std::cout << "3. Дек\n";
        std::cout << "4. Связный список\n";
        std::cout << "5  Декартово дерево\n";
        std::cout << "6. Выход\n";
        std::cout << "Выберите структуру данных: ";
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
            std::cout << "Некорректный выбор, попробуйте снова!" << std::endl;
        }
        std::cout << std::endl;
    }
    return;
}

// Реализация функций для работы с адаптерами'
void stackMenu() {
    Stack stack(2);
    int choice, value;
    while (true) {
        std::cout << "Меню стека:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. Top\n";
        std::cout << "4. Display\n";
        std::cout << "5. Назад\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления: ";
            std::cin >> value;
            stack.push(value);
            break;
        case 2:
            try {
                std::cout << "Удаленный элемент: " << stack.pop() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "Верхний элемент: " << stack.topElement() << std::endl;
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
            std::cout << "Некорректный выбор, попробуйте снова!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void queueMenu() {
    Queue queue(2);
    int choice, value;
    while (true) {
        std::cout << "Меню очереди:\n";
        std::cout << "1. Enqueue\n";
        std::cout << "2. Dequeue\n";
        std::cout << "3. Display\n";
        std::cout << "4. Назад\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите элемент для добавления: ";
            std::cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            try {
                std::cout << "Удаленный элемент: " << queue.dequeue() << std::endl;
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
            std::cout << "Некорректный выбор, попробуйте снова!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void dequeMenu() {
    Deque deque(2);
    int choice, value;
    while (true) {
        std::cout << "Меню дека:\n";
        std::cout << "1. Вставить в начало\n";
        std::cout << "2. Вставить в конец\n";
        std::cout << "3. Удалить с начала\n";
        std::cout << "4. Удалить с конца\n";
        std::cout << "5. Display\n";
        std::cout << "6. Назад\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите элемент для вставки в начало: ";
            std::cin >> value;
            deque.insertRear(value);
            break;
        case 2:
            std::cout << "Введите элемент для вставки в конец: ";
            std::cin >> value;
            deque.insertRear(value);
            break;
        case 3:
            try {
                std::cout << "Удаленный элемент: " << deque.removeFront() << std::endl;
            }
            catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            }
            break;
        case 4:
            try {
                std::cout << "Удаленный элемент: " << deque.removeRear() << std::endl;
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
            std::cout << "Некорректный выбор, попробуйте снова!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void linkedListMenu() {
    LinkedList linkedList;
    int choice, value;
    while (true) {
        std::cout << "Меню связного списка:\n";
        std::cout << "1. Вставить\n";
        std::cout << "2. Удалить\n";
        std::cout << "3. Display\n";
        std::cout << "4. Назад\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите элемент для вставки: ";
            std::cin >> value;
            linkedList.insert(value);
            break;
        case 2:
            std::cout << "Введите элемент для удаления: ";
            std::cin >> value;
            linkedList.remove(value);
            break;
        case 3:
            linkedList.display();
            break;
        case 4:
            return;
        default:
            std::cout << "Некорректный выбор, попробуйте снова!" << std::endl;
        }
        std::cout << std::endl;
    }
}
void DCTMenu() {
    Treap bst;
    int choice,x, l, r;
    while (true) {
        std::cout << "Меню Декартового дерева:\n";
        std::cout << "1. Добавить число в множество\n";
        std::cout << "2. Проверить наличие числа в множестве\n";
        std::cout << "3. Найти первое число, не меньшее x\n";
        std::cout << "4. Найти количество чисел в диапазоне [l,r]\n";
        std::cout << "5. Удалить число из множества\n";
        std::cout << "6. Назад\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите число для добавления: ";
            std::cin >> x;
            bst.insert(x);
            std::cout << x << " добавлено в множество.\n";
            break;
        case 2:
            std::cout << "Введите число для проверки: ";
            std::cin >> x;
            if (bst.contains(x)) {
                std::cout << x << " содержится в множестве.\n";
            }
            else {
                std::cout << x << " не найдено в множестве.\n";
            }
            break;
        case 3:
            std::cout << "Введите x для поиска: ";
            std::cin >> x;
            {
                int lowerBoundValue = bst.lower_bound(x);
                if (lowerBoundValue != -1) {
                    std::cout << "Первое число, не меньшее " << x << ": " << lowerBoundValue << "\n";
                }
                else {
                    std::cout << "Нет чисел, не меньших " << x << ".\n";
                }
            }
            break;
        case 4:
            std::cout << "Введите диапазон [l, r]: ";
            std::cin >> l >> r;
            {
                int count = bst.count_in_range(l, r);
                std::cout << "Количество чисел в диапазоне [" << l << ", " << r << "]: " << count << "\n";
            }
            break;
        case 5:
            std::cout << "Введите число для удаления: ";
            std::cin >> x;
            if (bst.contains(x))
            {
                bst.erase(x);
                std::cout << x << " удалено из множества.\n";
            }
            else {
                std::cout << x << " не найдено в множестве.\n";
            }
            break;
        case 6:
            return;
        default:
            std::cout << "Некорректный выбор, попробуйте снова!" << std::endl;
        }
        std::cout << std::endl;
    }
}


