/*
*	SorterShell_sort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
int sFirst(int n) {
    return n / 2;
}
int sDif(int n) {
    return n / 2;
}
template <class SeqType, class T>
class SorterShell_sortDif : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
    int (*First)(int);
    int (*Dif)(int);
protected:
    void Shell_sort(SeqType* Sequence) {
        int size = Sequence->GetLength();
        int s = size;
        for (s = First(s); s > 0; s = Dif(s)) {
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
    SorterShell_sortDif(int (*newFirst)(int), int (*newDif)(int)):
        First(newFirst), Dif(newDif)
    {

    }
    SorterShell_sortDif()
    {
        First = sFirst;
        Dif = sDif;
    }
};
