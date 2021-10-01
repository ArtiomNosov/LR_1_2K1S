/*
*	SorterQuickSort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterQuickSort:public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
    /* This function takes last element as pivot, places
       the pivot element at its correct position in sorted
        array, and places all smaller (smaller than pivot)
       to left of pivot and all greater elements to right
       of pivot */
    virtual T* GetElem(SeqType* Sequence, int i) = 0; // Я не понимаю зачем это мнетод, если он должен быть у Sequence

    int Partition(SeqType* Sequence, int low, int high)
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
    void QuickSort(SeqType* Sequence, int low, int high)
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
};
