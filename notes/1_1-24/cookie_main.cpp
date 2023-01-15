// Prof. Scott

// Simple main program for constructor/deconstructor example

#include "cookie.h"

int main() {

  CookieMon a;   // default cookie                                                             

  if (1) {

    CookieMon b ('+');  // non-default cookie, still yummy                                     

  }  // b is deconstructed here when it goes out of scope                                      

}  // a is deconstructed here    
