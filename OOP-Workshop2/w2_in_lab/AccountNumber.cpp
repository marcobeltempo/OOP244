// OOP244 Workshop 2: Compound types and privacy
// File	AccountNumber.cpp
// Version 1.0
// Date	05/20/2016
// Author	Marco Beltempo
// Description
// 
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////

#include "AccountNumber.h"

#include <iostream>
#include <string.h>

using namespace std;
using namespace sict;

void AccountNumber::setName(const char name[]){

    strcpy(_name, name);
}

void AccountNumber::setAccountNumber(int bankCode, int branchCode, int accountNumber){

    _bankCode = bankCode;
    _branchCode = branchCode;
    _accountNumber = accountNumber;

    if (_bankCode >= MIN_BANKCODE && _bankCode <= MAX_BANKCODE &&
        _branchCode >= MIN_BRANCHCODE && _branchCode <= MAX_BRANCHCODE &&
        _accountNumber >= MIN_ACCNO && _accountNumber <= MAX_ACCNO){

        _validAccNumber = true;

    }
    else{
        _validAccNumber = false;
    }
}

bool AccountNumber::isValid() const {

    return _validAccNumber;
}

void AccountNumber::display() const {

    if (_validAccNumber){

        cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
            << _branchCode << "-" << _accountNumber << endl;
    }
    else {

        cout << _name << " does not have a valid account number." << endl;
    }
}