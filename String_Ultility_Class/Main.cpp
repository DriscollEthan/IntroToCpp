#include "Driscoll_String.h"

int main()
{
	/* STRING TEST CASES: */

	/* CONSTRUCTORS AND PRINTING */
	Driscoll_String Str = "Hello World!";
	//std::cout << Str << std::endl;

	Driscoll_String StrCopy = "World B";

	StrCopy.Replace("B", "Hello");
	
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
* CStr                    (IDK PROABLY WORKING)
* ToLower                 (GOOD)
* ToUpper                 (GOOD)
* Find                    (GOOD)
* Find_StartIndex         (GOOD)
* Replace                 (NEARLY but not actaully nearly WORKING)
* Operator =              (GOOD)
* Operator +              (GOOD)
* Operator +=             (GOOD)
* Operator ==             (GOOD)
* Operator !=             (GOOD)
* Operator[] Get Char     (GOOD)
* Operator ostream        (GOOD)
*/