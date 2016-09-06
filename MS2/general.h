// OOP244-Seneca Course Management App- MS1
// File general.h
// Version 1.0
// Date 07/19/16
// Author Marco Beltempo
// Email mabeltempo@myseneca.ca
// Description
// 
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// M.Beltempo 07/19/16 Defined default values
// M.Beltempo 07/27/16 Added MAX_SYSTEM_LEN 
//////////////////////// ///////////////////////////////////
#ifndef _GENERAL_H_
#define _GENERAL_H_

namespace sict {

#define MAX_COURSECODE_LEN 6   // maximum length of a course code.
#define DISPLAY_LINES 10 	  // maximum number of lines used to display course details before each pause.
#define MAX_NO_RECS 2000 	 // maximum number of records in the data file.
#define MAX_LENGTH 100      // buffer size for course title;
#define MAX_SYSTEM_LEN 6+1 // maximum length of system name

}
#endif
