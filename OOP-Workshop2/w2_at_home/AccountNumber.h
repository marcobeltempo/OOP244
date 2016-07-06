// OOP244 Workshop 2: Compound types and privacy
// File	AccountNumber.h
// Version 2.0
// Date	05/20/2016	
// Author	Marco Beltempo
// Description
// The display function has been modified to pass 2 boolean arguments 
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name 	  Date 	Reason
// M.Beltempo 06/01/16  display_numer set to true
///////////////////////////////////////////////////////////

#ifndef _ACCOUNT_NUMBER_H
#define _ACCOUNT_NUMBER_H

#define MAX_NAME_LENGTH 40
#define MIN_BANKCODE 100
#define MAX_BANKCODE 999
#define MIN_BRANCHCODE 1
#define MAX_BRANCHCODE 220
#define MIN_ACCNO 10000
#define MAX_ACCNO 99999

namespace sict{
    class AccountNumber{

    private:

        char _name[MAX_NAME_LENGTH + 1];
        int _bankCode;
        int _branchCode;
        int _accountNumber;
        bool _validAccNumber;

        void displayNumber() const;
        void displayName() const;

    public:

        void setName(const char name[]);
        void setAccountNumber(int bankCode, int branchCode, int accountNumber);
        void display(bool display_name = true, bool display_number = true) const;
        bool isValid() const;

    };
}
#endif
