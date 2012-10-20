#include <iostream>

using namespace std;

// Note that a b o o l occupies at least as much space as a c h a r (§4.6).

//Because of standard conversions (§C.6.2.3), 0 can be used as a constant of any integral (§4.1.1), floatingpoint, pointer, or pointertomember type. The type of zero will be determined by context

// No object is allocated with the address 0

//Because of C++’s tighter type checking, the use of plain 0 , rather than any suggested N U L L macro, leads to fewer problems.

// The type of a string literal is ‘‘array of the appropriate number of c o n s t characters,’’ so " B o h r " is of type c o n s t c h a r [5 ].

// Note that == compares addresses (pointer values) when applied to pointers, and not the values pointed to.

//The snag is that it is impossible to avoid the implicit conversion. In other words, there is no way of declaring a function so that the array v is copied when the function is called.

// The implicit conversion of the array argument to a pointer means that the size of the array is lost to the called function. Thus, we need to call strln()

/*
Subtraction of pointers is defined only when both pointers point to elements of the same array
(although the language has no fast way of ensuring that is the case). When subtracting one pointer
from another, the result is the number of array elements between the two pointers (an integer). One
can add an integer to a pointer or subtract an integer from a pointer; in both cases, the result is a
pointer value. If that value does not point to an element of the same array as the original pointer or
one beyond, the result of using that value is undefined

Addition of pointers
makes no sense and is not allowed.

Symbolic constants should be used systematically to avoid ‘‘magic numbers’’ in code.

NOTE:Strings are terminated by the character ´\0´
*/


//A string literal is statically allocated so that it is safe to return one from a function

const char* error_msg(int i)
{
// ...
return  "r a n g e e r r o r ";
}
// The memory holding r a n g e e r r o r will not go away after a call of e r r o r _ m e s s a g e ().

int* 
f(char*); // function taking a char* argument; returns a pointer to int

int main()
{
  char** ppc;// pointer to pointer to char
  int* ap[15];// array of 15 pointers to ints

  int (*fp)(char*); // pointer to function taking a char* argument; returns an int. What is this used for?
  
  cout << "beep \a \n";
  
  char ls[] = "long"
              "string";
  
  cout << ls << endl;            
  
  string ls2= "long"
              "string2";
  
  cout << ls2 << endl;  
  
  const char* ptr;// pointer to a const char
  
  char c = 'v';
  char* const const_ptr = &c;// const pointer, must be initialized
  
  // REFERENCE, see p.98 for a clear ilustration ref vs ptr
/*  
  the value of a reference cannot be changed after initialization; it
always refers to the object it was initialized to denote. To get a pointer to the object denoted by a
reference r r , we can write &r r

Consequently ‘‘plain’’ reference arguments should be used
only where the name of the function gives a strong hint that the reference argument is modified.
*/

  double d = 4.;
  
  //double& ref = 4; // leads to: error: invalid initialization of non-const reference of type ‘double&’ from a temporary of type ‘int’

  const double& ref2 = 5; 
  
  /*
  STRUCT
  
  You can minimize wasted space by simply
ordering members by size (largest member first). However, it is usually best to order members
for readability and sort them by size only if there is a demonstrated need to optimize.

In that case, the plain name (s t a t ) is the name of the nonstructure,
and the structure must be
referred to with the prefix s t r u c t .
  */

}s
