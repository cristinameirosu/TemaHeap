#ifndef _HEAP_
#define _HEAP_

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class isGreaterThan
{
public:
	bool operator ()(const T& object1, const T& object2)
	{
		return object1 > object2;
	}

};

template <typename T>
class isSmallerThan 
{
public:
	bool operator ()(const T& object1, const T& object2)
	{
		return object1 < object2;
	}
};


template <typename T, class comp>
class Heap
{
private:
	T *heap;
	int size;
	int capacity;
	comp compare;

public:

	Heap()
	{
		capacity = 1;
		size = 0;
		heap = new T[capacity];
	}

	Heap(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
		heap = new T[this->capacity];
	}

	/*Heap(const Heap& other)
	{
		this->size = other->size;
		this->capacity = other->capacity;
		this->heap = new T[capacity];
		for (int i = 0; i < size; i++)
			this->heap[i] = other->heap[i];
	}*/

	/*void operator =(const Heap& other)
	{
		//check for self-assignment
		if (this == other)
			return;
		this->capacity = other.capacity;
		this->size = other.size;
		for (int i = 0; i < size; i++)
		{
			this->heap[i] = other.heap[i];
		}
		this->compare = other->compare;
	}*/
	
	/*bool operator==(const Heap& other)
	{
	if (this->capacity != other.capacity or this->size != other.size)
	return false;
	for (int i = 0; i < this->size; i++)
	{
	if (this->heap[i] != other.heap[i])
	return false;
	}
	return true;
	}*/

	~Heap()
	{
		delete[] heap;
	}

	void resizeHeap()
	{
		T *tempHeap;
		capacity = 2 * capacity;
		tempHeap = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			tempHeap[i] = heap[i];
		}
		delete[] heap;
		heap = tempHeap;
	}

	void swap(const T& x, const T& y)
	{
		T aux;
		aux = heap[x];
		heap[x] = heap[y];
		heap[y] = aux;
	}

	int getParent(int current)
	{
		return (current - 1) / 2;
	}

	int getLeftSon(int current)
	{
		return 2 * current + 1;
	}

	int getRightSon(int current)
	{
		return 2 * current + 2;
	}

	void insert(T value)
	{
		if (size == capacity)
		{
			resizeHeap();
		}

		heap[size] = value;
		int current = size;

		while (compare(heap[current], heap[getParent(current)]) && current != 0)
		{
			swap(current, (current - 1) / 2);
			current = getParent(current);
		}


		size++;
	}

	void pushDown(int current)
	{
		if (2 * current + 1 > size - 1) {	//daca nu exista nici fiul drept nici fiul stang
			return;
		}

		if (2 * current + 2 > size - 1) //daca nu exista fiul drept
		{
			if (!compare(heap[current], heap[getLeftSon(current)]))
			{
				swap(current, getLeftSon(current));
				return;
			}
			else
				return;
		}
		//suntem in cazul in care exista si fiul drept si fiul stang;
		if (!compare(heap[current], heap[getLeftSon(current)]))
		{
			if (compare(heap[getLeftSon(current)], heap[getRightSon(current)]))
			{
				//trebuie sa ne deplasam in dreapta heapului;
				swap(current, getLeftSon(current));
				current = getLeftSon(current);
				pushDown(current);
			}
		}
		if (!compare(heap[current], heap[getRightSon(current)]))
		{
			swap(current, getRightSon(current));
			current = getRightSon(current);
			pushDown(current);

		}
		else return;
	}

	void extract()
	{
		if (size == 0)
		{
			throw runtime_error("Heap is empty!");
		}
		heap[0] = heap[size - 1];
		int current = 0;
		size--;
		//vrem sa aducem elementul de pe pozitia radacinii la locul corespunzator acestuia
		pushDown(current);
	}

	void printElements()
	{
		for (int i = 0; i < size; i++)
		{
			cout << heap[i] << " ";
		}
	}

	T peek()
	{
		if (size == 0)
		{
			throw runtime_error("Heap is empty!");
		}
		return heap[0];//va intoarce valoare maxima daca avem un maxHeap sau minima daca avem un minHeap
	}

};

#endif // !_HEAP_
