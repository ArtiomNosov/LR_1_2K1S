#pragma once
template <class T>
class Sorter {
private:
public:
	virtual void Sort(void* Sequence) = 0;
	virtual void Sort(void* Sequence, int startIndex, int EndIndex) = 0;
};
