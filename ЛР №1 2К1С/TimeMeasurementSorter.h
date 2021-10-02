/*
*   TimeMeasurementSorter.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include <ctime>
template <class T, class SorterType, class SeqType>
time_t TimeMeasurementSorter(SeqType*& seqBefore, SeqType*& seqAfter, SorterType*& sorter, int coutOfElements, T**(*randomElements)(int)) {
	seqBefore = new SeqType(randomElements(coutOfElements), coutOfElements);
	sorter = new SorterType();
	time_t startTime;
	time(&startTime);
	seqAfter = sorter->Sort(seqBefore);
	time_t endTime;
	time(&endTime);
	return endTime - startTime;
}