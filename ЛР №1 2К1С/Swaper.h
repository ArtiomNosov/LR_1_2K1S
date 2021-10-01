/*
*	Swaper.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/

#pragma once
template <class T>
class Swaper {
private:
public:
	virtual void Swap(void* Sequence, int i, int j) = 0;
};
