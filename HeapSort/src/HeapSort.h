/*
 * HeapSort.h
 *
 *  Created on: Apr 14, 2014
 *      Author: Tyler Wilcock
 *
 */

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

using namespace std;

class HeapSort
{
	public:
		HeapSort();
		virtual ~HeapSort();
		int removeItem();
		void insertItem(int);
		void displayHeap();
		void swap(int&, int&);
		int findMaxChild(int, int);
	private:
		int heapArray[100];
		int heapSize;
};

#endif /* HEAPSORT_H_ */
