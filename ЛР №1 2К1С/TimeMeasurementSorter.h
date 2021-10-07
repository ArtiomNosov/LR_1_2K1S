/*
*   TimeMeasurementSorter.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include <ctime>
#include <string>
#include <fstream>
#include "RandomInteger.h"
#include "SorterQuickSortLinkedListSequence.h"
#include "SorterQuickSortArraySequence.h"
#include "SorterBubbleSortLinkedListSequence.h"
#include "SorterBubbleSortArraySequence.h"
#include "SwaperLinkedListSequence.h"
#include "SwaperArraySequence.h"
#include "SorterShakerSortArraySequence.h"
#include "SorterShakerSortLinkedListSequence.h"
#include "SorterInsertionSortArraySequence.h"
#include "SorterInsertionSortLinkedListSequence.h"
#include "SorterSelectionSortArraySequence.h"
#include "SorterSelectionSortLinkedListSequence.h"
#include "SorterInsertion_binaryArraySequence.h"
#include "SorterInsertion_binaryLinkedListSequence.h"
#include "SorterSelectionSquareArraySequence.h"
#include "SorterSelectionSquareLinkedListSequence.h"
#include "SorterShell_sortArraySequence.h"
#include "SorterShell_sortLinkedListSequence.h"
#include "SorterShell_sortDifArraySequence.h"
#include "SorterShell_sortDifLinkedListSequence.h"
template <class T, class SorterType, class SeqType>
time_t TimeMeasurementSorterWithRandom(SeqType*& seqBefore, SeqType*& seqAfter, SorterType*& sorter, int coutOfElements, T**(*randomElements)(int)) {
	seqBefore = new SeqType(randomElements(coutOfElements), coutOfElements);
	sorter = new SorterType();
	time_t startTime;
	time(&startTime);
	seqAfter = sorter->Sort(seqBefore);
	time_t endTime;
	time(&endTime);
	return endTime - startTime;
}

template <class T, class SorterType, class SeqType>
time_t TimeMeasurementSorter(SeqType*& seqBefore, SeqType*& seqAfter, SorterType*& sorter) {
	if (!seqBefore)
		return;
	sorter = new SorterType();
	time_t startTime;
	time(&startTime);
	seqAfter = sorter->Sort(seqBefore);
	time_t endTime;
	time(&endTime);
	return endTime - startTime;
}

// Функции для оценки сложности выполнения алгоритмов сортировки (Integer)
template <class T, class SorterType, class SeqType>
void TimeMeasurementSorterWithRandomAndWriteIntoFile(SeqType*& seqBefore, SeqType*& seqAfter, SorterType*& sorter, int maxCoutOfElements, int countOfSteps, T** (*randomElements)(int)) {
	int addition = maxCoutOfElements / countOfSteps;
	time_t currentTimeOfSort = 0;
	string infoAboutCurrentMeasurment =
		string("Type of container:\t") + string(typeid(seqBefore).name());
	infoAboutCurrentMeasurment.append("\n");
	infoAboutCurrentMeasurment +=
		string("Sorter using for sort:\t") + string(typeid(sorter).name());
	infoAboutCurrentMeasurment.append("\n");
	infoAboutCurrentMeasurment +=
		string("Count of elements\tTime of processing");
	infoAboutCurrentMeasurment.append("\n");
	// create file 
	string fileName( typeid(sorter).name() );
	fileName.resize(35);
	fileName.append(".txt");
	ofstream fout(fileName.data());
	fout << infoAboutCurrentMeasurment << "\n";
	SeqType* s1 = nullptr, * s2 = nullptr; SorterType* S_0 = nullptr;
	for (int i = 0; i < maxCoutOfElements; i += addition) {
		currentTimeOfSort = TimeMeasurementSorterWithRandom(s1, s2, S_0, i, randomElements);
		infoAboutCurrentMeasurment =
			string(to_string(i));
		infoAboutCurrentMeasurment.append("\t");
		infoAboutCurrentMeasurment +=
			string(to_string(currentTimeOfSort));
		fout << infoAboutCurrentMeasurment << "\n";
	}
	seqBefore = s1;
	seqAfter = s2;
	sorter = S_0;
	fout.close(); // закрываем файл
}

// Функция для замера на всех реализованных сортировках
template <class T = Integer>
void TimeMeasurementAllSorters(int maxCoutOfElements, int countOfSteps, T** (*randomElements)(int)) {
	// SorterBubbleSortLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_1 = nullptr,* LLS_Aft_1 = nullptr;
	SorterBubbleSortLinkedListSequence<T>* S_1 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_1, LLS_Aft_1, S_1, maxCoutOfElements, countOfSteps, randomElements);
	// SorterBubbleSortArraySequence
	ArraySequence<T>* AS_Bef_2 = nullptr, *AS_Aft_2 = nullptr;
	SorterBubbleSortArraySequence<T>* S_2 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_2, AS_Aft_2, S_2, maxCoutOfElements, countOfSteps, randomElements);
	// SorterInsertion_binaryLinkedListSequence
	/*LinkedListSequence<T>* LLS_Bef_3 = nullptr, *LLS_Aft_3 = nullptr;
	SorterInsertion_binaryLinkedListSequence<T>* S_3 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_3, LLS_Aft_3, S_3, maxCoutOfElements, countOfSteps, randomElements);
	*/ // Здесь баг
	// SorterInsertion_binaryArraySequence
	/*
	ArraySequence<T>* AS_Bef_4 = nullptr, *AS_Aft_4 = nullptr;
	SorterInsertion_binaryArraySequence<T>* S_4 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_4, AS_Aft_4, S_4, maxCoutOfElements, countOfSteps, randomElements);
	*/
	// SorterInsertionSortLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_5 = nullptr, *LLS_Aft_5 = nullptr;
	SorterInsertionSortLinkedListSequence<T>* S_5 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_5, LLS_Aft_5, S_5, maxCoutOfElements, countOfSteps, randomElements);
	// SorterInsertionSortArraySequence
	ArraySequence<T>* AS_Bef_6 = nullptr,* AS_Aft_6 = nullptr;
	SorterInsertionSortArraySequence<T>* S_6 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_6, AS_Aft_6, S_6, maxCoutOfElements, countOfSteps, randomElements);
	// SorterQuickSortLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_7 = nullptr,* LLS_Aft_7 = nullptr;
	SorterQuickSortLinkedListSequence<T>* S_7 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_7, LLS_Aft_7, S_7, maxCoutOfElements, countOfSteps, randomElements);
	// SorterQuickSortArraySequence долго делает
	//ArraySequence<T>* AS_Bef_8 = nullptr,* AS_Aft_8 = nullptr;
	//SorterQuickSortArraySequence<T>* S_8 = nullptr;
	//TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_8, AS_Aft_8, S_8, maxCoutOfElements, countOfSteps, randomElements);
	// SorterSelectionSortLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_9 = nullptr,* LLS_Aft_9 = nullptr;
	SorterSelectionSortLinkedListSequence<T>* S_9 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_9, LLS_Aft_9, S_9, maxCoutOfElements, countOfSteps, randomElements);
	// SorterSelectionSortArraySequence
	ArraySequence<T>* AS_Bef_10 = nullptr,* AS_Aft_10 = nullptr;
	SorterSelectionSortArraySequence<T>* S_10 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_10, AS_Aft_10, S_10, maxCoutOfElements, countOfSteps, randomElements);
	// SorterSelectionSquareLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_11 = nullptr,* LLS_Aft_11 = nullptr;
	SorterSelectionSquareLinkedListSequence<T>* S_11 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_11, LLS_Aft_11, S_11, maxCoutOfElements, countOfSteps, randomElements);
	// SorterSelectionSquareArraySequence
	ArraySequence<T>* AS_Bef_12 = nullptr,* AS_Aft_12 = nullptr;
	SorterSelectionSquareArraySequence<T>* S_12 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_12, AS_Aft_12, S_12, maxCoutOfElements, countOfSteps, randomElements);
	// SorterShakerSortLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_13 = nullptr,* LLS_Aft_13 = nullptr;
	SorterShakerSortLinkedListSequence<T>* S_13 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_13, LLS_Aft_13, S_13, maxCoutOfElements, countOfSteps, randomElements);
	// SorterShakerSortArraySequence
	// Долго делает //ArraySequence<T>* AS_Bef_14 = nullptr,* AS_Aft_14 = nullptr;
	//SorterShakerSortArraySequence<T>* S_14 = nullptr;
	//TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_14, AS_Aft_14, S_14, maxCoutOfElements, countOfSteps, randomElements);
	// SorterShell_sortLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_15 = nullptr,* LLS_Aft_15 = nullptr;
	SorterShell_sortLinkedListSequence<T>* S_15 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_15, LLS_Aft_15, S_15, maxCoutOfElements, countOfSteps, randomElements);
	// SorterShell_sortArraySequence
	ArraySequence<T>* AS_Bef_16 = nullptr,* AS_Aft_16 = nullptr;
	SorterShell_sortArraySequence<T>* S_16 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_16, AS_Aft_16, S_16, maxCoutOfElements, countOfSteps, randomElements);
	// SorterShell_sortDifLinkedListSequence
	LinkedListSequence<T>* LLS_Bef_17 = nullptr,* LLS_Aft_17 = nullptr;
	SorterShell_sortDifLinkedListSequence<T>* S_17 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(LLS_Bef_17, LLS_Aft_17, S_17, maxCoutOfElements, countOfSteps, randomElements);
	// SorterShell_sortDifArraySequence
	ArraySequence<T>* AS_Bef_18 = nullptr,* AS_Aft_18 = nullptr;
	SorterShell_sortDifArraySequence<T>* S_18 = nullptr;
	TimeMeasurementSorterWithRandomAndWriteIntoFile(AS_Bef_18, AS_Aft_18, S_18, maxCoutOfElements, countOfSteps, randomElements);
}