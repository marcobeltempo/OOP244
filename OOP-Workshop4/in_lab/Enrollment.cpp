// OOP244 Workshop 4 In Lab
// File Enrollment.cpp
// Version 1.0
// Date 06/10/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 06/10/16 Implemented definitions
//////////////////////// ///////////////////////////////////


#include "Enrollment.h"
#include <iostream>
#include <string.h>

using namespace std;

namespace sict{

    //done
    bool Enrollment::isValid()const{
        return name_ && name_[0];
    }
    //done
    void Enrollment::setEmpty(){
        name_[0] = 0;
        code_[0] = 0;
        year_ = 0;
        semester_ = 0;
        slot_ = 0;
        enrolled_ = false;
    }
    // done
    bool Enrollment::isEnrolled() const{
        return enrolled_;
    }

    // done
    void Enrollment::display(bool nameOnly)const{
        if (isValid()){
            cout << name_;
            if (!nameOnly){
                cout << endl << code_ << ", Year: " << year_ << " semester: " << semester_ << " Slot: " << slot_ << endl;
                cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
            }
        }
        else{
            cout << "Invalid enrollment!" << endl;
        }
    }


    void Enrollment::set(const char* name, const char* code, int year, int semester, int time, bool enrolled){


        if (name != NULL && name[0] != '/0'){

            strcpy_s(name_, name);
        }
        else{
            strcpy_s(name_, "");
        }

        if (code != NULL && code[0] != '/0'){

            strcpy_s(code_, code);

        }
        else{
            strcpy_s(code_, "");
        }

        if (year >= 2015){

            year_ = year;
        }
        else{
            year_ = 0;
        }

        if (semester > 0 && semester < 4){

            semester_ = semester;
        }
        else{
            semester_ = 0;
        }

        if (time > 0 && time < 6){

            slot_ = time;
        }
        else{
            slot_ = 0;
        }

        enrolled_ = enrolled;

        if (!strcmp(name_, "") || !strcmp(code_, "") || year_ == 0 || semester_ == 0 || slot_ == 0){

            setEmpty();
        }

    }

    bool Enrollment::hasConflict(const Enrollment &other) const{

        if (isValid() || other.isValid()){

            if (year_ == other.year_ && semester_ == other.semester_ && slot_ == other.slot_){
                return true;
            }
            else{
                return false;
            }
        }
    }

    Enrollment::Enrollment(const char* name, const char* code, int year, int semester, int time){

        set(name, code, year, semester, time);

    }

    Enrollment::Enrollment(){

        setEmpty();
    }

    Enrollment::~Enrollment(){

    }

}
