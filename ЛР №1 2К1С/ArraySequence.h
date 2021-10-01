/*
*	
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once

#include "DynamicArray.h"
#include "Sequence.h"

template <class T>
class ArraySequence : public Sequence<T>
{
private:
protected:
	DynamicArray<T>* Items;
public:
	// Конструкторы:
	ArraySequence() {
		Items = new DynamicArray<T>();
	}
	ArraySequence(T** arr, int count) {
		Items = new DynamicArray<T>();
		Items->Resize(count);
		for (int i = 0; i < count; i++)
		{
			Items->Set(i, arr[i]);
		}
	} // Копировать элементы из переданного массива
	ArraySequence(ArraySequence <T>* list)
	{
		Items = new DynamicArray<T>();
		Items->Resize(list->GetLength());
		for (int i = 0; i < (list->GetLength()); i++)
		{
			Items->Set(i, list->Get(i));
		}
	}// Создать на основе другого - Копирующий конструктор

	//Операции из Sequence
	T* GetFirst()
	{
		return this->Get(0);
	}
	T* GetLast()
	{
		return this->Get(Items->GetSize() - 1);
	}
	T* Get(int index)
	{
		return Items->Get(index);
	}
	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex)
	{
		ArraySequence<T>* buf = new ArraySequence<T>();
		int dif = endIndex - startIndex + 1;
		buf->Resize(dif);
		for (int i = 0; i < dif; i++)
		{
			buf->Set(i, this->Get(startIndex + i));
		}
		return buf;
	}
	int GetLength()
	{
		return Items->GetSize();
	}
	void Set(int index, T* value) // Задать элемент по индексу. Может выбросить IndexOutOfRange
	{
		Items->Set(index, value);
	}

	// Добавляет элемент в конец списка
	// TODO: Сделать реализацию без resize в Append, Prepend, InsertAt
	void Append(T* item)
	{
		Items->Resize(Items->GetSize() + 1);
		Items->Set(Items->GetSize() - 1, item);
	}
	// Добавляет элемент в начало списка

	// TODO: Подумать над балансировкой массива.
	void Prepend(T* item)
	{
		Items->ResizeRight(Items->GetSize() + 1);
		Items->Set(0, item);
	}
	// Вставляет элемент в заданную позицию
	void InsertAt(T* item, int index)
	{
		int newLenght = this->GetLength() + 1;
		this->Resize(newLenght);
		T* buf;
		int dif = newLenght - index - 1;
		for (int i = 0; i < dif; i++)
		{
			buf = this->Get(newLenght - i - 2);
			this->Set(newLenght - i - 1, buf);
		}
		this->Set(index, item);
	}
	Sequence <T>* Concat(Sequence <T>* list)
	{
		Sequence <T>* buf = new ArraySequence<T>();
		int oldLenght = this->GetLength();
		for (int i = 0; i < GetLength(); i++)
			buf->Append(Get(i));
		for (int i = 0; i < ((ArraySequence <T>*)list)->GetLength(); i++)
			buf->Append(((ArraySequence <T>*)list)->Get(i));
		return buf;
	}
	void Resize(int newSize) {
		Items->Resize(newSize);
	}
	void ResizeRight(int newSize) {
		Items->ResizeRight(newSize);
	}
	// Перегруженные операторы
	T* operator[](int index) {
		return Get(index);
	}

	bool operator==(ArraySequence<T>& right){
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

//template<class T>
