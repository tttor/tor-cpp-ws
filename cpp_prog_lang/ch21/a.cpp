/*
===
Overloading the operator << to
mean ‘‘put to’’ gives a better notation and lets the programmer output a sequence of objects in a
single statement. For example:
c e r r << "x = " << x << ´\ n ´;

This style can be used as long as x is of a type for which operator << is defined and a user
can trivially define operator << for a new type.

===
Several standard streams are declared in <i o s t r e a m >:
o s t r e a m c o u t ; // standard output stream of char
o s t r e a m c e r r ; // standard unbuffered output stream for error messages
o s t r e a m c l o g ; // standard output stream for error messages
w o s t r e a m w c o u t ; // wide stream corresponding to cout
w o s t r e a m w c e r r ; // wide stream corresponding to cerr
w o s t r e a m w c l o g ; // wide stream corresponding to clog
The c e r r and c l o g streams refer to the same output destination; they simply differ in the buffering
they provide. The c o u t writes to the same destination as C’s s t d o u t (§21.8), while c e r r and c l o g
write to the same destination as C’s s t d e r r .

===
An o p e r a t o r <<() returns a reference to the o s t r e a m for which it was called so that another o p e r a t
o r <<() can be applied to it. For example,

c e r r << "x = " << x ;

where x is an i n t , will be interpreted as:

(c e r r .o p e r a t o r <<("x = ")).o p e r a t o r <<(x );

In particular, this implies that when several items are printed by a single output statement, they will
be printed in the expected order: left to right.

A b o o l value will be output as 0 or 1 by default. If you don’t like that, you can set the formatting
flag b o o l a l p h a from <i o m a n i p > (§21.4.6.2) and get t r u e or f a l s e . For example:
i n t m a i n ()
{
c o u t << t r u e << ´ ´ << f a l s e << ´\ n ´;
c o u t << b o o l a l p h a ; // use symbolic representation for true and false
c o u t << t r u e << ´ ´ << f a l s e << ´\ n ´;
}
This prints:
1 0
t r u e f a l s e

===
Consider a userdefined
type c o m p l e x (§11.3):
c l a s s c o m p l e x {
p u b l i c :
d o u b l e r e a l () c o n s t { r e t u r n r e ; }
d o u b l e i m a g () c o n s t { r e t u r n i m ; }
/ / ...
};
Operator << can be defined for the new type c o m p l e x like this:
o s t r e a m & o p e r a t o r <<(o s t r e a m &s , c o m p l e x z )
{
r e t u r n s << ´(´ << z .r e a l () << ´,´ << z .i m a g () << ´)´;
}
This << can then be used exactly like << for a builtin
type. For example,
i n t m a i n ()
{
c o m p l e x x (1 ,2 );
c o u t << "x = " << x << ´\ n ´;
}
produces
x= (1,2)

===
Whitespace is defined as the standard
C whitespace (blank, tab, newline, formfeed, and carriage return) by a call to i s s p a c e () as defined
in <c c t y p e > (§20.4.2).

===
In addition, we can read into an array of characters:

you can specify a maximum for the number of characters to be read by >>: i s .w i d t h (n )
specifies that the next >> on i s will read at most n 1
characters into an array. For example:
v o i d g ()
{
c h a r v [4 ];
c i n .w i d t h (4 );
c i n >> v ;
c o u t << "v = " << v << e n d l ;
}
This will read at most three characters into v and add a terminating 0 .

===
Every stream (i s t r e a m or o s t r e a m ) has a state associated with it. Errors and nonstandard conditions
are handled by setting and testing this state appropriately.

If the state is g o o d () the previous input operation succeeded. If the state is g o o d (), the next input
operation might succeed; otherwise, it will fail. Applying an input operation to a stream that is not
in the g o o d () state is a null operation. If we try to read into a variable v and the operation fails,
the value of v should be unchanged (it is unchanged if v is a variable of one of the types handled by
i s t r e a m or o s t r e a m member functions). The difference between the states f a i l () and b a d () is
subtle. When the state is f a i l () but not also b a d (), it is assumed that the stream is uncorrupted
and that no characters have been lost. When the state is b a d (), all bets are off.

===
A g e t l i n e () behaves like its corresponding
g e t (), except that it removes its terminator from the i s t r e a m

===
Floatingpoint
output is controlled by a format and a precision:
– The general format lets the implementation choose a format that presents a value in the style
that best preserves the value in the space available. The precision specifies the maximum
number of digits. It corresponds to p r i n t f ()’s %g (§21.8).
– The scientific format presents a value with one digit before a decimal point and an exponent.
The precision specifies the maximum number of digits after the decimal point. It corresponds
to p r i n t f ()’s %e .
– The fixed format presents a value as an integer part followed by a decimal point and a fractional
part. The precision specifies the maximum number of digits after the decimal point.
It corresponds to p r i n t f ()’s %f .
We control the floatingpoint
output format through the state manipulation functions. In particular,
we can set the notation used for printing floatingpoint
values without side effects on other parts of
the stream state. For example,

c o u t << "d e f a u l t :\ t " << 1 2 3 4 .5 6 7 8 9 << ´\ n ´;
c o u t .s e t f (i o s _ b a s e :: s c i e n t i f i c ,i o s _ b a s e :: f l o a t f i e l d ); // use scientific format
c o u t << "s c i e n t i f i c :\ t " << 1 2 3 4 .5 6 7 8 9 << ´\ n ´;
c o u t .s e t f (i o s _ b a s e :: f i x e d ,i o s _ b a s e :: f l o a t f i e l d ); // use fixedpoint
format
c o u t << "f i x e d :\ t " << 1 2 3 4 .5 6 7 8 9 << ´\ n ´;
c o u t .s e t f (0 ,i o s _ b a s e :: f l o a t f i e l d ); // reset to default (that is, general format)
c o u t << "d e f a u l t :\ t " << 1 2 3 4 .5 6 7 8 9 << ´\ n ´;

produces
d e f a u l t : 1 2 3 4 .5 7
s c i e n t i f i c : 1 .2 3 4 5 6 8 e +0 3
f i x e d : 1 2 3 4 .5 6 7 8 9 0
d e f a u l t : 1 2 3 4 .5 7
The default precision (for all formats) is 6 .

A call of p r e c i s i o n () affects all floatingpoint
I/O operations for a stream up until the next call of
p r e c i s i o n (). Thus,
c o u t .p r e c i s i o n (8 );
c o u t << 1 2 3 4 .5 6 7 8 9 << ´ ´ << 1 2 3 4 .5 6 7 8 9 << ´ ´ << 1 2 3 4 5 6 << ´\ n ´;
c o u t .p r e c i s i o n (4 );
c o u t << 1 2 3 4 .5 6 7 8 9 << ´ ´ << 1 2 3 4 .5 6 7 8 9 << ´ ´ << 1 2 3 4 5 6 << ´\ n ´;
produces
1 2 3 4 .5 6 7 9 1 2 3 4 .5 6 7 9 1 2 3 4 5 6
1 2 3 5 1 2 3 5 1 2 3 4 5 6

Note that floatingpoint
values are rounded rather than just truncated and that p r e c i s i o n () doesn’t
affect integer output.
The u p p e r c a s e flag (§21.4.1) determines whether e or E is used to indicate the exponents in the
scientific format.

===
we can
explicitly request that an output buffer be flushed:
c o u t << x << f l u s h << y << f l u s h ;

These declarations ensure that
c o u t << f l u s h ;
is resolved as
c o u t .o p e r a t o r <<(f l u s h );
which calls
f l u s h (c o u t );
which then invokes
c o u t .f l u s h ();
The whole rigmarole is done (at compile time) to allow b a s i c _ o s t r e a m :: f l u s h () to be called
using the c o u t <<f l u s h notation.

===
NEXT
21.5.1 File Streams [io.filestream]
*/

#include <iostream>

class Complex
{
public:
Complex(double r, double i)
: r_(r), i_(i)
{}

double
real() const
{
  return r_;
}

double
imag() const
{
  return i_;
}

//std::ostream&
//operator<<(std::ostream& s)
//{
////  return s << "(" << z.real() << ", " << z.imag() << ")";
//  return s << this->real();
//}

private:
double r_;
double i_;
};

// This should be a free function
// http://stackoverflow.com/questions/10744787/operator-must-take-exactly-one-argument
std::ostream&
operator<< (std::ostream& s, Complex z)
{
  return s << "(" << z.real() << ", " << z.imag() << ")";
}

std::string
get_password()
{
  std::string s;
  std::cout << "Pass= ";
  std::cin >> s;
  
  std::cout << "Your pass= " << s << std::endl;
  
  return s;
}

int
main()
{
  using namespace std;
  
//  //
//  cerr << "from cerr\n";
//  clog << "from clog\n";
//  
//  //
//  Complex z(1,2);
//  cout << z << endl;
//  
//  //
//  get_password();
  
  //
  int x = 1;
  int y = 3;
  
  cout << x << flush << y << flush << endl;
  
  //
  cout << 1234 << ", " << hex << 1234 << ", " << oct << 1234 << endl;
  cout << setprecision(3) << 12.345;   
  
  return 0;
}
