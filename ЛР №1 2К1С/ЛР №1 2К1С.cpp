#include <iostream>
#include "LinkedListSequence.h"
#include "SorterQuickSortLinkedListSequence.h"
const int globalLengthOfArray = 10;
int arrInt[globalLengthOfArray] = { 1, 4, 5, 5, 3, 6, 4, 1, 9, 7 };
int arrIntSorted[globalLengthOfArray] = { 1, 1, 3, 4, 4, 5, 5, 6, 7, 9 };

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


int main()
{
	LinkedListSequence<MyInt>* L1 = genListFromArrayMyInt();
	auto L2 = genListFromSortedArrayMyInt();
	auto sorter = new SorterQuickSortLinkedListSequence<MyInt>();
	sorter->Sort(L1, 0, L1->GetLength() - 1);
    std::cout << L1->Equals(L2) <<"\nHello world!\n";
}