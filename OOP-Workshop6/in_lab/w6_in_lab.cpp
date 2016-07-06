// OOP244 Workshop 6: operators 
// File: w6_in_lab.cpp
// Version: 1.0
// Date: 2016/02/22
// Author: Fardad Soleimanloo
// Description:
// This file tests in-lab section of your workshop
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/17/16 Added an endl to the displayABC function
//////////////////////// ///////////////////////////////////

#include <iostream>
#include "Account.h"

using namespace sict;
using namespace std;

void displayABC(const Account&, const Account&, const Account&);

int main(){
    Account A;
    Account B("Saving", 10000.99);
    Account C("Checking", 100.99);

    displayABC(A, B, C);
    A = B + C;
    
    displayABC(A, B, C);
    A = "Joint";
    
    displayABC(A, B, C);
    A = B += C;
    
    displayABC(A, B, C);
    A = B += C += 100.01;
    
    displayABC(A, B, C);
    return 0;
}


void displayABC(const Account& A, const Account& B, const Account& C){
    cout << "A: " << A;
    cout << "B: " << B;
    cout << "C: " << C;
    cout << "--------" << endl;
}