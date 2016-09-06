/* OOP244-Seneca Course Management App- MS4

 File Course.h
 Version 1.4
 Date 7/19/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca

 Revision History
  __________________________________________________________________________________________
 | Name      | Date  | Reason                                                               |
 |------------------------------------------------------------------------------------------|
 | M.Beltempo 7/19/16  Declared the Course class                                            |   
 | M.Beltempo 7/28/16  Made display() virtual to allow redef, of << from derived classes    | 
 | M.Beltempo 7/29/16  Added tester friend class                                            |               
 | M.Beltempo 8/08/16  Derived from Streamable and declared virtual functions               |
 |__________________________________________________________________________________________|

 */

#include "general.h"
#include "Streamable.h"

#ifndef _COURSE_H_
#define _COURSE_H_

namespace sict{

    class Course : public Streamable{

	//Tester
        friend class CourseTester; //for submision testing
		
    private:

        char courseCode_[MAX_COURSECODE_LEN + 1]; 
        char* courseTitle_;
        int credits_;
        int studyLoad_;

    public:

        //Constructors
        Course();
        Course(const char* courseCode, const char* courseTitle, int credits, int studyLoad);
        Course(const Course&);
        Course& operator = (const Course& other);

        //Destructor
        ~Course();

        //Setters
        void setCourseCode(const char* );
        void setCourseTitle(const char*);
        void setCredits(int);
        void setStudyLoad(int);

        //Getters
        const char* getCourseCode() const;
        const char* getCourseTitle() const;
        int getCredits() const;
        int getStudyLoad() const;
        bool isEmpty();

        //Overloaded operators 
        bool operator == (const char*);
        int operator += (int newStudyLoad);
       

        fstream& store(fstream& fileStream, bool addNewLine = true) const;
        fstream& load(fstream& fileStream);
        ostream& display(ostream& os) const;
        istream& read(istream& istr);

    };
   std::ostream& operator<<(std::ostream& os, const Course& course);
   
}
#endif
