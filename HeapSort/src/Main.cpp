/*
 * Main.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: Tyler Wilcock
 *
 *      This is the main 'driver' class for my max heap sort algorithm.
 */

#include <iostream>
#include "HeapSort.h"

using namespace std;

int main()
{
	HeapSort heap;
	heap.insertItem(2);
	heap.insertItem(5);
	heap.insertItem(7);
	heap.insertItem(16);
	heap.displayHeap();

	return 0;
}

