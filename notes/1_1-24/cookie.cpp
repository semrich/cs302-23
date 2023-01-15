/* Professor Scott, cookie.cpp

Member functions for a simple example that displays a message when objects are constructed 
and deconstructedto show when constructors are run (when they come in scope) and what 
happens when deconstructs run (when they go out of scope)

*/

#include <iostream>
#include "cookie.h"   // class definition file

using namespace std;

CookieMon::CookieMon(char c) {   // constructor

  cout << c << " is for cookie, that's good enough for me" << endl;
  myc = c;

}

CookieMon::~CookieMon() {  // deconstructor

  cout << "Oh, cookie, cookie, cookie starts with " << myc << endl;

}
