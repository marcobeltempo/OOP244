// OOP244 Workshop 3 - In Lab
// File w3_in_lab.cpp
// Version 1.0
// Date 06/02/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/02/16  Implemented mising fields
///////////////////////////////////////////////////////////

#include <iostream>
#include "Weather.h"

using namespace std;
using namespace sict;
int main(){
    int i; //  loop counter
    int n; //the count of days worth of weather
    // initialize the weather pointer here
    Weather* weather;

    cout << "Weather Data" << endl
        << "=====================" << endl
        << "Days of Weather: ";
    cin >> n;
    cin.ignore();

    // allocate dynamic memory here

    weather = new Weather[n];

    for (i = 0; i < n; i++){
        char date_description[7];
        double high;
        double low;

        // ... add code to accept the user input
        // for the weather array

        cout << "Enter date: ";
        cin >> date_description;

        cout << "Enter high: ";
        cin >> high;

        cout << "Enter low: ";
        cin >> low;

        weather[i].set(date_description, high, low);
    }
    cout << endl
        << "Weather report:" << endl
        << "Date        high  low" << endl
        << "======================" << endl;

    for (i = 0; i < n; i++){
        weather[i].display();
    }

    // deallocate dynamic memory here

    delete weather;
    return 0;
}
