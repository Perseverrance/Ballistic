//
// Created by perseverance on 30.09.23.
//

#ifndef PROJECT_B_CONVERTER_H
#define PROJECT_B_CONVERTER_H

#include "time.h"


class TimeConverter {
public:

    [[nodiscard]] Time<Scale::TT> TAI_to_TT(const Time<Scale::TAI> &TAI) const noexcept; //1
    [[nodiscard]] Time<Scale::TAI> TT_to_TAI(const Time<Scale::TT> &TT) const noexcept;  //2
    [[nodiscard]] Time<Scale::UTC> TAI_to_UTС(const Time<Scale::TAI> &TAI) const noexcept; //3
    [[nodiscard]] Time<Scale::TAI> UTC_to_TAI(const Time<Scale::UTC> &UTC) const noexcept; //4


    template<Scale To, Scale From>
    [[nodiscard]] Time<To> convert(const Time<From> &from) const {
        Time<From> time;
        if constexpr (To == Scale::TT && From == Scale::TAI) {
            return TAI_to_TT(time);
        };
    }
};

Time<Scale::TT> TimeConverter::TAI_to_TT(const Time<Scale::TAI> &TAI) const noexcept {
    double tt1;
    double tt2;
    auto func_value = iauTaitt(TAI.jdInt(), TAI.jdFrac(), &tt1, &tt2);
    //assert(func_value == 0);
    Time<Scale::TT> timeTT(tt1, tt2);
    return timeTT;
}

Time<Scale::TAI> TimeConverter::TT_to_TAI(const Time<Scale::TT> &TT) const noexcept {
    double tai1;
    double tai2;
    auto func_value = iauTttai(TT.jdInt(), TT.jdFrac(), &tai1, &tai2);
    assert(func_value == 0);
    Time<Scale::TAI> timeTAI(tai1, tai2);
    return timeTAI;
}

Time<Scale::UTC> TimeConverter::TAI_to_UTС(const Time<Scale::TAI> &TAI) const noexcept {
    double utc1;
    double utc2;

    auto func_value = iauTaiutc(TAI.jdInt(), TAI.jdFrac(), &utc1, &utc2);
    assert(func_value == -1);
    Time<Scale::UTC> timeUTC(utc1, utc2);
    return timeUTC;
}

Time<Scale::TAI> TimeConverter::UTC_to_TAI(const Time<Scale::UTC> &UTC) const noexcept {
    double tai1;
    double tai2;

    auto func_value = iauUtctai(UTC.jdInt(), UTC.jdFrac(), & tai1, &tai2);
    Time<Scale::TAI> timeTAI;
    return timeTAI;
}


#endif //PROJECT_B_CONVERTER_H