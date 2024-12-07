#include <menu.h>
#include <time_measurement.h>
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;

    std::cout << "�������� ������ ���������� �����������:\n";
    std::cout << "1. ��������� �������\n";
    std::cout << "2. ��������� �� �����\n";
    std::cout << "������� ��� �����: ";
    std::cin >> choice;

    if (choice == 1) {
        populateManually();
    }
    //else(choice == 2) {

    //}
    else {
        std::cout << "penis" << std::endl;
    }

    return 0;
}
