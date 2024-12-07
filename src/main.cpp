#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "time_measurement.h"
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
        std::cout << "������������ �����!" << std::endl;
    }

    return 0;
}
//int main() {
//	setlocale(LC_ALL, "Russian");
//	MyStack<int> st_int;
//	MyQueue<int> que_int;
//	MyDeque<int> deq_int;
//	MyList<int> lst_int;
//	MyTreap<int> tr_int;
//	std::stack<int> st_stl;
//	std::queue<int> q_stl;
//	std::deque<int> deq_stl;
//	std::list<int> lst_stl;
//	std::set<int> tr_stl;
//	int choise = 0;
//	int cnt_len = 0;
//	int temp = 0;
//	int c = 0;
//	int* arr_data = new int[0];
//	float* arr_times = new float[10];
//	char** arr_containers = new char* [5];
//	for (int i = 0; i < 5; i++) {
//		arr_containers[i] = new char[30];
//	}
//	strcpy(arr_containers[0], "����");
//	strcpy(arr_containers[1], "�������");
//	strcpy(arr_containers[2], "������������ �������");
//	strcpy(arr_containers[3], "���������� ������");
//	strcpy(arr_containers[4], "�������� ������ ������");
//
//	auto start = std::chrono::high_resolution_clock::now();
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	std::ifstream file;
//	char* filename = new char [0];
//	while (choise != 3) {
//		std::cout << "1. ������� ������ �������\n2. ������� ������ � �����\n3. �����\n�������� ��������: ";
//		std::cin >> choise;
//		switch (choise)
//		{
//		case 1:
//			std::cout << "\n� ����� ����������� �� ������ ��������?\n1. ����\n2. �������\n3. ������������ �������\n4. ���������� ������\n5. ��������� ������\n6. �����\n";
//			while (choise != 6) {
//				std::cout << "�������� ���������: ";
//				std::cin >> choise;
//
//				switch (choise)
//				{
//				case 1:
//					menu_stack(st_int);
//					break;
//				case 2:
//					menu_queue(que_int);
//					break;
//				case 3:
//					menu_deque(deq_int);
//					break;
//				case 4:
//					menu_list(lst_int);
//					break;
//				case 5:
//					menu_treap(tr_int);
//					break;
//				case 6:
//					break;
//				default:
//					std::cout << choise << "-�� ���������� �� ����������\n";
//					break;
//				}
//			}
//
//			break;
//		case 2:
//			filename = new char[80];
//			std::cout << "������� ��� �����: ";
//			std::cin >> filename;
//			std::cout << "\n";
//
//			file.open(filename);
//			if (!file.is_open()) {
//				std::cout << "���� �� ������!" << std::endl;
//				return 1;
//			}
//
//			cnt_len = 0;
//			char temp_c[80];
//			while (file >> temp_c) {
//				cnt_len++;
//			}
//
//			arr_data = new int[cnt_len];
//
//			file.clear();
//			file.seekg(0L, std::ios_base::beg);
//
//			while (file >> temp) {
//				arr_data[c] = temp;
//				c++;
//			}
//
//			file.clear();
//			file.seekg(0L, std::ios_base::beg);
//
//			measure_my_stack(st_int, arr_times, arr_data, cnt_len);
//			measure_STL_stack(st_stl, arr_times, arr_data, cnt_len);
//
//			measure_my_queue(que_int, arr_times, arr_data, cnt_len);
//			measure_STL_queue(q_stl, arr_times, arr_data, cnt_len);
//
//			measure_my_deque(deq_int, arr_times, arr_data, cnt_len);
//			measure_STL_deque(deq_stl, arr_times, arr_data, cnt_len);
//
//			measure_my_list(lst_int, arr_times, arr_data, cnt_len);
//			measure_STL_list(lst_stl, arr_times, arr_data, cnt_len);
//
//			measure_my_tree(tr_int, arr_times, arr_data, cnt_len);
//			measure_STL_tree(tr_stl, arr_times, arr_data, cnt_len);
//
//			print_table(arr_times, arr_containers);
//			printChart(arr_times, arr_containers);
//
//			break;
//		case 3:
//			break;
//		default:
//			std::cout << '\n' << choise << "-�� �������� �� ����������\n\n";
//			break;
//		}
//	}
//
//	delete[] arr_containers;
//	delete[] arr_times;
//	delete[] filename;
//
//	return 0;
//}