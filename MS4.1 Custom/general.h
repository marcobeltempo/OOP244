/* OOP244-Seneca Course Management App- MS4

 File general.h
 Version 1.4
 Date 7/19/16
 Author Marco Beltempo
 Email mabeltempo@myseneca.ca

 Revision History
  __________________________________________________________________________________________
 | Name      | Date  | Reason                                                               |
 |------------------------------------------------------------------------------------------|
 | M.Beltempo 7/19/16  Defined default values                                               |
 | M.Beltempo 7/27/16  Added MAX_SYSTEM_LEN                                                 |
 | M.Beltempo 8/05/16  Added TYPE_ICT as ‘I’ and TYPE_GEN as ‘G’                            |               
 | M.Beltempo 8/12/16  Changed TYPE_ICT and TYPE_GEN to double quoutes                      |    
 |__________________________________________________________________________________________|

*/

#ifndef _GENERAL_H_
#define _GENERAL_H_

namespace sict {

#define MAX_COURSECODE_LEN 6   // maximum length of a course code.
#define DISPLAY_LINES 10 	  // maximum number of lines used to display course details before each pause.
#define MAX_NO_RECS 2000 	 // maximum number of records in the data file.
#define MAX_LENGTH 100      // buffer size for course title;
#define MAX_SYSTEM_LEN 6 // maximum length of system name
#define TYPE_ICT "I"      // ICT Course Identifier
#define TYPE_GEN "G"     // GenEd Course Identifier

}
#endif
