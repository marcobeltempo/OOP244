/* OOP244-Seneca Course Management App- MS4

 File ICTCourse.h
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
 | M.Beltempo 7/26/16  Defined ICTCourse class                                              |  
 | M.Beltempo 7/29/16  Added tester friend class                                            |
 | M.Beltempo 8/08/16  Declared Streamable virtual functions                                |    
 |__________________________________________________________________________________________|

 */

#include <string>

#include "general.h"
#include "Course.h"

#ifndef _ICTCOURSE_H_
#define _ICTCOURSE_H_

namespace sict {

class ICTCourse : public Course {
	
	 //Tester
        friend class  ICTCourseTester; //for submision testing
  
    private:

        char computerSystem_[MAX_SYSTEM_LEN];
       
    public:

        //constructors
        ICTCourse(const char* courseCode, const char* courseTitle, int credits, int studyLoad, const char* comp_system);
        ICTCourse();

        const char* getComputerSystem() const;
        void setComputerSystem(const char* value);
       // void display(std::ostream& os) const;

      fstream& store(fstream& file, bool addNewLine) const;
      fstream& load(fstream& fileStream);
      ostream& display(ostream& os) const;
      istream& read(istream& istr);

    };
 std::ostream& operator<<(std::ostream& os, const Course& ICT);

}
#endif