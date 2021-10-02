#pragma once
#include <iostream>
#include <random> // для std::random_device и std::mt19937
#include "Integer.h"
Integer** randomInteger(int count) {
    std::random_device rd;
    std::mt19937 mersenne(rd()); // инициализируем Вихрь Мерсенна случайным стартовым числом 
    Integer** res = new Integer * [count];
    for (int i = 0; i < count; i++) {
               res[i] = new Integer(mersenne());
    }
    return res;
}