#pragma once
#include "SorterQuickSort.h"
#include "SwaperLinkedListSequence.h"
template <class T>
class SorterQuickSortLinkedListSequence: public SorterQuickSort<T> {
private:
    SwaperLinkedListSequence<T> Swaper;
    void Swap(void* Sequence, int i, int j) override {
        Swaper.Swap((LinkedListSequence<T>*)Sequence, i, j);
    }
    T* GetElem(void* Sequence, int i) override {
        return ((LinkedListSequence<T>*)Sequence)->Get(i);
    }
    using SorterQuickSort<T>::QuickSort;
public:
    void Sort(void* Sequence, int startIndex, int EndIndex) override {
        QuickSort(Sequence, startIndex, EndIndex);
    }
    void Sort(void* Sequence) override {
        QuickSort(Sequence, 0, ((LinkedListSequence<T>*)Sequence)->GetLength()-1);
    }
};