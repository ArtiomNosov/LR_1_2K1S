/*
*	SorterSelectionSort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company: Continue
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterSelectionSort : public Sorter<SeqType> {
private:
    virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    // ������� ���������� ������ �������
    void SelectionSort(SeqType* Sequence)
    {
        int size = Sequence->GetLength();
        int min, temp; // ��� ������ ������������ �������� � ��� ������
        for (int i = 0; i < size - 1; i++)
        {
            min = i; // ���������� ������ �������� ��������
            // ���� ����������� ������� ����� ��������� �� ����� i-���
            for (int j = i + 1; j < size; j++)  // ��� ��������� ��������� ����� i-���
            {
                if (*(*Sequence)[j] < *(*Sequence)[min]) // ���� ������� ������ ������������,
                    min = j;       // ���������� ��� ������ � min
            }
            Swap(Sequence, i, min);// ������ ������� i-�� � ����������� ��������
        }
    }
public:
};
