/*
 * HeapSort.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: Tyler Wilcock
 *
 *      The purpose of this class is to implement a max heap sort algorithm.  A max heap is based off a
 *      binary tree in that each root node has a maximum of two leaf nodes.  Each of these leaf nodes can
 *      be a root node itself.  Specifically, a max heap is a heap in which the root node must be of greater
 *      value than its leaf nodes.
 *
 *      I know that Javadocs doesn't support C++, but I'm going to use Javadocs syntax for commenting
 *      regardless.  I'll be looking more into C++ documentation tools (like Doxygen) and port the
 *      commenting over when I find one that I really like.
 */

#include "HeapSort.h"
#include <iostream>

using namespace std;

/**
 * So far, all I use this constructor for is to declare the size of the max heap to 0.
 */
HeapSort::HeapSort()
{
	heapSize = 0;
}

HeapSort::~HeapSort()
{

}

/**
 * Swaps the value of two integer values using memory addresses.
 *
 * @param Address of first integer value
 * @param Address of second integer value
 * @return void
 */
void HeapSort::swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

/**
 * This function should compare the left and right children indices passed into it using the class variable 'heapArray'.
 * If there are no children, it will return -1.  If there is only one child, that means there is only a left child, and that will
 * be returned.  Otherwise, it will compare the two children within the array and return the larger one.
 *
 * @param leftChild - int Index of the leftChild
 * @param rightChild - int Index of the rightChild
 * @return The bigger child
 */
int HeapSort::findMaxChild(int leftChild, int rightChild)
{
	if(leftChild > heapSize - 1)
	{
		/*There are no left or right children from the parent node
		*Example, only parent node.  leftChild = parent (0) * 2 + 1, which means leftChild = 1;
		*							 If there is only one node, size = 1;
		*							 Condition(leftChild {1} > size {1}) = false
		*							 Return -1
		*/
		return -1;
	}

	if(rightChild > heapSize - 1)
	{
		/* There is only a left child, return it.
		 * Example, only a 2 nodes (parent and left obviously)
		 * 													TRUE CONDITION EXAMPLE
		 * 										rightChild = parent(0) * 2 + 2, which means rightChild = 2;
		 * 										If there is only two nodes, size = 2;
		 * 										Condition(rightChild {2} > size {2}) = false
		 * 										return leftChild (The only child of the parent)
		 *
		 */
		return leftChild;
	}

	if(heapArray[leftChild] > heapArray[rightChild])
	{
		return leftChild;
	}
	return rightChild;
}

/**
 * This function inserts a new node into the bottom right most position (the index pointed to by size) of the heap.
 * After the value is inserted, it checks to make sure that the max heap is properly sorted.  If any value is not
 * in the proper order, it will swap the necessary values so that the max heap is properly sorted.
 *
 * @param item Integer item that will be inserted into the heap
 * @return void
 */
void HeapSort::insertItem(int item)
{
	if(heapSize == 0)
	{
		heapArray[0] = item;
		heapSize++;
	}
	else
	{
		heapArray[heapSize] = item;
		heapSize++;
		int parent;
		int leftChild = parent * 2 + 1;
		int rightChild = parent * 2 + 2;
		int maxChild = findMaxChild(leftChild, rightChild);

		while(heapArray[parent] < heapArray[maxChild] && maxChild != -1)
		{
			if(heapArray[parent] < heapArray[maxChild])
			{
				swap(heapArray[parent], heapArray[maxChild]);
			}
			leftChild = parent * 2 + 1;
			rightChild = parent * 2 + 2;
			maxChild = findMaxChild(leftChild, rightChild);
			parent = maxChild;
		}
	}
}

/**
 * The purpose of this function is to remove the node at index '0' from the max heap, and return this value.
 * After the removal, the function will check to make sure that the heap is still properly sorted.  If any value
 * breaks the rule of max heaps, the necessary values will be swapped to the heap is properly sorted once again.
 *
 * @return int Item removed from the heap at index '0'
 */
int HeapSort::removeItem()
{

}

/**
 * This function prints the current content of the heap to the console, including array indices.
 *
 * @return void
 */
void HeapSort::displayHeap()
{
	for(int i = 0; i < heapSize; i++)
	{
		cout << "Element " << i << " is " << heapArray[i] << ". \n";
	}
}
