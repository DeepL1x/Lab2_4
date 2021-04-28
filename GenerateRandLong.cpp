//
// Created by Victor on 28.04.2021.
//

#include "GenerateRandLong.h"
long long generateRandLong(){
    long long key = 0;
    for (int i = 0 ; i < 12; ++i){
        key += (rand() % 10) * pow(10, i);
    }
    return key + (rand() % 9 + 1) * pow(10, 12);
}