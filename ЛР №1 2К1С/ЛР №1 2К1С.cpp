#include <iostream>
#include "Integer.h"
#include "LinkedListSequence.h"
#include "SorterQuickSortLinkedListSequence.h"
#include "ArraySequence.h"
#include "SorterBubbleSortLinkedListSequence.h"
#include "SorterInsertion_binaryArraySequence.h"
#include "SorterInsertion_binaryLinkedListSequence.h"
#include "InterfaceProcedure.h"
#include "TimeMeasurementSorter.h"
#include "RandomInteger.h"
const int globalLengthOfArray = 10;
int arrInt[globalLengthOfArray] = { 1, 4, 5, 5, 3, 6, 4, 1, 9, 7 };
int arrIntSorted[globalLengthOfArray] = { 1, 1, 3, 4, 4, 5, 5, 6, 7, 9 };
using namespace std;
class MyInt {
private:
	int data;
public:
	MyInt(int a) : data(a)
	{
	}
	~MyInt() {}
	bool operator < (const MyInt& right) {
		return this->data < right.data;
	}

	bool operator <= (const MyInt& right) {
		return this->data <= right.data;
	}

	bool operator == (const MyInt& right) {
		return this->data == right.data;
	}
};

int* newInt(int n) {
	int* r = new int;
	*r = n;
	return r;
}

auto genArrPtrInt(int* arr, const int l) {
	int** r = new int* [l];
	for (int i = 0; i < l; i++)
		r[i] = newInt(arr[i]);
	return r;
}

auto genArrPtrMyInt(int* arr, const int l) {
	MyInt** r;
	r = new MyInt*[l];
	for (int i = 0; i < l; i++)
		r[i] = new MyInt((arr[i]));
	return r;
}

auto genArrPtrInteger(int* arr, const int l) {
	Integer** r = new Integer * [l];
	for (int i = 0; i < l; i++)
		r[i] = new Integer(arr[i]);
	return r;
}

LinkedListSequence<int>* genListFromArray() {
	auto arr = genArrPtrInt(arrInt, globalLengthOfArray);
	return new LinkedListSequence<int>(arr, globalLengthOfArray);
}

LinkedListSequence<int>* genListFromSortedArray() {
	auto arr = genArrPtrInt(arrIntSorted, globalLengthOfArray);
	return new LinkedListSequence<int>(arr, globalLengthOfArray);
}

LinkedListSequence<MyInt>* genListFromArrayMyInt() {
	auto arr = genArrPtrMyInt(arrInt, globalLengthOfArray);
	return new LinkedListSequence<MyInt>(arr, globalLengthOfArray);
}

LinkedListSequence<MyInt>* genListFromSortedArrayMyInt() {
	auto arr = genArrPtrMyInt(arrIntSorted, globalLengthOfArray);
	return new LinkedListSequence<MyInt>(arr, globalLengthOfArray);
}

ArraySequence<Integer>* genArraySequenceFromArrayInteger() {
	auto arr = genArrPtrInteger(arrInt, globalLengthOfArray);
	return new ArraySequence<Integer>(arr, globalLengthOfArray);
}

ArraySequence<Integer>* genArraySequenceFromSortedArrayInteger() {
	auto arr = genArrPtrInteger(arrIntSorted, globalLengthOfArray);
	return new ArraySequence<Integer>(arr, globalLengthOfArray);
}

LinkedListSequence<Integer>* genListFromArrayInteger() {
	auto arr = genArrPtrInteger(arrInt, globalLengthOfArray);
	return new LinkedListSequence<Integer>(arr, globalLengthOfArray);
}

LinkedListSequence<Integer>* genListFromSortedArrayInteger() {
	auto arr = genArrPtrInteger(arrIntSorted, globalLengthOfArray);
	return new LinkedListSequence<Integer>(arr, globalLengthOfArray);
}
int main() {
	setlocale(LC_ALL, "Rus");
	//MyTaskLR12K1C MyTask;
	//MyTask.firstMenuLR12K1C();
	const int countOfElements = 10000;
	const int countOfSteps = 10;
	ofstream test("test.txt");
	test << "Hello World!";
	test.close(); // закрываем файл
	TimeMeasurementAllSorters(countOfElements, countOfSteps, randomInteger);
}