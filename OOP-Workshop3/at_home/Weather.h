// OOP244 Workshop 3 - 
// File Weather.h
// Version 1.0
// Date 06/3/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
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
        const char* date() const;
        double low() const;


    };
}

#endif