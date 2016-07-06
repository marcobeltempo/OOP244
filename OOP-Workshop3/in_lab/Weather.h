// OOP244 Workshop 3 - In Lab
// File Weather.h
// Version 1.0
// Date 06/02/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/2/16 Implemented safegaurds and weather class
//////////////////////// ///////////////////////////////////

#ifndef _WEATHER_H_
#define _WEATHER_H_

/*Weather.h*/

namespace sict{
    class Weather {

    private:
        char _date[7];
        double _high_temperature;
        double _low_temperature;

    public:

        void set(const char*, double, double);
        void display() const;

    };
}

#endif