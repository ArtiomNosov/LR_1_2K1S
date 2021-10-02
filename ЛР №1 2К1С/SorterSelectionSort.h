/*
*	SorterSelectionSort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterSelectionSort : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    // Функция сортировки прямым выбором
    void SelectionSort(SeqType* Sequence)
    {
        int size = Sequence->GetLength();
        int min, temp; // для поиска минимального элемента и для обмена
        for (int i = 0; i < size - 1; i++)
        {
            min = i; // запоминаем индекс текущего элемента
            // ищем минимальный элемент чтобы поместить на место i-ого
            for (int j = i + 1; j < size; j++)  // для остальных элементов после i-ого
            {
                if (*(*Sequence)[j] < *(*Sequence)[min]) // если элемент меньше минимального,
                    min = j;       // запоминаем его индекс в min
            }
            Swap(Sequence, i, min);// меняем местами i-ый и минимальный элементы
        }
    }
public:
};
