
// OOP244 Workshop 5 In Lab
// File Account.cpp
// Version 1.0
// Date 06/17/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/17/16 changed += operator to const char name[]
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

    /*Overload the operartor+= so the following is possible:
If A and B and C are Account objects:
A = B += C: adds the balance of C to B and returns the reference of B,
so A will be to B afterwards.*/

    Account& Account::operator += (const Account& A){

        balance_ += A.balance_;
        return *this;

    }

    /*Overload the operator= so the following is possible:
    A = B = "new name": Sets the name of B to “new name” and returns the reference of B.
    */
    Account& Account::operator=(const char name[])
    {
        strncpy(name_, name, 40);
        name_[40] = 0;
        return *this;
    }

    /*
    A friend operator+:
    Overload operator+ as a friend so the following is possible :
    A = B + C : this operator returns an account with an empty name
    and a balance of the sum of two balances of B and C. */

    Account operator+(const Account& A, const Account& B){

        Account newAccount(A.balance_ + B.balance_);
        return newAccount;
    }

    /*operator<< should call the display member function of A 
    (no newline printed) and return the reference of ostream. */

    std::ostream& operator <<(std::ostream& os, const Account& A){

        A.display();
        return os ;
    }

}
