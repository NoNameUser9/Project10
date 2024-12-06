//#pragma once
//#include "stack.h"
//#include "queue.h"
//#include "deque.h"
//#include "linkedlist.h"
//#include <stack>
//#include <queue>
//#include <deque>
//#include <list>
//#include <set>
//#include <chrono>
//#include <fstream>
//
//template <typename T>
//void measure_my_stack(MyStack<T> stack, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		stack.push(data[i]);
//
//	for (int i = 0; i < len; i++)
//		stack.pop();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[0] = duration.count();
//}
//
//template <typename T>
//void measure_STL_stack(std::stack<T> stack, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		stack.push(data[i]);
//
//	for (int i = 0; i < len; i++)
//		stack.pop();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[1] = duration.count();
//}
//
//template <typename T>
//void measure_my_queue(MyQueue<T> queue, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		queue.push(data[i]);
//
//	for (int i = 0; i < len; i++)
//		queue.pop();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[2] = duration.count();
//}
//
//template <typename T>
//void measure_STL_queue(std::queue<T> queue, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		queue.push(data[i]);
//
//	for (int i = 0; i < len; i++)
//		queue.pop();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[3] = duration.count();
//}
//
//template <typename T>
//void measure_my_deque(MyDeque<T> deque, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		deque.push_back(data[i]);
//
//	for (int i = 0; i < len; i++)
//		deque.pop_front();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[4] = duration.count();
//}
//
//template <typename T>
//void measure_STL_deque(std::deque<T> deque, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		deque.push_back(data[i]);
//
//	for (int i = 0; i < len; i++)
//		deque.pop_front();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[5] = duration.count();
//}
//
//template <typename T>
//void measure_my_list(MyList<T> list, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		list.push_back(data[i]);
//
//	for (int i = 0; i < len; i++)
//		list.pop_front();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[6] = duration.count();
//}
//
//template <typename T>
//void measure_STL_list(std::list<T> list, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		list.push_back(data[i]);
//
//	for (int i = 0; i < len; i++)
//		list.pop_front();
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[7] = duration.count();
//}
//
//template <typename T>
//void measure_my_tree(MyTreap<T> tree, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		tree.insert(data[i]);
//
//	for (int i = 0; i < len; i++)
//		tree.erase(data[i]);
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[8] = duration.count();
//}
//
//template <typename T>
//void measure_STL_tree(std::set<T> tree, float* times, int* data, int len) {
//	auto start = std::chrono::high_resolution_clock::now();
//	for (int i = 0; i < len; i++)
//		tree.insert(data[i]);
//
//	for (int i = 0; i < len; i++)
//		tree.erase(data[i]);
//
//	auto end = std::chrono::high_resolution_clock::now();
//	std::chrono::duration<float> duration;
//	duration = end - start;
//	times[9] = duration.count();
//}