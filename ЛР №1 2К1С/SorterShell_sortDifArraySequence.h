/*
*	SorterShell_sortDifArraySequence.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "SorterShell_sortDif.h"
#include "SwaperArraySequence.h"
template <class T, class SeqType = ArraySequence<T>>
class SorterShell_sortDifArraySequence : public SorterShell_sortDif<SeqType, T> {
private:
    SwaperArraySequence<T> Swaper;
    void Swap(SeqType* Sequence, int i, int j) override {
        Swaper.Swap(Sequence, i, j);
    }
    using SorterShell_sortDif<SeqType, T>::Shell_sort;
public:
    SorterShell_sortDifArraySequence (int (*newFirst)(int), int (*newDif)(int)):
        SorterShell_sortDif<SeqType, T>(newFirst, newDif){}
    SorterShell_sortDifArraySequence():
        SorterShell_sortDif<SeqType, T>(){}
    SeqType* Sort(SeqType* Sequence, int startIndex, int EndIndex) override {
        auto newSeq = Sequence->GetSubsequence(startIndex, EndIndex);
        Shell_sort(newSeq);
        return newSeq;
    }
    SeqType* Sort(SeqType* Sequence) override {
        auto newSeq = new SeqType(Sequence);
        Shell_sort(newSeq);
        return newSeq;
    }
};
