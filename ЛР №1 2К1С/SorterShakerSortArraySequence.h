/*
*	SorterShakerSortArraySequence.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/


#pragma once
#include "SorterShakerSort.h"
#include "SwaperArraySequence.h"
template <class T, class SeqType = ArraySequence<T>>
class SorterShakerSortArraySequence : public SorterShakerSort<SeqType, T> {
private:
    SwaperArraySequence<T> Swaper;
    void Swap(SeqType* Sequence, int i, int j) override {
        Swaper.Swap(Sequence, i, j);
    }
    using SorterShakerSort<SeqType, T>::ShakerSort;
public:
    SeqType* Sort(SeqType* Sequence, int startIndex, int EndIndex) override {
        auto newSeq = Sequence->GetSubsequence(startIndex, EndIndex);
        ShakerSort(newSeq);
        return newSeq;
    }
    SeqType* Sort(SeqType* Sequence) override {
        auto newSeq = new SeqType(Sequence);
        ShakerSort(newSeq);
        return newSeq;
    }
};
