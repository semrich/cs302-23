/* Professor Scott, array.cpp
1/15/2020

Implementation (.cpp) for Array class that we will cover in lecture today

*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

template <typename T>
class Array {

  template <typename U> 
  friend ostream &operator<<( ostream &, const Array<U> & );

public:

  Array( int = 10 ); // default constructor                                                   
  Array( const Array<T> & ); // copy constructor                                              
  ~Array(); // destructor                                                                     

  void push_back (T);

  int getSize() const; // return size                                                         

  const Array<T> &operator=( const Array<T> & ); // assignment operator                       
  int operator==( const Array<T> & ) const; // equality operator                             

  int& operator[](int offset){ return ptr[offset];}
  const int& operator[](int offset) const{ return ptr[offset];}

  int operator!=( const Array<T> &right ) const {                                            

    return ! ( *this == right ); // invokes Array::operator==                                

 } // end function operator!=                                                                

private:

  int capacity;
  int size; // pointer-based array size                                                       
  T *ptr; // pointer to first element of pointer-based array                                  

}; // end class Array    

template <typename T>
Array<T>::Array( int arraySize )  {

  size = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize
  capacity = 100;

  ptr = new T[ capacity ]; // create space for pointer-based array

  for ( int i = 0; i < capacity; i++ )
    ptr[ i ] = 0; // set pointer-based array element to zero

} // end Array default constructor

template <typename T>
void Array<T>::push_back (T value) {

  if (size < capacity) {

    ptr[size] = value;
    size++; // size += 1;

  }
  else {

    capacity *= 2;
    T * newarr = new T[capacity];  /// delete

    for (int i = 0; i < size; i++) 
      newarr[i] = ptr[i];

    delete [] ptr;
    ptr = newarr;
  
  }

}

template <typename T>
Array<T>::Array( const Array<T> &arrayToCopy )  : size( arrayToCopy.size )  {

  ptr = new T[ size ]; // create space for pointer-based array

  for ( int i = 0; i < size; i++ )
    ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object

}  // end of copy constructor

template <typename T>
Array<T>::~Array() {

  delete [] ptr; // release pointer-based array space

} // end destructor

template <typename T>
int Array<T>::getSize() const  {

  return (size); // number of elements in Array

} // end function getSize

template <typename T>
const Array<T> & Array<T>::operator=( const Array<T> &right ) {

  if ( &right != this ) { // avoid self-assignment

    if ( size != right.size ) {
      
      delete [] ptr; // release space
      size = right.size; // resize this object
      ptr = new int[ size ]; // create space for array copy
    
    } // end inner if

    for ( int i = 0; i < size; i++ )	
      ptr[ i ] = right.ptr[ i ]; // copy array into object
  
  } 

  return (*this); // enables x = y = z, for example

} // end function operator=

template <typename T>
int Array<T>::operator==( const Array<T> &right ) const  {

  // arrays must have same # of elements to be equal
  if ( size != right.size )
    return false; 

  // all elements must be equal
  for ( int i = 0; i < size; i++ )
    if ( ptr[ i ] != right.ptr[ i ] )
      return false; 

  return (true); // Arrays are equal

} // end function operator==

 template <typename T>
   ostream &operator<<( ostream &output, const Array<T> &a ) {

  for ( int i = 0; i < a.size; i++ ) {

    output << a.ptr[ i ];

    if ( ( i + 1 ) % 8 == 0 ) // 8 numbers per row of output
      output << endl << "  ";
    
  } // end for

  output << endl;
  return (output); // enables cout << x << y;

} // end function operator<<
