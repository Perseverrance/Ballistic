//
// Created by perseverance on 14.10.23.
//

#include <iostream>
#include "gtest/gtest.h"
#include "../src/Time/time.h"
#include "../src/Time/converter.h"

TEST(first, first){
    double a = 1000000000.5;
    double b = -1000000000.1;
    Time<Scale::TAI> timeTAI(a, b);
    Time<Scale::TT> timeTT;

    TimeConverter converter;
    timeTT = converter.TAI_to_TT(timeTAI);
}

//TEST(second, second)
//{
//    std::cout << "hi" << std::endl;
//}