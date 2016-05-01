#include "Heap.h"
#include <iostream>
using namespace std;
int main()
{
	Heap<int,isGreaterThan<int> > heap(2);
	heap.insert(3);
	heap.insert(13);
	heap.insert(5);
	heap.insert(2);
	heap.insert(21);
	heap.printElements();
	cout << endl;
	heap.extract();
	heap.printElements();
	cout << endl;
	heap.insert(7);
	heap.insert(9);
	heap.printElements();
	cout << endl;
	heap.extract();
	heap.printElements();
	cout << endl;
	cout << heap.peek();
	char c;
	cin >> c;
}