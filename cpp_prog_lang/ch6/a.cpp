/*
The stream c e r r is an unbuffered output stream usually used to report errors (§21.2.1).

Conventionally, m a i n () should return zero if the program terminates normally and nonzero otherwise
(§3.2).

When this is done, m a i n () is given two
arguments specifying the number of arguments, usually called a r g c , and an array of arguments,
usually called a r g v . The arguments are character strings, so the type of a r g v is c h a r *[a r g c +1 ].
The name of the program (as it occurs on the command line) is passed as a r g v [0 ], so a r g c is
always at least 1 . The list of arguments is zeroterminated;
that is, a r g v [a r g c ]==0 .

p.120:
runtime checked conversion d y n a m i c _ c a s t < type > ( expr )
compiletime checked conversion s t a t i c _ c a s t < type > ( expr )
unchecked conversion r e i n t e r p r e t _ c a s t < type > ( expr )
_c _ o_ n_ s_ t_ c_o_n_v_e_r_si_o_n_________________c_ o_ n_ s_ t_ __ c_ a_ s t_ _<_t_y_p_e_>_ _(_e_x_p_r_ _)_

The one's complement operator (~), sometimes called the "bitwise complement" operator, yields a bitwise one's complement of its operand. That is, every bit that is 1 in the operand is 0 in the result. Conversely, every bit that is 0 in the operand is 1 in the result. The operand to the one's complement operator must be an integral type.

conditional expression --> expr ? expr : expr

Unary operators and assignment operators are rightassociative;
all others are leftassociative.
For example, a =b =c means a =(b =c ), a +b +c means (a +b )+c , and *p ++ means *(p ++), not (*p)++.

The order of evaluation of subexpressions within an expression is undefined
i n t x = f (2 )+g (3 ); // undefined whether f() or g() is called first

i n t i = 1 ;
v[i] = i++; / / undefined result

The operators , (comma), && (logical and), and || (logical or) guarantee that their lefthand
operand is evaluated before their righthand operand. For example, b =(a =2 ,a +1 ) assigns 3 to b

For builtin
types, the second operand of
&& is evaluated only if its first operand is t r u e , and the second operand of || is evaluated only if its
first operand is f a l s e ; this is sometimes called shortcircuit
evaluation

i f (0 <= x <= 9 9 ) // ...
This is legal, but it is interpreted as (0 <=x )<=9 9 , where the result of the first comparison is either
t r u e or f a l s e .

The value of
++x is the new (that is, incremented) value of x . For example, y =++x is equivalent to y =(x +=1 ).
The value of x++, however, is the old value of x.

Therefore, you should measure carefully before believing that some piece of handcrafted
code outperforms library functions.

A named object has its lifetime determined by its scope (§4.9.4). However, it is often useful to create
an object that exists independently of the scope in which it was created. In particular, it is common
to create objects that can be used after returning from the function in which they were created.
The operator n e w creates such objects, and the operator d e l e t e can be used to destroy them.
Objects allocated by n e w are said to be ‘‘on the free store’’ (also, to be ‘‘heap objects,’’ or ‘‘allocated
in dynamic memory’’)

An object created by n e w exists until it is explicitly destroyed by d e l e t e

A C++ implementation does not guarantee the presence of a ‘‘garbage
collector’’ that looks out for unreferenced objects and makes them available to n e w for reuse.

To deallocate space allocated by n e w , d e l e t e and d e l e t e [] must be able to determine the size of
the object allocated. This implies that an object allocated using the standard implementation of
n e w will occupy slightly more space than a static object. Typically, one word is used to hold the
object’s size.

If you feel tempted to use an explicit type conversion, take the time to consider if it is really
necessary

From C, C++ inherited the notation (T )e , which performs any conversion that can be expressed
as a combination of s t a t i c _ c a s t s, r e i n t e r p r e t _ c a s t s, and c o n s t _ c a s t s to make a value of type T
from the expression e (§B.2.3).
*/

#include <sstream>
#include <vector>

using namespace std;

int 
main(int argc, char* argv[])
{
  vector<int>* p = new vector<int>(3);  // individual objects
  int* q = new int[3];
  
  delete p;
  delete[] q;
  
  int i = int(5.43);  // For a builtin type T , T (e ) is equivalent to s t a t i c _ c a s t <T >(e ).
  int j = int(); // default int value; The constructor notation T () is used to express the default value of type T .
  /*
  The value of an explicit use of the constructor for a builtin
type is 0 converted to that type (§4.9.5).
Thus, i n t () is another way of writing 0 . For a userdefined
type T , T () is defined by the default
constructor (§10.4.2), if any.


if (a <= b)
  m a x = b ;
e l s e
  m a x = a ;

is better expressed like this:

m a x = (a <=b ) ? b : a ;
  */
  
  
}
