#pragma once
#include "ArraySequence.h"
template <class T>
class SwaperArraySequence {
private:
public:
	void Swap(ArraySequence<T>* Sequence, int i, int j) {
		T* buf = Sequence->Get(i);
		Sequence->Set(i, Sequence->Get(j));
		Sequence->Set(j, buf);
	}
};