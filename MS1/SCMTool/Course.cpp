// OOP244-Seneca Course Management App- MS1
// File Course.cpp
// Version 1.0
// Date 07/19/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// SID 031028095
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/19/16 Defined constructors (default, copy), setters, getters
// M.Beltempo 07/21/16 allocated new char for courseTitle_ setter with strlen
// M. Beltempo 07/23/16 Implemented a sepearte display function for displaying course list
// M.Beltempo 07/23/16 modified change study load for -= 
//////////////////////// ///////////////////////////////////

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Course.h"

using namespace std;

namespace sict {

    //Constructors
    Course::Course() { 

        courseCode_[0] = '\0';
        courseTitle_ = nullptr;
        credits_ = 0;
        studyLoad_ = 0;
    }

    Course::Course(const char* courseCode, const char* courseTitle, int credits, int studyLoad ) {

        setCourseCode(courseCode);
        setCourseTitle(courseTitle);
        setCredits(credits);
        setStudyLoad(studyLoad);
      
    }

    Course::Course(const Course& copy) {
        
        if (this != &copy) {
            if (copy.courseTitle_ != nullptr) {

                setCourseCode(copy.courseCode_);
                setCourseTitle(copy.courseTitle_);
                setCredits(copy.credits_);
                setStudyLoad(copy.studyLoad_);
            }
            else {

                courseTitle_ = nullptr;
            }
        }
    }
    Course&  Course::operator = (const Course& other) {

        if (this != &other) {

            if (courseTitle_ != nullptr) {
                delete courseTitle_;
            }
            setCourseCode(other.courseCode_);
            setCourseTitle(other.courseTitle_);
            setCredits(other.credits_);
            setStudyLoad(other.studyLoad_);

        }

        return *this;
    }

    Course::~Course() {

        delete courseTitle_;
        courseTitle_ = nullptr;
    }

    //Setters
    void Course::setCourseCode(const char* courseCode) {

        strncpy(courseCode_, courseCode, MAX_COURSECODE_LEN + 1);
    }

    void Course::setCourseTitle(const char* courseTitle) {

       
            courseTitle_ = new char[strlen(courseTitle) + 1];  // allocate with new

            strcpy(courseTitle_, courseTitle);        // copy to new space
      }
        

    void Course::setCredits(int credits) {

        credits_ = credits;
    }

    void Course::setStudyLoad(int studyLoad) {

        studyLoad_ = studyLoad;
    }

    //Getters

    const char* Course::getCourseCode() const {

        return courseCode_;
    }

    const char* Course::getCourseTitle() const {

        return courseTitle_;
    }

    int Course::getCredits() {

        return credits_;
    }

    int Course::getStudyLoad() {

        return studyLoad_;
    }

    bool Course::isEmpty() {

        return courseTitle_ == nullptr;
    }

    //Checks if client course code is equal to object course code and returns bool
    bool Course::operator == (const char* compareCode) {
        if (strcmp(courseCode_, compareCode) == 0) {

            return true;
        }
        else {

            return false;
        }
    }

    // Modifies the course load by adding or subtracting to the existing int
    int Course::operator += (int newStudyLoad) {

        if (newStudyLoad < 0) {

            return  this->studyLoad_ -= -newStudyLoad;
        }
        else {

            return this->studyLoad_ += newStudyLoad;
        }
    }

    void Course::display(std::ostream& os) const{

        cout << right << setw(MAX_COURSECODE_LEN) << courseCode_
            << "|" << setw(43) << left << courseTitle_
            << "|" << setw(9) << right << credits_
            << "|" << setw(11) << studyLoad_
            << setw(2) << "|";
    }

    std::ostream& operator<<(std::ostream& os, const Course& course) {

        course.display(os);
        return os;
    }

}

