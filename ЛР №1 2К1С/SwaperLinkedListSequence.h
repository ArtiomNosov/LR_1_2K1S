/*
*	SwaperLinkedListSequence.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "LinkedListSequence.h"
template <class T>
class SwaperLinkedListSequence {
private:
public:
	void Swap(LinkedListSequence<T>* Sequence, int i, int j) {
		T* buf = Sequence->Get(i);
		Sequence->Set(i, Sequence->Get(j));
		Sequence->Set(j, buf);
	}
};