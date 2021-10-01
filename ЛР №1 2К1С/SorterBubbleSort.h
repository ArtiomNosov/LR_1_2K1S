#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterBubbleSort : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    void BubbleSort(SeqType* Sequence) {
        int size = Sequence->GetLength();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if ((*(Sequence->Get(j)) > *(Sequence->Get(j+1)))) {
                    Swap(Sequence, j, j + 1);
                }
            }
        }
    }
public:
};
