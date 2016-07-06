// OOP244 Workshop 2: Compound types and privacy
// File	AccountNumber.cpp
// Version 2.0
// Date	05/20/2016
// Author	Marco Beltempo
// Description
// 
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// M.Beltempo  06/01/16     Remove new line from displayNumber & displayName func. def. and insert following function call.
///////////////////////////////////////////////////////////

#include "AccountNumber.h"

#include <iostream>
#include <string.h>

using namespace std;
namespace sict{

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

        }else{

            _validAccNumber = false;
        }
    }

    bool AccountNumber::isValid() const {

        return _validAccNumber;
    }

    void AccountNumber::display(bool display_name, bool display_number) const{

        if (_validAccNumber == true){       // if account is valid prcoeed to check parameter vlaues

            if (display_name == true && display_number == true){

                cout << "Name: " << _name << ", Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber << endl;
            }

            else if (display_name == false && display_number == true){

                displayNumber();
                cout << endl;
            }

            else if (display_number == false && display_name == true){

                displayName();
                cout << endl;
            }

            else if (display_name == false && display_number == false){  // intentionally set to do nothing

            }

        }else{

            cout << _name << " does not have a valid account number." << endl;
        }
    }

    void AccountNumber::displayNumber() const{

        cout << "Account number: " << _bankCode << "-" << _branchCode << "-" << _accountNumber;
    }

    void AccountNumber::displayName() const{

        cout << "Name: " << _name;
    }
}