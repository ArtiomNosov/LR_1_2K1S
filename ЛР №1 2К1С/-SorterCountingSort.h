/*
*	SorterCountingSort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
// Я не знаю как быть с классами. Возможно стоит их преобразовать к ключам

//#pragma once
//#include "Sorter.h"
//template <class SeqType, class T>
//class SorterCountingSort : public Sorter<SeqType> {
//private:
//    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
//
//protected:
//    void BubbleSort(SeqType* Sequence) {
//        int size = Sequence->GetLength();
//        for (int i = 0; i < size; i++) {
//            for (int j = 0; j < size - i - 1; j++) {
//                if ((*(Sequence->Get(j)) > *(Sequence->Get(j + 1)))) {
//                    Swap(Sequence, j, j + 1);
//                }
//            }
//        }
//    }
//    void CountingSort(int* array, int n, int k) {
//        int c[k + 1] = { 0 };
//        for (int i = 0; i < n; ++i) {
//            ++c[array[i]];
//        }
//
//        int b = 0;
//        for (int i = 0; i < k + 1; ++i) {
//            for (int j = 0; j < c[i]; ++j) {
//                array[b++] = i;
//            }
//        }
//    }
//public:
//};
