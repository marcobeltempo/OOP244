/* OOP244-Seneca Course Management App- MS2

 File GenEdCourse.cpp
 Version 1.0
 Date 07/27/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca

 Revision History
  __________________________________________________________________________________________
 | Name      | Date     | Reason                                                            |
 |------------------------------------------------------------------------------------------|
 | M.Beltempo 07/27/2016  Defined member functions                                          |
 | M.Beltempo 07/28/2016  Replaced single arg. constructor with 5 arg.                      | 
 |__________________________________________________________________________________________|

*/

#include <iostream>
#include <iomanip>

#include "GenEdCourse.h"
#include "general.h"

using namespace std;

namespace sict {

 
    GenEdCourse::GenEdCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, int language_level) : Course
    (courseCode, courseTitle, credits, studyLoad) {

        setLangLevel(language_level);
    }

    int GenEdCourse::getLangLevel() const {

        return langLevel_;
    }
    void GenEdCourse::setLangLevel(int value) {

        langLevel_ = value;
    }

    std::ostream& operator<<(std::ostream& os, const GenEdCourse& GenEd) {

        GenEd.display(os);

        return os;
    }

    fstream& GenEdCourse::store(fstream& fileStream, bool addNewLine) const {

        fileStream << TYPE_GEN << ",";
        Course::store(fileStream, false);

        fileStream << "," << getLangLevel();

        if (addNewLine) {

            fileStream << endl;
        }

        return fileStream;
    }


    fstream& GenEdCourse::load(fstream& fileStream) {
        
        int tempLang = 0;
        fileStream.ignore();
        Course::load(fileStream);
        fileStream.ignore();
        fileStream >> tempLang;
       
        setLangLevel(tempLang);
       
        return fileStream;

    }

    ostream&  GenEdCourse::display(ostream& os) const {

        Course::display(os);

        os << setw(9) << "|" << setw(12) << right << langLevel_ << "|" << endl;

        return os;
    }

    istream&  GenEdCourse::read(istream& istr) {

        int tempLang = 0;

        Course::read(istr);

        cout << "Language Requirement: ";
        istr >> tempLang;

        setLangLevel(tempLang);
       
        return istr;
    }

}