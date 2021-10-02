/*
*	SorterBatcherSort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterBatcherSort : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    void Sortdir(SeqType* Sequence, int i, int j, int dir) { //возрастание или убывание
        if (dir == (*(*Sequence)[i] > *(*Sequence)[j])) Swap(Sequence, i, j);
    }

    /* Pекурсивно сортирует последовательность в порядке возрастания
       (dir == 1), или убывания (dir == 0).
       Сортируемая последовательность начинается с младшей позиции индекса,
       параметр cnt - это количество элементов для сортировки. */
    void Merge(SeqType* Sequence, int low, int cnt, int dir) {
        if (cnt > 1) {
            int k = cnt / 2;
            for (int i = low; i < low + k; i++) Sortdir(Sequence, i, i + k, dir);
            Merge(Sequence, low, k, dir);
            Merge(Sequence, low + k, k, dir);
        }
    }

    /* Создаём последовательность рекурсивно.
       Сортируем две половинки, затем вызываем merge */
    void BatcherSort(SeqType* Sequence, int low, int cnt, int dir) {
        if (cnt > 1) {
            int k = cnt / 2;
            BatcherSort(Sequence, low, k, 1);
            BatcherSort(Sequence, low + k, k, 0);
            Merge(Sequence, low, cnt, dir);
        }
    }
public:
};
