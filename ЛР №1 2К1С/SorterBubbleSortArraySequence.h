#pragma once
#include "SorterBubbleSort.h"
#include "SwaperArraySequence.h"
template <class T, class SeqType = ArraySequence<T>>
class SorterBubbleSortArraySequence : public SorterBubbleSort<SeqType, T> {
private:
    SwaperArraySequence<T> Swaper;
    void Swap(SeqType* Sequence, int i, int j) override {
        Swaper.Swap(Sequence, i, j);
    }
    using SorterBubbleSort<SeqType, T>::BubbleSort;
public:
    SeqType* Sort(SeqType* Sequence, int startIndex, int EndIndex) override {
        auto newSeq = Sequence->GetSubsequence(startIndex, EndIndex);
        BubbleSort(newSeq);
        return newSeq;
    }
    SeqType* Sort(SeqType* Sequence) override {
        auto newSeq = new SeqType(Sequence);
        BubbleSort(newSeq);
        return newSeq;
    }
};
