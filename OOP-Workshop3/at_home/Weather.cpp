// OOP244 Workshop 3 - 
// File Weather.cpp
// Version 1.0
// Date 06/03/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/9/16 Removed unnecessary output formatting in display function
//////////////////////// ///////////////////////////////////

/*Weather.cpp*/
//  includes go here
#include "Weather.h"

#include <iostream>
#include <string.h>
#include <iomanip>

// sict namespace
using namespace std;
namespace sict{

    // set
    /* The first parameter receives the address of
    a C-style string that holds the calendar date.
    The second and third parameters receive the low temperature,
    and high temperatures, respectively. */

    void Weather::set(const char* date, double high_temp, double low_temp){

        strcpy(_date, date);
        _high_temperature = high_temp;
        _low_temperature = low_temp;

    }
    // date method (query)

    const char* Weather::date() const{

        return _date;
    }

    // low method (query)

    double Weather::low() const{

        return _low_temperature;
    }

    // display

    /* Displays the high and low temperature as well
    as the date in the following format:
    date left justified in a field of 10 using underscore '_'
    instead of white space high and low temperatures right justified
    in fields of 6 with 1 decimal place each using underscore '_' */

    void Weather::display() const{

        cout << left << setw(10) << setfill('_')
            << _date << right << setw(6)
            << setprecision(1) << fixed << _high_temperature
            << setw(6) << _low_temperature
            << endl;
    }

}