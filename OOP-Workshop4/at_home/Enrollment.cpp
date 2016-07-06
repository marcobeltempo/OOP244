// OOP244 Workshop 4 at Home
// File Enrollment.cpp
// Version 2.0
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
// M.Beltempo 06/15/16 Implemented enrol & withdraw functions
// M.Beltempo 06/16/16 Withdraw function set  enrolled_= false to avoid output error
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

    void Enrollment::withdraw(){

        enrolled_ = false;
    }

    int Enrollment::enrol(const Enrollment* enrollments, int size){

        for (int i = 1; i < size; i++){
            if (hasConflict(enrollments[i]) == true){

                enrolled_ = false;
                return i + 1;

            }
            else{

                enrolled_ = true;
                return 0;
            }
        }
    }

            Enrollment::Enrollment(){

                setEmpty();
            }

            Enrollment::~Enrollment(){

            }


        }
    
