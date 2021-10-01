/*
*	BoostTest.cpp
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#define BOOST_TEST_MODULE base_functional
#include <boost/test/included/unit_test.hpp>

#include "LinkedListSequence.h"
#include "Integer.h"
#include "ArraySequence.h"
#include "SorterQuickSortLinkedListSequence.h"
#include "SorterBubbleSortLinkedListSequence.h"
#include "SorterBubbleSortArraySequence.h"
#include "SwaperLinkedListSequence.h"
#include "SwaperArraySequence.h"

ArraySequence<Integer>* genArrayFromArrayInteger();
ArraySequence<Integer>* genArrayFromSortedArrayInteger();

BOOST_AUTO_TEST_SUITE(TEST_LinkedListSequence)

const int globalLengthOfArray = 10;
int arrInt[globalLengthOfArray] =		{ 1, 4, 5, 5, 3, 6, 4, 1, 9, 7 };
int arrIntSorted[globalLengthOfArray] = { 1, 1, 3, 4, 4, 5, 5, 6, 7, 9 };
#define OneIntPtr auto oneIntPtr = new int; *oneIntPtr = arrInt[0];

int* newInt(int n) {
	int* r = new int;
	*r = n;
	return r;
}

auto genArrPtrInt(int* arr, const int l) {
	int** r = new int*[l];
	for (int i = 0; i < l; i++)
		r[i] = newInt(arr[i]);
	return r;
}

auto genArrPtrInteger(int* arr, const int l) {
	Integer** r = new Integer* [l];
	for (int i = 0; i < l; i++)
		r[i] = new Integer(arr[i]);
	return r;
}

auto whereTestFunc(int* intPtr) {
	return *intPtr > 5;
}

LinkedListSequence<int>* genListFromArray() {
	auto arr = genArrPtrInt(arrInt, globalLengthOfArray);
	return new LinkedListSequence<int>(arr, globalLengthOfArray);
}

LinkedListSequence<int>* genListFromSortedArray() {
	auto arr = genArrPtrInt(arrIntSorted, globalLengthOfArray);
	return new LinkedListSequence<int>(arr, globalLengthOfArray);
}

LinkedListSequence<Integer>* genListFromArrayInteger() {
	auto arr = genArrPtrInteger(arrInt, globalLengthOfArray);
	return new LinkedListSequence<Integer>(arr, globalLengthOfArray);
}

LinkedListSequence<Integer>* genListFromSortedArrayInteger() {
	auto arr = genArrPtrInteger(arrIntSorted, globalLengthOfArray);
	return new LinkedListSequence<Integer>(arr, globalLengthOfArray);
}

	BOOST_AUTO_TEST_CASE(test_copyConstructor) {
		LinkedListSequence<int>* L1 = genListFromArray();
		LinkedListSequence<int>* L2 = new LinkedListSequence<int>(L1);
		BOOST_TEST((L1->Equals(L2)));
	}

	BOOST_AUTO_TEST_CASE(test_ConstructorFromArray) {
		LinkedListSequence<int>* L1 = genListFromArray();
		LinkedListSequence<int>* L2 = new LinkedListSequence<int>(L1);
		BOOST_TEST((L1->Equals(L2)));
	}

	BOOST_AUTO_TEST_CASE(test_baseConstructor) {
		LinkedListSequence<int>* L1 = genListFromArray();
		BOOST_TEST((1==1));
		delete L1;
	}

	BOOST_AUTO_TEST_CASE(test_Destructor) {
		// I don't know how chek it.
	}

	BOOST_AUTO_TEST_CASE(test_GetFirst) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto L2 = L1->GetSubsequence(1, L1->GetLength() - 1);
		OneIntPtr;
		L1->Prepend(oneIntPtr);
		BOOST_TEST((*(L1->GetFirst()) == *(oneIntPtr)));
		BOOST_TEST((*(L1->GetFirst()) != *(L2->GetFirst())));
	}

	BOOST_AUTO_TEST_CASE(test_GetLast) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto L2 = L1->GetSubsequence(0, L1->GetLength() - 2);
		BOOST_TEST((L1->GetLast() != L2->GetLast()));
	}

	BOOST_AUTO_TEST_CASE(test_Get) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto L2 = L1->GetSubsequence(1, L1->GetLength() - 1);
		BOOST_TEST((L1->Get(1) == L2->Get(0)));
		BOOST_TEST((L1->Get(2) != L2->Get(2)));
	}

	BOOST_AUTO_TEST_CASE(test_GetSubsequence) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto* L2 = L1->GetSubsequence(0, 1);
		BOOST_TEST((L1->Get(0) == L2->Get(0)));
		L2 = L1->GetSubsequence(0, -1);
		BOOST_TEST((L2->GetLength() == 0));
	}

	BOOST_AUTO_TEST_CASE(test_GetLength) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto* L2 = L1->GetSubsequence(0, 0);
		BOOST_TEST((L2->GetLength() == 1));
		BOOST_TEST((L1->GetLength() == globalLengthOfArray));
	}

	BOOST_AUTO_TEST_CASE(test_Set) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto* L2 = L1->GetSubsequence(0, 1);
		L2->Set(0, L1->Get(L1->GetLength() - 1));
		BOOST_TEST((L2->Get(0) == L1->Get(L1->GetLength() - 1)));
	}

	BOOST_AUTO_TEST_CASE(test_Append) {
		LinkedListSequence<int>* L1 = genListFromArray();
		OneIntPtr;
		L1->Append(oneIntPtr);
		BOOST_TEST((L1->Get(L1->GetLength() - 1) == oneIntPtr));
	}

	BOOST_AUTO_TEST_CASE(test_Prepend) {
		LinkedListSequence<int>* L1 = genListFromArray();
		OneIntPtr;
		L1->Prepend(oneIntPtr);
		BOOST_TEST((L1->Get(0) == oneIntPtr));
	}

	BOOST_AUTO_TEST_CASE(test_InsertAt) {
		LinkedListSequence<int>* L1 = genListFromArray();
		OneIntPtr;
		L1->InsertAt(oneIntPtr, 4);
		BOOST_TEST((L1->Get(4) == oneIntPtr));
	}

	BOOST_AUTO_TEST_CASE(test_Concat) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto L2 = L1->GetSubsequence(0, 0);
		OneIntPtr;
		L2->Append(oneIntPtr);
		auto L3 = L1->Concat(L2);
		BOOST_TEST((L3->Get(0) == L1->Get(0)));
		BOOST_TEST((L3->Get(L1->GetLength()) == L1->Get(0)));
		BOOST_TEST((L3->Get(L1->GetLength() + 1) == oneIntPtr));
	}

	BOOST_AUTO_TEST_CASE(test_Where) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto L2 = L1->Where(whereTestFunc);
		int n = 0;
		for (int i = 0; i < L2->GetLength(); i++) {
			BOOST_TEST(*(L2->Get(i)) > 5);
			n++;
		}
		BOOST_TEST(n == 3);
	}

	BOOST_AUTO_TEST_CASE(test_Equals) {
		LinkedListSequence<int>* L1 = genListFromArray();
		auto L2 = L1->GetSubsequence(0, L1->GetLength() - 1);
		BOOST_TEST((L1->Equals(L2)));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TEST_DynamicArray)
using namespace TEST_LinkedListSequence;

Integer* mupFuncComplex(Integer* a)
{
	return *a * *a;
}

bool whereFunc(Integer* a)
{
	Integer d{ 2 };
	return (*a == d);
}

DynamicArray<Integer>* genArrayFromArrayInteger() {
	auto arr = genArrPtrInteger(arrInt, globalLengthOfArray);
	return new DynamicArray<Integer>(arr, globalLengthOfArray);
}

BOOST_AUTO_TEST_CASE(test_ResizeRight)
{
	auto DynArr1 = genArrayFromArrayInteger();

	DynArr1->ResizeRight(11);
	DynArr1->Set(DynArr1->GetSize() - 1, new Integer(77));

	BOOST_CHECK(DynArr1->GetSize() == 11);
	BOOST_CHECK((((DynArr1->Get(10))->GetNumber()) == 77));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TEST_ArraySequence)

using namespace TEST_LinkedListSequence;

ArraySequence<Integer>* genArraySequenceFromArrayInteger() {
	auto arr = genArrPtrInteger(arrInt, globalLengthOfArray);
	return new ArraySequence<Integer>(arr, globalLengthOfArray);
}

ArraySequence<Integer>* genArraySequenceFromSortedArrayInteger() {
	auto arr = genArrPtrInteger(arrIntSorted, globalLengthOfArray);
	return new ArraySequence<Integer>(arr, globalLengthOfArray);
}

BOOST_AUTO_TEST_CASE(test_ConstructorFromArray)
{
	auto ASeq = genArraySequenceFromArrayInteger();
	for (int i = 0; i < ASeq->GetLength(); i++) {
		BOOST_CHECK((ASeq->Get(i))->GetNumber() == arrInt[i]);
	}
}

BOOST_AUTO_TEST_CASE(test_copyConstructor) {
	auto ASeq_1 = genArraySequenceFromArrayInteger();
	auto ASeq_2 = new ArraySequence<Integer>(*ASeq_1);
	for (int i = 0; i < ASeq_1->GetLength(); i++)
	{
		BOOST_CHECK(ASeq_1->Get(i) == ASeq_2->Get(i));
	}
}
BOOST_AUTO_TEST_CASE(test_GetFirst) {
	auto ASeq = genArraySequenceFromArrayInteger();
	BOOST_CHECK(ASeq->GetFirst()->GetNumber() == arrInt[0]);
}
BOOST_AUTO_TEST_CASE(test_GetLast) {
	auto ASeq = genArraySequenceFromArrayInteger();
	BOOST_CHECK(ASeq->GetLast()->GetNumber() == arrInt[globalLengthOfArray - 1]);
}
BOOST_AUTO_TEST_CASE(test_Get) {
	auto ASeq = genArraySequenceFromArrayInteger();
	for (int i = 0; i < ASeq->GetLength(); i++) {
		BOOST_CHECK((ASeq->Get(i))->GetNumber() == arrInt[i]);
	}
	BOOST_CHECK(ASeq->Get(0) == ASeq->GetFirst());
	BOOST_CHECK(ASeq->Get(ASeq->GetLength() - 1) == ASeq->GetLast());
}
BOOST_AUTO_TEST_CASE(test_GetSubsequence) {
	auto ASeq = genArraySequenceFromArrayInteger();
	auto SubASeq = ASeq->GetSubsequence(1, ASeq->GetLength() / 2);
	BOOST_CHECK(SubASeq->GetLength() == ASeq->GetLength() / 2);
	for (int i = 0; i < ASeq->GetLength() / 2; i++) {
		BOOST_CHECK(((SubASeq->Get(i))->GetNumber() == arrInt[i + 1]));
	}
}
BOOST_AUTO_TEST_CASE(test_GetLength) {
	auto ASeq = genArraySequenceFromArrayInteger();
	BOOST_CHECK(ASeq->GetLength() == globalLengthOfArray);
	ASeq->Resize(0);
	BOOST_CHECK(ASeq->GetLength() == 0);
}
BOOST_AUTO_TEST_CASE(test_Set) {
	auto ASeq = genArraySequenceFromArrayInteger();
	ASeq->Set(0, ASeq->GetLast());
	BOOST_CHECK(ASeq->GetFirst() == ASeq->GetLast());
}
BOOST_AUTO_TEST_CASE(test_Append) {
	auto ASeq = genArraySequenceFromArrayInteger();
	ASeq->Append(ASeq->GetFirst());
	BOOST_CHECK(ASeq->Get(globalLengthOfArray) == ASeq->GetFirst());
}
BOOST_AUTO_TEST_CASE(test_Prepend) {
	auto ASeq = genArraySequenceFromArrayInteger();
	ASeq->Prepend(ASeq->GetFirst());
	BOOST_CHECK(ASeq->Get(0) == ASeq->GetFirst());
}
BOOST_AUTO_TEST_CASE(test_InsertAt) {
	auto ASeq = genArraySequenceFromArrayInteger();
	auto elemInsert = new Integer(ASeq->GetLast()->GetNumber() + ASeq->GetFirst()->GetNumber() + 77);
	auto elem0 = ASeq->GetFirst();
	auto elem1 = ASeq->Get(1);

	ASeq->InsertAt(elemInsert, 1);

	BOOST_CHECK(globalLengthOfArray + 1 == ASeq->GetLength());
	BOOST_CHECK(ASeq->GetFirst() == elem0);
	BOOST_CHECK(ASeq->Get(1) == elemInsert);
	BOOST_CHECK(ASeq->Get(2) == elem1);
}
BOOST_AUTO_TEST_CASE(test_Concat) {
	auto ASeq_1 = genArraySequenceFromArrayInteger();
	auto ASeq_2 = ASeq_1->GetSubsequence(1, ASeq_1->GetLength() / 2);

	Sequence<Integer>* ASeq_concat = ASeq_1->Concat(ASeq_2);

	for (int i = 0; i < ASeq_1->GetLength(); i++)
	{
		BOOST_CHECK(ASeq_concat->Get(i) == ASeq_1->Get(i));
	}
	for (int i = 0; i < ASeq_2->GetLength(); i++)
	{
		BOOST_CHECK(ASeq_concat->Get(i + ASeq_1->GetLength()) == ASeq_2->Get(i));
	}
	ASeq_concat = ASeq_2->Concat(ASeq_1);
	for (int i = 0; i < ASeq_2->GetLength(); i++)
	{
		BOOST_CHECK(ASeq_concat->Get(i) == ASeq_2->Get(i));
	}
	for (int i = 0; i < ASeq_1->GetLength(); i++)
	{
		BOOST_CHECK(ASeq_concat->Get(ASeq_2->GetLength() + i) == ASeq_1->Get(i));
	}
}
BOOST_AUTO_TEST_CASE(test_Resize) {
	auto ASeq_1 = genArraySequenceFromArrayInteger();
	for (int i = 0; i < globalLengthOfArray; i++) {
		BOOST_CHECK(ASeq_1->GetLast()->GetNumber() == arrInt[globalLengthOfArray - 1 - i]);
		ASeq_1->Resize(globalLengthOfArray - 1 - i);
	}
	BOOST_CHECK(ASeq_1->GetLength() == 0);
}
BOOST_AUTO_TEST_CASE(test_Equals) {
	auto ASeq_1 = genArraySequenceFromArrayInteger();
	auto ASeq_2 = ASeq_1->GetSubsequence(0, ASeq_1->GetLength() - 1);
	BOOST_TEST((*ASeq_1) == (*ASeq_2));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TEST_SwaperLinkedListSequence)
	using namespace TEST_LinkedListSequence;
	BOOST_AUTO_TEST_CASE(test_SwaperLinkedListSequence_Swap) {
		auto L1 = genListFromArrayInteger();
		auto L2 = L1->GetSubsequence(0, 1);
		auto swaper = new SwaperLinkedListSequence<Integer>();
		swaper->Swap(L2, 0, 1);
		BOOST_TEST(L1->Get(0) == L2->Get(1));
		BOOST_TEST(L1->Get(1) == L2->Get(0));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TEST_SwaperArraySequence)
using namespace TEST_ArraySequence;
BOOST_AUTO_TEST_CASE(test_SwaperArraySequence_Swap) {
	auto ASeq_1 = genArraySequenceFromArrayInteger();
	auto ASeq_2 = ASeq_1->GetSubsequence(0, 1);
	auto swaper = new SwaperArraySequence<Integer>();
	swaper->Swap(ASeq_2, 0, 1);
	BOOST_TEST(ASeq_1->Get(0) == ASeq_2->Get(1));
	BOOST_TEST(ASeq_1->Get(1) == ASeq_2->Get(0));
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TEST_SorterQuickSortLinkedListSequence)
	using namespace TEST_LinkedListSequence;
	BOOST_AUTO_TEST_CASE(SorterQuickSortLinkedListSequence_test_Sort) {
		LinkedListSequence<Integer>* L1 = genListFromArrayInteger();
		auto sorter = new SorterQuickSortLinkedListSequence<Integer>();
		auto L2 = sorter->Sort(L1, 0, L1->GetLength() - 1);
		L1 = genListFromSortedArrayInteger();
		BOOST_TEST(L1->Equals(L2));
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TEST_SorterQuickSortArraySequence)
	using namespace TEST_ArraySequence;
	BOOST_AUTO_TEST_CASE(SorterQuickSortArraySequence_test_Sort) {
		ArraySequence<Integer>* L1 = genArraySequenceFromArrayInteger();
		auto sorter = new SorterBubbleSortArraySequence<Integer>();
		auto L2 = sorter->Sort(L1, 0, L1->GetLength() - 1);
		L1 = genArraySequenceFromSortedArrayInteger();
		BOOST_TEST(*L1 = *L2);
	}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(SorterBubbleSortLinkedListSequence_test_Sort)
	using namespace TEST_LinkedListSequence;
	BOOST_AUTO_TEST_CASE(TEST_SorterBubbleSortLinkedListSequence) {
		LinkedListSequence<Integer>* L1 = genListFromArrayInteger();
		auto sorter = new SorterBubbleSortLinkedListSequence<Integer>();
		auto L2 = sorter->Sort(L1, 0, L1->GetLength() - 1);
		L1 = genListFromSortedArrayInteger();
		BOOST_TEST(L1->Equals(L2));
	}
BOOST_AUTO_TEST_SUITE_END()
