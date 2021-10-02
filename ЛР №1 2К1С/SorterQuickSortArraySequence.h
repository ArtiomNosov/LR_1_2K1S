/*
*	SorterQuickSortArraySequence.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "SorterQuickSort.h"
#include "SwaperArraySequence.h"
template <class T, class SeqType = ArraySequence<T>>
class SorterQuickSortArraySequence : public SorterQuickSort<SeqType, T> {
private:
    SwaperArraySequence<T> Swaper;
    void Swap(SeqType* Sequence, int i, int j) override {
        Swaper.Swap(Sequence, i, j);
    }
    T* GetElem(SeqType* Sequence, int i) override {
        return ((SeqType*)Sequence)->Get(i);
    }
    using SorterQuickSort<SeqType, T>::QuickSort;
public:
    SeqType* Sort(SeqType* Sequence, int startIndex, int EndIndex) override {
        auto newSeq = Sequence->GetSubsequence(startIndex, EndIndex);
        QuickSort(newSeq, startIndex, EndIndex);
        return newSeq;
    }
    SeqType* Sort(SeqType* Sequence) override {
        auto newSeq = new SeqType(Sequence);
        QuickSort(newSeq, 0, ((SeqType*)Sequence)->GetLength() - 1);
        return newSeq;
    }
};
