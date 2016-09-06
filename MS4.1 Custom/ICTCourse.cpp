/* OOP244-Seneca Course Management App- MS4

 File Course.cpp
 Version 1.4
 Date 7/19/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca

 Revision History
  ___________________________________________________________________________________________
 | Name      | Date  | Reason                                                                |
 | ------------------------------------------------------------------------------------------|
 | M.Beltempo 7/27/16  Defined member functions                                              |
 | M.Beltempo 7/28/16  Replaced single arg. constructor with 5 arg.                          |
 | M.Beltempo 8/08/16  Replaced display function to new virtual display function             |
 |                     Defined read function using logic fom scmApp addACourse(int) function |
 |                     Defined load and read function                                        |
 |___________________________________________________________________________________________|

*/

#include <iostream>
#include <string.h>
#include <iomanip>

#include "ICTCourse.h"


using namespace std;

namespace sict {

    ICTCourse::ICTCourse() {

        computerSystem_[0] = 0;
        
    }

    ICTCourse::ICTCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, const char* comp_system) : Course
    (courseCode, courseTitle, credits, studyLoad)
    {

        setComputerSystem(comp_system);
    }

    const char* ICTCourse::getComputerSystem() const {

        return computerSystem_;
    }

    void ICTCourse::setComputerSystem(const char* value) {

        if ((value == nullptr) || (value[0] == '\0')) {

            strcpy(computerSystem_, "matrix");
        }
        else {

            strcpy(computerSystem_, value);
        }
    }

    std::ostream& operator<<(std::ostream& os, const ICTCourse& ICT) {

        ICT.display(os);
        return os;
    }

    fstream& ICTCourse::store(fstream& fileStream, bool addNewLine) const {

        fileStream << TYPE_ICT << ",";

        Course::store(fileStream, false);

        fileStream << "," << getComputerSystem();

        if (addNewLine) {

            fileStream << endl;
        }

        return fileStream;
    }


    fstream& ICTCourse::load(fstream& fileStream) {

        char tempCourseICT[MAX_SYSTEM_LEN + 1];

        Course::load(fileStream);

        fileStream.getline(tempCourseICT, MAX_SYSTEM_LEN + 1, '\n');
 
        setComputerSystem(tempCourseICT);

        return fileStream;
    }

    ostream&  ICTCourse::display(ostream& os) const {

        Course::display(os);
        os << setw(8) << left << computerSystem_ << setw(13) << "|" << "|" << endl;

        return os;
    }

    istream&  ICTCourse::read(istream& istr) {

        char tempCourseICT[MAX_SYSTEM_LEN + 1];

        Course::read(istr);

        cout << "Computer system: ";
        istr >> tempCourseICT;
        setComputerSystem(tempCourseICT);

        return istr;
    }

}


