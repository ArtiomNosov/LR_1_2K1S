#pragma once
#include "SorterBubbleSort.h"
#include "SwaperLinkedListSequence.h"
template <class T, class SeqType = LinkedListSequence<T>>
class SorterBubbleSortLinkedListSequence : public SorterBubbleSort<SeqType, T> {
private:
    SwaperLinkedListSequence<T> Swaper;
    void Swap(SeqType* Sequence, int i, int j) override {
        Swaper.Swap((SeqType*)Sequence, i, j);
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