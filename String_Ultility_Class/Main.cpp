#include "Driscoll_String.h"
#include <string>

int main()
{
	/* STRING TEST CASES: */

	/* CONSTRUCTORS AND PRINTING */
	Driscoll_String Str = "Hello World!";
	std::cout << Str << std::endl;

	Driscoll_String StrCopy = " Bye World!";

	StrCopy.Replace("Bye", "Helllllo");
	
	std::cout << StrCopy;




	return 0;
}

/* THINGS TO TESTCHECKLIST:
*
* CONSTRUCTOR WITH STRING (GOOD)
* COPY CONSTRUCTOR        (GOOD)
* GetLength               (GOOD)
* CharacterAt             (GOOD)
* Equals                  (GOOD)
* Append                  (GOOD)
* Prepend                 (GOOD)
* CStr                    ()
* ToLower                 (GOOD)
* ToUpper                 (GOOD)
* Find                    (GOOD)
* Find_StartIndex         (GOOD)
* Replace                 (NEEDS MEMORY ALLOCATION NOW)
* Operator =              (GOOD)
* Operator +              (GOOD)
* Operator +=             (GOOD)
* Operator ==             (GOOD)
* Operator !=             (GOOD)
* Operator[] Get Char     ()
* Operator ostream        (GOOD)
*/