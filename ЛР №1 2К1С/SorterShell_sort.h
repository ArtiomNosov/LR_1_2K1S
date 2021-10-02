/*
*	SorterShell_sort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterShell_sort : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    void Shell_sort(SeqType* Sequence) {
        int size = Sequence->GetLength();
        for (int s = size / 2; s > 0; s /= 2) {
            for (int i = 0; i < size; i++) {
                for (int j = i + s; j < size; j += s) {
                    if (*(*Sequence)[i] > *(*Sequence)[j]) {
                        Swap(Sequence, i, j);
                    }
                }
            }
        }
    }
public:
};
