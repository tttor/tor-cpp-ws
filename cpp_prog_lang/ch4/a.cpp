/*
////////////BOOL
By definition, t r u e has the value 1 when converted to an integer and f a l s e has the value 0 . Conversely,
integers can be implicitly converted to b o o l values: nonzero integers convert to t r u e and 0
converts to f a l s e .

A pointer can be implicitly converted to a b o o l (§C.6.2.5). A nonzero pointer converts to t r u e ;
zerovalued
pointers convert to f a l s e .

//////////////////////CHAR
The possibility of converting a c h a r
to an integer raises the question: is a c h a r signed or unsigned? The 256 values represented by an
8bit
byte can be interpreted as the values 0 to 2 5 5 or as the values 1
2 7 to 1 2 7 . Unfortunately,
which choice is made for a plain c h a r is implementationdefined
(§C.1, §C.3.4). C++ provides two
types for which the answer is definite; s i g n e d c h a r , which can hold at least the values 1
2 7 to 1 2 7 ,
and u n s i g n e d c h a r , which can hold at least the values 0 to 2 5 5 . Fortunately, the difference matters
only for values outside the 0 to 1 2 7 range, and the most common characters are within that range.

////////////////////////////INT
Unlike plain c h a r s, plain i n t s are always signed. The signed i n t types are simply more explicit
synonyms for their plain i n t counterparts.
*/

///////////////////////////////SIZE
// Sizes of C++ objects are expressed in terms of multiples of the size of a c h a r , so by definition the size of a c h a r is 1 .
// can be obtained using the s i z e o f operator
// In addition, it is guaranteed that a c h a r has at least 8 bits, a s h o r t at least 16 bits, and a l o n g at least 32 bits

/////////////////////////////////DECLARATION
//The scope of a global name extends from the point of declaration to the end of the file in which its declaration occurs
//A hidden global name can be referred to using the scope resolution operator ::. (see.p.82)
//If no initializer is specified, a global (§4.9.4), namespace (§8.2), or local static object (§7.1.2, §10.2.4) (collectively called static objects) is initialized to 0 of the appropriate type.
// Local variables (sometimes called automatic objects) and objects created on the free store (sometimes called dynamic objects or heap objects) are not initialized by default
// Using the n e w and d e l e t e operators, you can create objects whose lifetimes are controlled directly (§6.2.6).

///////////////////////////OTHER
//If your program is a success, it is likely to be ported, so someone will have to find and fix problems related to implementationdependent features.
// Writing truly portable lowlevel code is harder
#include <iostream>
#include <limits>//When needed, implementationdependent aspects about an implementation

using namespace std;

  // enum
  // The range of an enumeration holds all the enumeration’s enumerator values rounded up to the nearest larger binary power minus 1 . The range goes down to 0 if the smallest enumerator is nonnegative and to the nearest lesser negative binary power if the smallest enumerator is negative.
  // By default, enumerations are converted to integers for arithmetic operations (§6.2).
  
enum flag {a=3, b=14}; // range 0:15
// inside the main(), flag = 99; //undefined: 99 is not within the range of flag
enum { ASM , AUTO , BREAK };// elememnts MUST be separated by a comma
enum use_name { ASM2 , AUTO2 , BREAK2 };// elememnts MUST be separated by a comma
// Declaring a variable k e y w o r d instead of plain i n t can give both the user and the compiler a hint as to the intended use.

struct A
{
  int a;
};

struct B
{ 
  int b;
}B1;

typedef
struct C
{
  int c;
}C1;

int
main()
{
  // Similarly, the suffix L can be used to write explicitly l o n g literals. For example, 3 is an i n t , 3U is an u n s i g n e d i n t , and 3 L is a l o n g i n t . If no suffix is provided, the compiler gives an integer literal a suitable type based on its value and the implementation’s integer sizes (§C.4).
  int i; //long int i;
  
  i = 3L;
  //  FLoat
  //If you don’t have that understanding, get advice, take the time to learn, or use d o u b l e and hope for the best
  // If you want a floatingpoint literal of type f l o a t , you can define one using the suffix f or F :
  
  double d;
  d = 12e-1;
  
  // Size
  
  cout << sizeof(char) << endl;
  cout << sizeof(bool) << endl;
  cout << sizeof(size_t) << endl;
  cout << sizeof(use_name) << endl;

  cout << "l a r g e s t f l o a t == " << numeric_limits<float>::max() << ", c h a r i s s i g n e d == " << numeric_limits<char>::is_signed << '\n';
  
  //////////////////////////////??VOID
  //It is used either to specify that a function does not return a value or as the base type for pointers to objects of unknown type
  void* any_ptr;
  
  ///////////////////////////////struct declaration
  A a1;
  a1.a = 1;
  
  B1.b = 1;
 
  C1 c1;
  c1.c = 1;
  
  C c2;
  c2.c = 2;
 
// A declaration consists of four parts: an optional ‘‘specifier,’’ a base type, a declarator, and an optional initializer. Except for function and namespace definitions, a declaration is terminated by a semicolon.   
// The first character must be a letter. The underscore character _ is considered a letter. Names starting with an underscore are reserved for special facilities in the implementation and the runtime environment, so such names should not be used in application programs.
  return 0;
}
