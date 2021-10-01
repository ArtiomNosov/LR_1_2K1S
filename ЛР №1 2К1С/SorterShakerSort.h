/*
*	SorterShakerSort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterShakerSort : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
	void ShakerSort(SeqType* Sequence) {
		int control = Sequence->GetLength() - 1;
		int left = 0;
		int right = Sequence->GetLength() - 1;
		do {
			for (int i = left; i < right; i++) {
				if ((*(*Sequence)[i] > *(*Sequence)[i + 1])) {
					Swap(Sequence, i, i + 1);
					control = i;
				}
			}
			right = control;
			for (int i = right; i > left; i--) {
				if (*(*Sequence)[i] < *(*Sequence)[i - 1]) {
					Swap(Sequence, i, i - 1);
					control = i;
				}
			}
			left = control;
		} while (left < right);
	}
public:
};
