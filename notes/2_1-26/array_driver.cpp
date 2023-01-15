// Fig. 11.8: fig11_08.cpp
// Array class test program modified w/ templates

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "array_class.cpp"

int main() {

  Array<int> arr1( 7 ); // seven-element Array of ints   
  Array<float> arr2; // 10-element Array by default of float

  cout << "Size of Array arr1 is " 
       << arr1.getSize() << endl;

  cout << "\nSize of Array arr22 is " 
       << arr2.getSize() << endl;

  cout << "Array 1 " << arr1 << endl;



}  // end of main
