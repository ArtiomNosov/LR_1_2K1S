#pragma once
#include "Sorter.h"
template <class T>
class SorterQuickSort:public Sorter<T> {
private:
    virtual void Swap(void* Sequence, int i, int j) = 0;
    /* This function takes last element as pivot, places
       the pivot element at its correct position in sorted
        array, and places all smaller (smaller than pivot)
       to left of pivot and all greater elements to right
       of pivot */
    virtual T* GetElem(void* Sequence, int i) = 0;

    int Partition(void* Sequence, int low, int high)
    {
        T* pivot = GetElem(Sequence, high);    // pivot
        int i = (low - 1);  // Index of smaller element

        for (int j = low; j <= high - 1; j++)
        {
            // If current element is smaller than or
            // equal to pivot
            if (*GetElem(Sequence, j) <= *pivot)
            {
                i++;    // increment index of smaller element
                Swap(Sequence, i, j);
            }
        }
        Swap(Sequence, i + 1, high);
        return (i + 1);
    }

    /* The main function that implements QuickSort
     arr[] --> Array to be sorted,
      low  --> Starting index,
      high  --> Ending index */
protected:
    void QuickSort(void* Sequence, int low, int high)
    {
        if (low < high)
        {
            /* pi is partitioning index, arr[p] is now
               at right place */
            int pi = Partition(Sequence, low, high);

            // Separately sort elements before
            // partition and after partition
            QuickSort(Sequence, low, pi - 1);
            QuickSort(Sequence, pi + 1, high);
        }
    }
public:
	virtual void Sort(void* Sequence, int startIndex, int EndIndex) override {
        QuickSort(Sequence, startIndex, EndIndex);
	}
};
