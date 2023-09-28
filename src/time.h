//
// Created by perseverance on 22.09.23.
//

#ifndef PROJCET_B_TIME_H
#define PROJCET_B_TIME_H

#include <iostream>
#include "../third_party/sofa/src/sofa.h"

enum class Scale {
    TAI = 0, UTC = 1, UT1 = 2, TT = 3, TCG = 4, TCB = 5, TDB = 6
};

template<Scale scale>
class Time {
private:
    double jdInt_;
    double jdFrac_;
    Scale scale_ = scale;
public:
    Time(int jdInt = 0, double jdFrac = 0) noexcept: jdInt_(jdInt), jdFrac_(jdFrac){};


};

class TimeConverter {
private:
    Scale scale_to;
    Scale scale_from;

public:
    template<Scale To, Scale From>
    Time<To> convert(const Time<From> & from)
    {}
};

#endif //PROJCET_B_TIME_H