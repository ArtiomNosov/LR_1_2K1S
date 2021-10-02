#pragma once
#include <iostream>
#include <random> // ��� std::random_device � std::mt19937
#include "Integer.h"
Integer** randomInteger(int count) {
    std::random_device rd;
    std::mt19937 mersenne(rd()); // �������������� ����� �������� ��������� ��������� ������ 
    Integer** res = new Integer * [count];
    for (int i = 0; i < count; i++) {
               res[i] = new Integer(mersenne());
    }
    return res;
}