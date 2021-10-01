/*
*	SorterInsertionSort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterInsertionSort : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    void InsertionSort(SeqType* Sequence) {
        int counter = 0;
        int size = Sequence->GetLength();
        for (int i = 1; i < size; i++) {
            for (int j = i; j > 0 && (*((*Sequence)[j - 1]) > *((*Sequence)[j])); j--) {
                counter++;
                Swap(Sequence, j, j - 1);
            }
        }
    }
public:
};
