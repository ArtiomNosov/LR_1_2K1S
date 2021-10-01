/*
*	LinkedList.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once

#include <iostream>
using namespace std;

#pragma inline_depth(2)

#include <cassert>

template <typename T> 
class Item
{
public:
	T* data;	// Любые данные
	Item<T>* next;	//Указатель на следующиий элемент в цепочке
	Item<T>* previous;
	~Item() {
	}

	bool Equals(Item<T> *I1, Item<T> *I2) {
		return *(I1->data) == *(I2->data);
	}
};

template <typename T> 
class LinkedList
{
	Item<T>* head;	// Голова списка
	Item<T>* tail;
	int lenght;	// Длинна списка
public:
	// Конструкторы
	// Создать пустой список
	LinkedList()
	{
		head = NULL;
		tail = NULL;
		lenght = 0;
	};
	LinkedList(T** items, int count) //	Копировать элементы из переданного массива
	{
		head = NULL;
		tail = NULL;
		lenght = 0;
		for (int i = 0; i < count; i++)
		{
			Append(items[i]);
		}
	}
	LinkedList(LinkedList <T>* list)  // Копирующий конструктор
	{
		head = NULL;
		tail = NULL;
		lenght = 0;

		for (int i = 0; i < list->lenght; i++)
		{
			Append(list->Get(i));
		}
	};
	// Деструктор
	~LinkedList() {
		Item<T>* next, * start = head;
		for (int i = 0; i < lenght; i++) {
			next = start->next;
			delete start->data;
			delete start;
			start = next;
		}
	}
	// Методы
	 // Получить первый элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
	T* GetFirst() {
		assert(lenght > 0);
		return head->data;
	}
	// Получить последний элемент в списке. Может выбрасывать исключения : − IndexOutOfRange(если список пуст)
	T* GetLast() {
		assert(lenght > 0);
		return tail->data;
	}
	// Получить элемент по индексу. Может выбрасывать исключения :− IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)	
	T* Get(int index)
	{
		if (index == 0 && lenght == 0)
			return NULL;
		assert(index >= 0);
		assert(index < lenght);
		Item<T>* buf = head;
		for (int i = 0; i < index; i++) {
			buf = buf->next;
		}
		return buf->data;
	}
	T* operator[](int index) {
		return this->Get(index);
	}
	bool Equals(LinkedList<T>* L1, LinkedList<T>* L2) {
		bool flag = true;
		if (L1->GetLength() != L2->GetLength())
			return false;
		if (L1->GetLength() == 0)
			return true;
		Item<T>* I1 = L1->head;
		Item<T>* I2 = L2->head;
		flag = flag && (I1->Equals(I1, I2));
		for (int i = 0; i < L1->GetLength() - 1; i++) {
			I1 = I1->next;
			I2 = I2->next;
			flag = flag && (I1->Equals(I1, I2));
		}
		return flag;
	}
	// Получить список из всех элементов, начиная с startIndex и заканчивая endIndex.
	// Может выбрасывать исключения :− IndexOutOfRange(если хотя бы один из 
	// индексов отрицательный или больше / равен числу элементов)
	LinkedList<T>* GetSubList(int startIndex, int endIndex) {
		assert(startIndex >= 0);
		assert(endIndex <= lenght);
		LinkedList<T>* buf = new LinkedList<T>();
		for (int i = startIndex; i <= endIndex; i++)
		{
			buf->Append(Get(i));
		}
		return buf;
	}
	// Получить длину списка
	int GetLength() {
		return lenght;
	}

	void Set(int index, T* data) {
		assert(!(index == 0 && lenght == 0));
		assert(index >= 0);
		assert(index < lenght);
		Item<T>* buf = head;
		for (int i = 0; i < index; i++) {
			buf = buf->next;
		}
		// Очень надеюсь, что указатель на объект
		// пропал из области видимости в результате
		// чего был вызван деструктор объекта
		// и освобождена память :p
		buf->data = data;
	}
		// Добавляет элемент в конец списка
	void Append(T* item) {
		lenght++;	//Увеличиваем число элементов на единицу
		Item<T>* buf = new Item<T>;
		buf->next = nullptr;
		buf->data = item;
		if (head == nullptr)
		{
			head = buf;
			head->previous = nullptr;
			tail = head;
		}
		else
		{
			tail->next = buf;
			buf->previous = tail;
			tail = buf; // Смещаем хвост
		}
	}
	void Prepend(T* item) // Добавляет элемент в начало списка
	{
		lenght++;	//Увеличиваем число элементов на единицу
		Item<T>* buf = new Item<T>;
		buf->next = NULL;
		buf->data = item;
		if (head == NULL)
		{
			head = buf;
			head->previous = NULL;
			tail = head;
		}
		else
		{
			head->previous = buf;
			buf->next = head;
			head = buf; // Смещаем голову
		}
	}
	// Вставляет элемент в заданную позицию. 
	// Может выбрасывать исключения : − IndexOutOfRange(если индекс отрицательный или больше / равен числу элементов)
	void InsertAt(T* item, int index) {
		assert(index >= 0);
		assert(index < lenght); 
		Item<T>* itemBefor = GetItemPtr(index)->previous;
		if (itemBefor == NULL) {
			Append(item);
		}
		else {
			Item<T>* buf = new Item<T>;
			buf->data = item;
			buf->previous = itemBefor;
			buf->next = itemBefor->next;
			itemBefor->next->previous = buf;
			itemBefor->next = buf;
			lenght++;
		}
	}
	//Сцепляет два списка
	LinkedList<T>* Concat(LinkedList<T>* list) {
		auto result = new LinkedList<T>(this);
		for (int i = 0; i < list->lenght; i++)
			result->Append(list->Get(i));
		return result;
	}
private:
	Item<T>* GetItemPtr(int n) {
		assert(n < GetLength());
		Item<T>* s = head;
		for (int i = 0; i < n; i++) {
			s = s->next;
		}
		return s;
	}
};


