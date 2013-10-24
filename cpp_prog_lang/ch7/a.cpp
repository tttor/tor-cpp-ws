/*
===
Argument types
are checked and implicit argument type conversion takes place when necessary.
d o u b l e s q r t (d o u b l e );
d o u b l e s r 2 = s q r t (2 ); // call sqrt() with the argument double(2)
d o u b l e s q 3 = s q r t ("t h r e e "); // error: sqrt() requires an argument of type double

===
A static variable provides a function with ‘‘a memory’’ without introducing a global variable that
might be accessed and corrupted by other functions

If a local variable is declared s t a t i c , a single, statically allocated object will be used to
represent that variable in all calls of the function. It will be initialized only the first time the thread
of execution reaches its definition.

===
It can, however,
be noticeably more efficient to pass a large object by reference than to pass it by value. In that
case, the argument might be declared c o n s t to indicate that the reference is used for efficiency reasons
only and not to enable the called function to change the value of the object.

===
If an array is used as a function argument, a pointer to its initial element is passed.

That is, an argument of type T [] will be converted to a T * when passed as an argument. This
implies that an assignment to an element of an array argument changes the value of an element of
the argument array. In other words, arrays differ from other types in that an array is not (and cannot
be) passed by value.

The size of an array is not available to the called function.

===
The type of a return expression is checked against the type of the returned type, and
all standard and userdefined
type conversions are performed. For example:
d o u b l e f () { r e t u r n 1 ; } // 1 is implicitly converted to double(1)

===
The store is reused after the function returns, so a pointer to a local variable should never be
returned. The contents of the location pointed to will change unpredictably:
i n t * f p () { i n t l o c a l = 1 ; ...; r e t u r n &l o c a l ; } // bad
This error is less common than the equivalent error using references:
i n t & f r () { i n t l o c a l = 1 ;  ...; r e t u r n l o c a l ; } // bad

===
However, a call of a v o i d function doesn’t yield a value,
so a v o i d function can use a call of a v o i d function as the expression in a r e t u r n statement. For
example:
v o i d g (i n t * p );
v o i d h (i n t * p ) {  ...;  r e t u r n g (p ); } // ok: return of ‘‘no value’’

===
Return types are not considered in overload resolution.

The effect of a default argument can alternatively be achieved by overloading:
v o i d p r i n t (i n t v a l u e , i n t b a s e );
i n l i n e v o i d p r i n t (i n t v a l u e ) { p r i n t (v a l u e ,1 0 ); }
However, overloading makes it less obvious to the reader that the intent is to have a single print
function plus a shorthand.

===
A default argument is type checked at the time of the function declaration and evaluated at the
time of the call.

===
That is, dereferencing
of a pointer to function using * is optional. Similarly, using & to get the address of a function
is optional:

Pointers to functions have argument types declared just like the functions themselves. In pointer
assignments, the complete function type must match exactly.

A function must be called through a pointer to function with exactly the right argument and return
types.

===
#d e f i n e N A M E 2 (a ,b ) a ##b
i n t N A M E 2 (h a c k ,c a h )();
will produce
i n t h a c k c a h ();
for the compiler to read.


One use of macros is almost impossible to avoid: Conditional Compilation
For example,
i n t f (i n t a
#i f d e f a r g _ t w o
,i n t b
#e n d i f
) ;
produces
i n t f (i n t a
) ;

===
7.9 Advice [dcl.advice]
[1] Be suspicious of nonc
o n s t reference arguments; if you want the function to modify its arguments,
use pointers and value return instead; §5.5.
[2] Useconst reference arguments when you need to minimize copying of arguments; §5.5.
[3] Useconst extensively and consistently; §7.2.
[4] Avoid macros; §7.8.
[5] Avoid unspecified numbers of arguments; §7.6.
[6] Don’t return pointers or references to local variables; §7.3.
[7] Use overloading when functions perform conceptually the same task on different types; §7.4.
[8] When overloading on integers, provide functions to eliminate common ambiguities; §7.4.3.
[9] When considering the use of a pointer to function, consider whether a virtual function
(§2.5.5) or a template (§2.7.2) would be a better alternative; §7.7.
[10] If you must use macros, use ugly names with lots of capital letters; §7.8.
*/

#include<iostream>
#include<stdio.h>

inline
int
fac(int n)
{
  return (n<2) ? 1 : n*fac(n-1);
}

void
test_static_var()
{
  static size_t i = 0;
  
  ++i;
  std::cout << "i= " << i << std::endl;
}

void
f(int)
{
  std::cout << "inside f(int)" << std::endl;
}

void
g()
{
  void f(double);
  
  f(1);// Clearly, f (i n t ) would have been the best match for f (1 ), but only f (d o u b l e ) is in scope.
}

void
f(double)
{
  std::cout << "inside f(double)" << std::endl;
}


int
main()
{
  using namespace std;
 
//  // 
//  cout << "fac(3)= "<< fac(3) << endl;

//  //
//  test_static_var();
//  test_static_var();
  
//  // The scope of overloaded function
//  g();
  
  //
  void (*ptr_to_f) (int);
  ptr_to_f = &f;
  ptr_to_f(7);
  
  return 0;
}
