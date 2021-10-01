/*
*	Sorter.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
template <class SeqType>
class Sorter {
private:
public:
	virtual SeqType* Sort(SeqType* Sequence) = 0;
	virtual SeqType* Sort(SeqType* Sequence, int startIndex, int EndIndex) = 0;
};
