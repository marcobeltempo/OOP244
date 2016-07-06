// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
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
// M.Beltempo 06/9/16 strcmp in findLow returns false when it is matched
///////////////////////////////////////////////////////////


#include <iostream>
#include <cstring>
#include "Weather.h"

using namespace std;
using namespace sict;
double findLow(const char* date, const Weather *data, int dataSize);
int main(){
    int i; //  loop counter
    int n; //the count of days worth of weather
    // create the weather pointer here
    Weather* weather;

    cout << "Weather Data\n";
    cout << "=====================" << endl;
    cout << "Days of Weather: ";
    cin >> n;
    cin.ignore();
    // allocate dynamic memory here
    weather = new Weather[n];

    for (i = 0; i < n; i++){
        char date_description[7];
        double high;
        double low;

        // ... add code to accept user input for
        //weather

        cout << "Enter date: ";
        cin >> date_description;

        cout << "Enter high: ";
        cin >> high;

        cout << "Enter low : ";
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

    char query[7];
    cout << endl << "Enter the date you are looking for: ";
    cin >> query;

    /* accept user input for the date to find
    (in this example stored in char query[7])
    and display low temprature. */

    double low = findLow(query, weather, n);
    cout << "Low temperature: " << low << endl;

    // deallocate dynamic memory here
    delete weather;
    return 0;

}

double findLow(const char* date, const Weather* data, int dataSize){

    for (int i = 0; i <= dataSize; i++){

        if (strcmp(data[i].date(), date) == 0){
            return data[i].low();
        }
    }
    return 0;
}
