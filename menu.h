#pragma once
#include "DCT.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"
#include "LinkedList.h"
#include "time_measurement.h"

void stackMenu();
void queueMenu();
void dequeMenu();
void linkedListMenu();
void DCTMenu();
void populateManually();
void containerMenu(Stack& stack, Queue& queue, Deque& deque, LinkedList& linkedList, Treap& bst);