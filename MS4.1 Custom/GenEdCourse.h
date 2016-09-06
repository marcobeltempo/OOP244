/* OOP244-Seneca Course Management App- MS4

 File GenEdCourse.h
 Version 1.4
 Date 7/26/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca
 SID 031028095
 Description
 
 Revision History
  __________________________________________________________________________________________
 | Name      | Date  | Reason                                                               |
 |------------------------------------------------------------------------------------------|
 | M.Beltempo 7/26/16 Defined GenEdCourse class                                             |
 | M.Beltempo 7/29/16 Added tester friend class                                             |
 | M.Beltempo 8/08/16 Derived from Streamable and declared virtual functions                |
 |__________________________________________________________________________________________|

 */

#include "Course.h"

#ifndef _GEN_ED_COURSE_H_
#define _GEN_ED_COURSE_H_

namespace sict {


       
		
    class GenEdCourse : public Course {
		
		 //Tester
		 friend class GenEdCourseTester; //for submision testing

    private:

        int langLevel_;
       
    public:
        GenEdCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, int language_level);
        GenEdCourse() { langLevel_ = 0; };
        int getLangLevel() const;
        void setLangLevel(int value);

        fstream& store(fstream& fileStream, bool addNewLine = true) const;
        fstream& load(fstream& fileStream);
        ostream& display(ostream& os) const;
        istream& read(istream& istr);

        
    };
   std::ostream& operator << (std::ostream& os, const GenEdCourse& GenEd);

}
#endif