/*
*	SorterInsertionSortArraySequence.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "SorterInsertionSort.h"
#include "SwaperArraySequence.h"
template <class T, class SeqType = ArraySequence<T>>
class SorterInsertionSortArraySequence : public SorterInsertionSort<SeqType, T> {
private:
    SwaperArraySequence<T> Swaper;
    void Swap(SeqType* Sequence, int i, int j) override {
        Swaper.Swap(Sequence, i, j);
    }
    using SorterInsertionSort<SeqType, T>::InsertionSort;
public:
    SeqType* Sort(SeqType* Sequence, int startIndex, int EndIndex) override {
        auto newSeq = Sequence->GetSubsequence(startIndex, EndIndex);
        InsertionSort(newSeq);
        return newSeq;
    }
    SeqType* Sort(SeqType* Sequence) override {
        auto newSeq = new SeqType(Sequence);
        InsertionSort(newSeq);
        return newSeq;
    }
};
