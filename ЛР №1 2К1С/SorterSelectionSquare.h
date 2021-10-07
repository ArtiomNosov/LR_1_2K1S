/*
*	SorterSelection_sort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterSelectionSquare : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    void SelectionSquare(SeqType* Sequence)
    {
        const int size = Sequence->GetLength();
        for (int idx_i = 0; idx_i < size - 1; idx_i++)
        {
            int min_idx = idx_i;

            for (int idx_j = idx_i + 1; idx_j < size; idx_j++)
            {
                if (*(*Sequence)[idx_j] < *(*Sequence)[min_idx])
                {
                    min_idx = idx_j;
                }
            }

            if (min_idx != idx_i)
            {
                Swap(Sequence, idx_i, min_idx);
            }
        }
    }
public:
};
