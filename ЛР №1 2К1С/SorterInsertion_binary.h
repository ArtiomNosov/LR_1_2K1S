/*
*	SorterInsertion_binary.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterInsertion_binary : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
	void Insertion_binary(SeqType* Sequence){
		int size = Sequence->GetLength();
		int lo = 0, hi = 0, mid = 0; T* key;
		for (int i = 0; i < size; i++) {
			key = (*Sequence)[i];
			lo = 0;
			hi = i - 1;
			while (lo < hi) {
				mid = lo + (hi - lo)/2;
				if (*key < *(*Sequence)[mid]) {
					hi = mid;
				}
				else {
					lo = mid + 1;
				}
			}
			for (int j = i; j > lo; j--) {
				Sequence->Set(j, (*Sequence)[j - 1]);
			}
			Sequence->Set(lo, key);
		}
		key = (*Sequence)[size - 1];
		for (int i = size - 1; i > 0; i--) {
			Sequence->Set(i, (*Sequence)[i - 1]);
		}
		Sequence->Set(0, key);
	}
public:
};
