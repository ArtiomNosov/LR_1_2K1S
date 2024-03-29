/*
*	LinkedListSequence.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sequence.h"
#include "LinkedList.h"

template <class T>
class LinkedListSequence : public Sequence<T>
{
private:
	LinkedList<T>* internalList;
protected:
	LinkedListSequence(LinkedList<T>* newIternalList):
		internalList(newIternalList)
	{
	};
public:
		// ������������
	// ���������� �����������
	LinkedListSequence(LinkedListSequence <T>* list) {
		internalList = new LinkedList<T>(list->internalList);
	};
	LinkedListSequence(Sequence <T>* list) {
		internalList = new LinkedList<T>(((LinkedListSequence <T>*)list)->internalList);
	};
	LinkedListSequence() {
		internalList = new LinkedList<T>();
	};
	LinkedListSequence(T** items, int count)
	{
		internalList = new LinkedList<T>(items, count);
	};
	// ����������
	~LinkedListSequence() {

	}

	T* GetFirst() {
		return internalList->GetFirst();
	}
	T* GetLast() {
		return internalList->GetLast();
	}
	T* Get(int index) {
		return internalList->Get(index);
	}
	LinkedListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
		LinkedList<T>* bufList = internalList->GetSubList(startIndex, endIndex);
		return new LinkedListSequence<T>(bufList);
	}
	int GetLength() {
		return internalList->GetLength();
	}
	void Set(int index, T* data) {
		internalList->Set(index, data);
	}
	void Append(T* item) {
		internalList->Append(item);
	}
	void Prepend(T* item) {
		internalList->Prepend(item);
	}
	void InsertAt(T* item, int index) {
		internalList->InsertAt(item, index);
	}
	Sequence <T>* Concat(Sequence <T>* list) {
		auto result = new LinkedListSequence<T>(this);
		for (int i = 0; i < list->GetLength(); i++) {
			result->Append(list->Get(i));
		}
		return (Sequence <T>*)result;
	}
	LinkedListSequence<T>* Where(bool (*whereFunc)(T*)) {
		LinkedListSequence<T>* buf = new LinkedListSequence<T>;
		for (int i = 0; i < this->GetLength(); i++) {
			if (whereFunc(this->Get(i))) buf->Append(this->Get(i));
		}
		return buf;
	}
	// ���������� ����������
	bool Equals(LinkedListSequence<T>* L2) {
		return (internalList->Equals(internalList, L2->internalList));
	}
	// ������������� ���������
	T* operator[](int index) {
		return Get(index);
	}
	bool operator==(LinkedListSequence<T>& right) {
		bool result = true, flag = false;
		T* item_1 = nullptr;
		T* item_2 = nullptr;
		int Len_1 = this->GetLength();
		int Len_2 = right.GetLength();
		if (Len_1 != Len_2) {
			return false;
		}
		for (int i = 0; i < Len_1; i++) {
			item_1 = this->Get(i);
			item_2 = right.Get(i);
			flag = ((*(item_1)) == (*(item_2)));
			result &= flag;
		}
		return result;
	};
};
