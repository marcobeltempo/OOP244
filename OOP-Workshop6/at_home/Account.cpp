
// OOP244 Workshop 5 At Home
// File Account.cpp
// Version 2.0
// Date 06/21/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/17/16 changed += operator to const char name[]
// M.Beltempo 06/22/16 removed the friend access for the + operator
// M.Beltempo 06/22/16 created an accessor to return balance_
// M.Beltempo 06/23/16 created += helper 
//////////////////////// ///////////////////////////////////

#include <iomanip>
#include <string>
#include <iostream>
#include "Account.h"


using namespace std;

namespace sict{

    void Account::display(bool gotoNewline)const {
        cout << (name_[0] ? name_ : "No Name") << ": $" << setprecision(2) << fixed << balance_;
        if (gotoNewline) cout << endl;
    }

    Account::Account(){
        name_[0] = 0;
        balance_ = 0;
    }
    Account::Account(double balance){
        name_[0] = 0;
        balance_ = balance;
    }
    Account::Account(const char name[], double balance){
        strcpy(name_, name);
        balance_ = balance;
    }

    /*Overload the operator= so the following is possible:
    A = B = "new name": Sets the name of B to �new name� and returns the reference of B.
    */
    Account& Account::operator=(const char name[])
    {
        strncpy(name_, name, 40);
        name_[40] = 0;
        return *this;
    }

    /*Overload operator+= as a helper so the following is
    possible: If “d” and “e” are double variables and A is an
    Account object. d = e += A;
    */

    double operator += (double& A, const Account& B){

        A += B.getBalance();
        return A;

    }

    Account& Account::operator+=(const Account& A)
    {
        balance_ += A.getBalance();
        return *this;
    }


    Account operator+(const Account A, const Account B){

        Account newAccount(A.getBalance() + B.getBalance());
        return newAccount;
    }

    double Account::getBalance()const{

        return balance_;
    }
    /*operator<< should call the display member function of A
    (no newline printed) and return the reference of ostream. */

    std::ostream& operator <<(std::ostream& os, const Account& A){

        A.display();
        return os;
    }

}