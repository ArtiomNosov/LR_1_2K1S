#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include "LinkedListSequence.h"
#include "TimeMeasurementSorter.h"
#include "RandomInteger.h"
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
#include "SorterQuickSortLinkedListSequence.h"
#include "SorterQuickSortArraySequence.h"
#include "SorterBubbleSortLinkedListSequence.h"
#include "SorterBubbleSortArraySequence.h"

using namespace std;
/// <summary>
/// 
/// </summary>
/// <param name="n"> - максимальное число, которое будет возвращать функция</param>
/// <returns>Число из [0, n]</returns>
int userPrint(int n = 0) {
	int print = -1, mistakesCounter = 0;
	cin >> print;
	cout << "Выберите один из пунктов\t";
	while (print < 0 || print > n) {
		mistakesCounter++;
		cout << "Неверный ввод. Выберите один из пунктов\t";
		cin >> print;
	} 
	return print;
}
template<class seqType>
void printOptions(seqType* seq) {
	if (!seq)
		return;
	int n = seq->GetLength();
	cout<<"\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ")\t" << *(seq->Get(i)) << "\n";
	}
}
template<class seqType>
void refreshMenu(seqType* seq = nullptr) {
	system("cls");
	if (!seq) {
		printOptions(seq);
	}
}
template<class seqType>
void firstMenuExample(int n, seqType* options = nullptr) {
	int currentUserPrint = -1;
	// Переменные для какой либо логики
	// Цикл для выбра
	do
	{
		printOptions(options);
		currentUserPrint = userPrint(options, n);
		cout << "Для того чтобы вернуться назад введите 0\n";
		switch (currentUserPrint)
		{
		case -1:
			break;
			// functions and menus
		default:
			break;
		}
		refreshMenu(options);
	} while (currentUserPrint != 0);
}

class MyTaskLR12K1C {
public:

	void printSequenceConsole() {
		container.PrintSequenceConsole();
		system("pause");
	}
	void printSequenceInFile(string fileName) {
		container.PrintSequenceInFile(fileName);
	}
	void firstMenuLR12K1C() {
		int currentUserPrint = -1;
		// Переменные для какой либо логики
		// Цикл для выбра
		cout << "\t Здравствуйте, вы в программе для анализа быстродействия" <<
			" сортировок и контейнеров Sequence\n";
		cout << "Выберите один из видов контейнеров\n";
		cout << "1. ArraySequence\n";
		cout << "2. LinkedListSequence\n";
		cout << "Для того чтобы завершить выполнение программы, введите 0\n";
		currentUserPrint = userPrint(2);
		if (!currentUserPrint)
			return;
		switch (currentUserPrint)
		{
		case 1:
			container.SetCurrentContainer(1);
			break;
		case 2:
			container.SetCurrentContainer(2);
			break;
		default:
			break;
		}
		refreshMenu(nulLL);
		printAndStoredDataInRunTime();
		refreshMenu(nulLL);
		if (currentUserPrint)
			firstMenuLR12K1C();
	}
	void printAndStoredDataInRunTime() {
		int currentUserPrint = -1;

		LinkedList<string>* doSmthWithSeqL = new LinkedList<string>;
		doSmthWithSeqL->Append(new string("Ввести данные с консоли"));
		doSmthWithSeqL->Append(new string("Сгенерировать случайные данные"));
		doSmthWithSeqL->Append(new string("SorterBubbleSort"));
		doSmthWithSeqL->Append(new string("SorterInsertion_binary"));
		doSmthWithSeqL->Append(new string("SorterInsertionSort"));
		doSmthWithSeqL->Append(new string("SorterQuickSort"));
		doSmthWithSeqL->Append(new string("SorterSelectionSort1"));
		doSmthWithSeqL->Append(new string("SorterSelectionSquare"));
		doSmthWithSeqL->Append(new string("SorterShakerSort"));
		doSmthWithSeqL->Append(new string("SorterShell_sort"));
		doSmthWithSeqL->Append(new string("SorterShell_sortDif"));
		// Переменные для какой либо логики
		string fileName = "";
		// Цикл для выбра
		cout << "\n1. Распечатать последовательность\n";
		cout << "2. Сохранить в файл\n";
		cout << "3. Обработать/заполнить последовательность\n";
		cout << "Для того чтобы вернуться назад введите 0\n";
		currentUserPrint = userPrint(3);
		if (!currentUserPrint)
			return;
		refreshMenu(nulLL);
		switch (currentUserPrint)
		{
		case 1:
			printSequenceConsole();
			break;
		case 2:
			cout << "Введите название файла для сохранения: ";
			while (fileName == "") {
				cin >> fileName;
			}
			printSequenceInFile(fileName);
			break;
		case 3:
			doSmthWithSeq(doSmthWithSeqL);
			break;
		default:
			break;
		}
		refreshMenu(nulLL);
		if (currentUserPrint)
			printAndStoredDataInRunTime();
	}
	void fillSeqConsole(int count) {
		container.FillSeqConsole(count);
	}
	void recordStatisicsInLogFile(string logData, string fileName) {
		const int size = 255;
		ofstream fout(fileName + ".txt", ios_base::app);
		
		fout << logData << "\n";
		fout.close(); // закрываем файл
		system("pause");
	}
	void printStatisticsAfterProcessing(string statistic) {
		cout << statistic << "\n";
	}
	template<class seqType>
	void doSmthWithSeq(seqType* options) {
		int currentUserPrint = -1;
		int countOfElements = -1;
		// Переменные для какой либо логики
		time_t startTime, endTime;
		time(&startTime);
		time(&endTime);
		char tmpbuf[128], timebuf[26], ampm[] = "AM";
		time_t ltime;
		struct tm xmas = { 0, 0, 12, 25, 11, 93 };
		errno_t err;
		_tzset();

		// Display operating system-style date and time.
		_strtime_s(tmpbuf, 128);

		// Get UNIX-style time and display as number and string.
		time(&ltime);
		err = ctime_s(timebuf, 26, &ltime);
		if (err)
		{
			printf("ctime_s failed due to an invalid argument.");
			exit(1);
		}
		string timebufString(timebuf);
		string UNIXheader("UNIX time and date:\t\t\t");
		string recordOfProcessing(UNIXheader + timebufString);
		time_t lastTimeForProcessing = -1;
		// Цикл для выбра
		printOptions(options);
		cout << "Для того чтобы вернуться назад введите 0\n";
		currentUserPrint = userPrint(options->GetLength());
		if (!currentUserPrint)
			return;
		refreshMenu(nulLL);
		switch (currentUserPrint)
		{
		case 1:
			// Заполнить Sequence с консоли
			cout << "Введите число элементов: ";
			cin >> countOfElements;
			fillSeqConsole(countOfElements);
			break;
		case 2:
			// Заполнить Sequence случайными занчениями
			cout << "Введите число элементов: ";
			cin >> countOfElements;
			container.FillSeqRandomElement(countOfElements);
			break;
		default:
			container.sorter.SetCurrentSorter(currentUserPrint);
			time(&startTime);
			container.SortSeq();

			
			break;
		}
		time(&endTime);
		lastTimeForProcessing = endTime - startTime;
		recordOfProcessing = 
			"\n" +
			recordOfProcessing +
			string("Контейнер:\t") +
			(container.GetCurrentContainer() == 1?"LinkedListSequence":"ArraySequence")+
			string("\n Количество элементов в контейнере:\t") +
			to_string(container.GetCountOfElements()) +
			string("\nВыполненная операция: ") +
			string(*(options->Get(currentUserPrint - 1))) +
			string("\nЗатраченное время: ") +
		to_string(lastTimeForProcessing);
		printStatisticsAfterProcessing(recordOfProcessing);
		recordStatisicsInLogFile(recordOfProcessing, string("logFile"));
	}

protected:
	LinkedList<string>* nulLL = nullptr;
private:
	class Container {
	public:
		void SetCurrentContainer(int n) {
			CurrentContainer = n;
		}
		int GetCurrentContainer() {
			return CurrentContainer;
		}
		void PrintSequenceConsole() {
			if (CurrentContainer < 1)
				return;
			if (CurrentContainer == 1) {
				for (int i = 0; i < LLSInteger_1->GetLength(); i++) {
					cout << i << ". " << *(LLSInteger_1->Get(i)) << "\t";
				}
			} else if(CurrentContainer == 2) {
				for (int i = 0; i < ASInteger_2->GetLength(); i++) {
					cout << i << ". " << *(ASInteger_2->Get(i)) << "\t";
				}
			}
		}
		void PrintSequenceInFile(string fileName) {
			if (CurrentContainer < 1)
				return;
			ofstream fout(fileName + ".txt");
			if (CurrentContainer == 1) {
				for (int i = 0; i < LLSInteger_1->GetLength(); i++) {
					fout << *(LLSInteger_1->Get(i)) << "\t";
				}
			}
			else if (CurrentContainer == 2) {
				for (int i = 0; i < ASInteger_2->GetLength(); i++) {
					fout << *(ASInteger_2->Get(i)) << "\t";
				}
			}
			fout.close(); // закрываем файл
			system("pause");
		}
		void FillSeqConsole(int count) {
			if (CurrentContainer < 1)
				return;
			if (CurrentContainer == 1) {
				for (int i = 0; i < count; i++) {
					Integer* buf = new Integer(0);
					cin >> *buf;
					cout << "2 - ";
					LLSInteger_1->Append(buf);
				}
			}
			else if (CurrentContainer == 2) {
				for (int i = 0; i < count; i++) {
					Integer* buf = new Integer(0);
					cin >> *buf;
					cout << "2 - ";
					ASInteger_2->Append(buf);
				}
			}
		}
		void FillSeqRandomElement(int count) {
			if (CurrentContainer < 1)
				return;
			if (CurrentContainer == 1) {
				LLSInteger_1 = 
					new LinkedListSequence<Integer>(randomInteger(count), count);
			}
			else if (CurrentContainer == 2) {
				ASInteger_2 = 
					new ArraySequence<Integer>(randomInteger(count), count);
			}
		}
		int GetCountOfElements(void) {
			if (CurrentContainer < 1)
				return -1;
			if (CurrentContainer == 1) {
				return LLSInteger_1->GetLength();
			}
			else if (CurrentContainer == 2) {
				return ASInteger_2->GetLength();
			}
		}
		void SortSeq() {
			if (sorter.CurrentSorter < 1)
				return;
			if (CurrentContainer < 1)
				return;
			if (sorter.CurrentSorter == 1) {
				if (CurrentContainer == 1) {
					LLSInteger_1 = 
						sorter.SBSLLSInteger_1->Sort(LLSInteger_1);
				}
				else if (CurrentContainer == 2) {
					ASInteger_2 =
						sorter.SBSASInteger_1->Sort(ASInteger_2);
				}
			}
			else if (sorter.CurrentSorter == 2) {
				if (CurrentContainer == 1) {
					LLSInteger_1 =
						sorter.SIBLLSInteger_2->Sort(LLSInteger_1);
				}
				else if (CurrentContainer == 2) {
					ASInteger_2 =
						sorter.SIBASInteger_2->Sort(ASInteger_2);
				}
			}
			else if (sorter.CurrentSorter == 3) {
				if (CurrentContainer == 1) {
					LLSInteger_1 =
						sorter.SISLLSInteger_3->Sort(LLSInteger_1);
				}
				else if (CurrentContainer == 2) {
					ASInteger_2 =
						sorter.SISASInteger_3->Sort(ASInteger_2);
				}
			}
			else if (sorter.CurrentSorter == 4) {
				if (CurrentContainer == 1) {
					LLSInteger_1 =
						sorter.SQSLLSInteger_4->Sort(LLSInteger_1);
				}
				else if (CurrentContainer == 2) {
					ASInteger_2 =
						sorter.SQSASInteger_4->Sort(ASInteger_2);
				}
				else if (sorter.CurrentSorter == 5) {
					if (CurrentContainer == 1) {
						LLSInteger_1 =
							sorter.SSSLLSInteger_5->Sort(LLSInteger_1);
					}
					else if (CurrentContainer == 2) {
						ASInteger_2 =
							sorter.SSSASInteger_5->Sort(ASInteger_2);
					}
				}
				else if (sorter.CurrentSorter == 6) {
					if (CurrentContainer == 1) {
						LLSInteger_1 =
							sorter.SSSqLLSInteger_6->Sort(LLSInteger_1);
					}
					else if (CurrentContainer == 2) {
						ASInteger_2 =
							sorter.SSSqASInteger_6->Sort(ASInteger_2);
					}
				}
				else if (sorter.CurrentSorter == 7) {
					if (CurrentContainer == 1) {
						LLSInteger_1 =
							sorter.SSShLLSInteger_7->Sort(LLSInteger_1);
					}
					else if (CurrentContainer == 2) {
						ASInteger_2 =
							sorter.SBShASInteger_7->Sort(ASInteger_2);
					}
				}
				else if (sorter.CurrentSorter == 8) {
					if (CurrentContainer == 1) {
						LLSInteger_1 =
							sorter.SShellSLLSInteger_8->Sort(LLSInteger_1);
					}
					else if (CurrentContainer == 2) {
						ASInteger_2 =
							sorter.SShellSASInteger_8->Sort(ASInteger_2);
					}
				}
				else if (sorter.CurrentSorter == 9) {
					if (CurrentContainer == 1) {
						LLSInteger_1 =
							sorter.SSSDLLSInteger_9->Sort(LLSInteger_1);
					}
					else if (CurrentContainer == 2) {
						ASInteger_2 =
							sorter.SSSDASInteger_9->Sort(ASInteger_2);
					}
				}
			}
		}

		class Sorter {
		public:
			void SetCurrentSorter(int n) {
				CurrentSorter = n;
			}
			// Sorters
			Sorter() {
			}
			int CurrentSorter = -1;

			// -SorterBatcherSort // 1
			// 2

			// -SorterBinaryTree // 3
			// 4

			SorterBubbleSortLinkedListSequence<Integer>* SBSLLSInteger_1 =
				new SorterBubbleSortLinkedListSequence<Integer>(); // 5
			SorterBubbleSortArraySequence<Integer>* SBSASInteger_1 =
				new SorterBubbleSortArraySequence<Integer>(); // 6

			// -SorterCountingSort // 7
			// 8

			// -SorterHeapSort // 9
			// 10

			SorterInsertion_binaryLinkedListSequence<Integer>* SIBLLSInteger_2 =
				new SorterInsertion_binaryLinkedListSequence<Integer>(); // 11
			SorterInsertion_binaryArraySequence<Integer>* SIBASInteger_2 =
				new SorterInsertion_binaryArraySequence<Integer>(); // 12

			SorterInsertionSortLinkedListSequence<Integer>* SISLLSInteger_3 =
				new SorterInsertionSortLinkedListSequence<Integer>(); // 13
			SorterInsertionSortArraySequence<Integer>* SISASInteger_3 =
				new SorterInsertionSortArraySequence<Integer>(); // 14

			SorterQuickSortLinkedListSequence<Integer>* SQSLLSInteger_4 =
				new SorterQuickSortLinkedListSequence<Integer>(); // 15
			SorterQuickSortArraySequence<Integer>* SQSASInteger_4 =
				new SorterQuickSortArraySequence<Integer>(); // 16

			SorterSelectionSortLinkedListSequence<Integer>* SSSLLSInteger_5 =
				new SorterSelectionSortLinkedListSequence<Integer>(); // 17
			SorterSelectionSortArraySequence<Integer>* SSSASInteger_5 =
				new SorterSelectionSortArraySequence<Integer>(); // 18

			SorterSelectionSquareLinkedListSequence<Integer>* SSSqLLSInteger_6 =
				new SorterSelectionSquareLinkedListSequence<Integer>(); // 19
			SorterSelectionSquareArraySequence<Integer>* SSSqASInteger_6 =
				new SorterSelectionSquareArraySequence<Integer>(); // 20

			SorterShakerSortLinkedListSequence<Integer>* SSShLLSInteger_7 =
				new SorterShakerSortLinkedListSequence<Integer>(); // 21
			SorterShakerSortArraySequence<Integer>* SBShASInteger_7 =
				new SorterShakerSortArraySequence<Integer>(); // 22

			SorterShell_sortLinkedListSequence<Integer>* SShellSLLSInteger_8 =
				new SorterShell_sortLinkedListSequence<Integer>(); // 23
			SorterShell_sortArraySequence<Integer>* SShellSASInteger_8 =
				new SorterShell_sortArraySequence<Integer>(); // 24

			SorterShell_sortDifLinkedListSequence<Integer>* SSSDLLSInteger_9 =
				new SorterShell_sortDifLinkedListSequence<Integer>(); // 25
			SorterShell_sortDifArraySequence<Integer>* SSSDASInteger_9 =
				new SorterShell_sortDifArraySequence<Integer>(); // 26

		protected:
		private:
			Sorter** SortersArraySequence = nullptr;
			Sorter** SortersLinkedListSequence = nullptr;
			// -SorterMerge_sort
		} sorter;
	protected:
		
	private:
		// Containers
		int CurrentContainer = -1;
		// LinkedListSequence<T>
		LinkedListSequence<Integer>* LLSInteger_1 = 
			new LinkedListSequence<Integer>(); // 1
		// ArraySequence<T>
		ArraySequence<Integer>* ASInteger_2 = 
			new ArraySequence<Integer>(); // 2
	} container;
};
// 1. Выбор между ArraySequence and LinkedListSequence


// 2. Выбор ими хранимых данных Integer...
// после этого момента всегда есть опция вывести на экран содержимое или напечатать в файл
// Обновить данные, Выбор способа ввода - ручной, автоматический
// Выбор оброботки, всегда выводятся данные об данной обработке по времени, 
// типу операции, количестве элементов и вносятся в таблицу
