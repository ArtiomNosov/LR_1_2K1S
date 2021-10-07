/*
*	SorterMerge_sort.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "Sorter.h"
template <class SeqType, class T>
class SorterMerge_sort : public Sorter<SeqType> {
private:
	virtual void Swap(SeqType* Sequence, int i, int j) = 0;
protected:
    SeqType* merge_sort(SeqType* up, SeqType* down, unsigned int left, unsigned int right)
    {
        if (left == right)
        {
            down[left] = up[left];
            return down;
        }

        unsigned int middle = (left + right) / 2;

        // раздел€й и сортируй
        int* l_buff = merge_sort(up, down, left, middle);
        int* r_buff = merge_sort(up, down, middle + 1, right);

        // сли€ние двух отсортированных половин
        int* target = l_buff == up ? down : up;

        unsigned int l_cur = left, r_cur = middle + 1;
        for (unsigned int i = left; i <= right; i++)
        {
            if (l_cur <= middle && r_cur <= right)
            {
                if (l_buff[l_cur] < r_buff[r_cur])
                {
                    target[i] = l_buff[l_cur];
                    l_cur++;
                }
                else
                {
                    target[i] = r_buff[r_cur];
                    r_cur++;
                }
            }
            else if (l_cur <= middle)
            {
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else
            {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        return target;
    }
public:
};
