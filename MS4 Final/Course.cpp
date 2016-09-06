/* OOP244-Seneca Course Management App- MS4

File Course.cpp
Version 1.4
Date 7/19/16
Author Marco Beltempo
Email mabeltempo@myseneca.ca
SID 031028095

Revision History
___________________________________________________________________________________________
| Name      | Date  | Reason                                                                |
| ------------------------------------------------------------------------------------------|
| M.Beltempo 7/19/16  Defined constructors (default, copy), setters, getters                |
| M.Beltempo 7/21/16  Allocated new char for courseTitle_ setter with strlen                |
| M.Beltempo 7/23/16  Implemented a sepearte display function for displaying course list.   |
|                     Modified change study load for -=                                     |
| M.Beltempo 7/28/16  Modified the << overload with display()                               |
| M.Beltempo 8/08/16  Replaced display function to new virtual display function.            |
|                     Defined read function using logic fom scmApp addACourse(int) function.|
|                     Defined load and read function.                                       |
|___________________________________________________________________________________________|

*/

#include <iostream>
#include <string.h>
#include <iomanip>

#include "Course.h"

using namespace std;

namespace sict {

    //Constructors
    Course::Course() {

        courseCode_[0] = '\0';
        courseTitle_ = nullptr;
        credits_ = -1;
        studyLoad_ = -1;

    }

    Course::Course(const char* courseCode, const char* courseTitle, int credits, int studyLoad) {

        setCourseCode(courseCode);
        setCourseTitle(courseTitle);
        setCredits(credits);
        setStudyLoad(studyLoad);

    }

    Course::Course(const Course& copy) {

        if (this != &copy) {
            if (!isEmpty()) {

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
           

            setCourseCode(other.courseCode_);
            setCourseTitle(other.courseTitle_);
            setCredits(other.credits_);
            setStudyLoad(other.studyLoad_);
        }
        return *this;
    }

    //destructor
    Course::~Course() {
		
	if (courseTitle_ != nullptr) {
       delete [] courseTitle_;
  } 
    }

    //Setters
    void Course::setCourseCode(const char* courseCode) {

        strncpy(courseCode_, courseCode, MAX_COURSECODE_LEN + 1);

    }
    void Course::setCourseTitle(const char* courseTitle) {


        courseTitle_ = new char[strlen(courseTitle) + 1];  // allocate with new

        if (strlen(courseTitle) != 0) {
           
            strcpy(courseTitle_, courseTitle);

        }

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

    int Course::getCredits() const {

        return credits_;
    }

    int Course::getStudyLoad() const {

        return studyLoad_;
    }

    bool Course::isEmpty() {


        return courseCode_[0] == '\0' || courseTitle_ == nullptr || courseTitle_ == '\0' || credits_ == 0 || credits_ == -1 || studyLoad_ == 0 || studyLoad_ == -1;

    }

    //Checks if client course code is equal to object course code and returns bool
    bool Course::operator == (const char* compareCode) {

        return strcmp(courseCode_, compareCode) == 0;
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


    std::ostream& operator<<(std::ostream& os, const Course& course) {

        course.display(os);
        return os;
    }

    fstream& Course::store(fstream& fileStream, bool addNewLine) const {

        fileStream <<
            getCourseCode() << "," <<
            getCourseTitle() << "," <<
            getCredits() << "," <<
            getStudyLoad();

        if (addNewLine) {

            fileStream << endl;
        }

        return fileStream;
    }

    fstream& Course::load(fstream& fileStream) {

        char tempCourseCode[MAX_COURSECODE_LEN + 1];
        char* tempCourseTitle;
        string str_title;

        int tempStudyLoad = 0;
        int tempCredits = 0;

        //fileStream.ignore(TYPE_ICT);
        //fileStream.ignore(TYPE_GEN);
        fileStream.getline(tempCourseCode, MAX_COURSECODE_LEN + 1, ',');

        //fileStream.ignore();
        getline(fileStream, str_title, ',');
        tempCourseTitle = new char[str_title.length()]; // use size of string to asign to char array
        strcpy(tempCourseTitle, str_title.c_str());         //convert string to c string

        fileStream >> tempCredits;
        fileStream.ignore();

        fileStream >> tempStudyLoad;
        fileStream.ignore();

        setCourseCode(tempCourseCode);
        setCourseTitle(tempCourseTitle);
        setCredits(tempCredits);
        setStudyLoad(tempStudyLoad);

        return fileStream;

    }

    ostream& Course::display(ostream& os) const {

        cout << right << setw(MAX_COURSECODE_LEN) << courseCode_
            << "|" << setw(41) << left << courseTitle_
            << "|" << setw(9) << right << credits_
            << "|" << setw(11) << studyLoad_
            << setw(2) << "|";

        return os;
    }

    istream& Course::read(istream& istr) {

        char tempCourseCode[MAX_COURSECODE_LEN + 1];
        char* tempCourseTitle;
        string str_title;

        int tempStudyLoad = 0;
        int tempCredits = 0;

        cout << "Course Code: ";

        istr >> tempCourseCode;
        istr.ignore();

        setCourseCode(tempCourseCode);

        cout << "Course Title: ";

        getline(istr, str_title);
        tempCourseTitle = new char[str_title.length() + 1]; // use size of string to asign to char array
        strcpy(tempCourseTitle, str_title.c_str());         //convert string to c string


        setCourseTitle(tempCourseTitle);

        cout << "Course Credit: ";
        istr >> tempCredits;

        istr.ignore();
        setCredits(tempCredits);

        cout << "Study Load: ";
        istr >> tempStudyLoad;

        setStudyLoad(tempStudyLoad);

        return istr;

    }

}

