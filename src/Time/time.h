//
// Created by perseverance on 22.09.23.
//

#ifndef PROJCET_B_TIME_H
#define PROJCET_B_TIME_H

#include <iostream>
#include "../../third_party/sofa/src/sofa.h"
//#include "../sofa/src/sofa.h"

enum class Scale {
    TAI = 0, UTC = 1, UT1 = 2, TT = 3, TCG = 4, TCB = 5, TDB = 6
};

struct schedule {
    int year;
    int month;
    int day;
    int hour;
    int min;
    double sec;
};

//// Time class
template<Scale scale>
class Time {
private:
    double jdInt_;
    double jdFrac_;
public:
    Time(double jd1 = 0, double jd2 = 0) noexcept;

    Time static buildFromJD(double jd) noexcept;

    double jd() const noexcept {
        return jdInt_ + jdFrac_;
    }

    Time static buildFromMJD(double mjd) noexcept;

    Time static buildFromCalendar(schedule sched);

    Time operator+(double seconds) const noexcept;
    Time operator-(double seconds) const noexcept;

    double const jdInt() const noexcept {
        return jdInt_;
    }

    double const jdFrac() const noexcept {
        return jdFrac_;
    }
};

//// Time functions
template<Scale scale>
Time<scale>::Time(double jd1, double jd2) noexcept {
    const int jd1Floor = jd1 >= 0 ? static_cast<int>(jd1) : static_cast<int>(jd1) - 1;
    const int jd2Floor = jd2 >= 0 ? static_cast<int>(jd2) : static_cast<int>(jd2) - 1;
    jdInt_ = jd1Floor + jd2Floor;

    const double delta1 = jd1 - jd1Floor;
    const double delta2 = jd2 - jd2Floor;
    jdFrac_ = delta1 + delta2;
    if (jdFrac_ >= 1) {
        jdInt_ += static_cast<int>(jdFrac_);
        jdFrac_ -= 1;
    }
}

template<Scale scale>
Time<scale> Time<scale>::buildFromJD(double jd) noexcept {
    return Time(jd, 0);
}

template<Scale scale>
Time<scale> Time<scale>::buildFromMJD(double mjd) noexcept {
    return Time(mjd + 2400000.5, 0);
}

template<Scale scale>
Time<scale> Time<scale>::buildFromCalendar(schedule sched) {
    //double jd = iauDtf2d(scale, sched.year, sched.month, sched.day, sched.hour, sched.min, sched.sec, get_jdInt_(),  );
}

#endif //PROJCET_B_TIME_H