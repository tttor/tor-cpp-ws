/*
===
A string is a sequence of characters. The standard library s t r i n g provides string manipulation operations
such as subscripting (§20.3.3), assignment (§20.3.6), comparison (§20.3.8), appending
(§20.3.9), concatenation (§20.3.10), and searching for substrings (§20.3.11).

From C, C++ inherited the notion of strings as zeroterminated
arrays of c h a r and a set of functions
for manipulating such Cstyle
strings (§20.4.1).

===
A character set is a mapping between a character (some conventional symbol) and an integer value.

C++ programmers usually assume that the standard American character set (ASCII) is available,
but C++ makes allowances for the possibility that some characters may be missing in a
programmer’s environment. For example, in the absence of characters such as [ and {, keywords
and digraphs can be used (§C.3.1).

===
The b a s i c _ s t r i n g is similar to v e c t o r (§16.3), except that b a s i c _ s t r i n g provides some typical string
operations, such as searching for substrings, instead of the complete set of operations offered by
v e c t o r .

===
Like other containers, a s t r i n g provides iterators for ordinary and reverse iteration:
The s t r i n g iterators are not range checked.

===
Individual characters of a s t r i n g can be accessed through subscripting:

Outofrange
access causes a t () to throw an o u t _ o f _ r a n g e .
Compared to v e c t o r , s t r i n g lacks f r o n t () and b a c k (). To refer to the first and the last character
of a s t r i n g , we must say s [0 ] and s [s .l e n g t h ()1
], respectively. The pointer/array equivalence
(§5.3) doesn’t hold for s t r i n g s . If s is a s t r i n g , &s [0 ] is not the same as s .

===
A s t r i n g can be initialized by a Cstyle
string, by another s t r i n g , by part of a Cstyle
string, by part
of a s t r i n g , or from a sequence of characters. However, a s t r i n g cannot be initialized by a character
or an integer

===
Characters are numbered starting at position 0 so that a string is a sequence of characters numbered
0 to l e n g t h ()1.

===
Most string operations take a character position plus a number of characters. A position larger
than the size of the string throws an o u t _ o f _ r a n g e exception. A ‘‘too large’’ character count is
simply taken to be equivalent to ‘‘the rest’’ of the characters.

v o i d f ()
{
s t r i n g s = "S n o b o l 4 ";
s t r i n g s 2 (s ,1 0 0 ,2 ); // character position beyond end of string: throw out_of_range()
s t r i n g s 3 (s ,2 ,1 0 0 ); // character count too large: equivalent to s3(s,2,s.size()– 2)
s t r i n g s 4 (s ,2 ,s t r i n g :: n p o s ); // the characters starting from s[2]
}

===
Assignment with a single character to a string is supported even though initialization by a single
character isn’t:
v o i d f ()
{
s t r i n g s = ´a ´; // error: initialization by char
s = ´a ´; // ok: assignment
s = "a ";
s = s ;
}

===
The c _ s t r ()
function is like d a t a (), except that it adds a 0 (zero) at the end as a Cstringstyle
terminator

===
Note that a s t r i n g can contain the 0 character. Functions manipulating Cstyle
strings will
interprete such as 0 as a terminator. Be careful to put 0 s into a string only if you don’t apply Cstyle
functions to it or if you put the 0 there exactly to be a terminator.

===
If you find c _ s t r () appearing in your program with great frequency, it is probably because you
rely heavily on Cstyle
interfaces. Often, an interface that relies on s t r i n g s rather than Cstyle
strings is available and can be used to eliminate the conversions. Alternatively, you can avoid most
of the explicit calls of c _ s t r () by providing additional definitions of the functions that caused you
to write the c _ s t r () calls:

e x t e r n "C " i n t a t o i (c o n s t c h a r *);
i n t a t o i (c o n s t s t r i n g & s )
{
r e t u r n a t o i (s .c _ s t r ());
}

===
The usual comparison operators ==, !=, >, <, >=, and <= are provided for b a s i c _ s t r i n g s:
/ / similar declarations for !=, >, <, >=, and <=

===
Once created, a string can be manipulated in many ways. Of the operations that modify the value
of a string, is one of the most common is appending to it – that is, adding characters to the end.

The += operator is provided as the conventional notation for the most common forms of
append. For example:

Appending to the end can be noticeably more efficient than inserting into other positions. For
example:
s t r i n g c o m p l e t e _ n a m e 2 (c o n s t s t r i n g & f i r s t _ n a m e , c o n s t s t r i n g & f a m i l y _ n a m e )// poor algorithm
{
s t r i n g s = f a m i l y _ n a m e ;
s .i n s e r t (s .b e g i n (), ´ ´);
r e t u r n s .i n s e r t (0 ,f i r s t _ n a m e );
}

Insertion usually forces the s t r i n g implementation to do extra memory management and to move
characters around.

Because s t r i n g has a p u s h _ b a c k () operation (§16.3.5), a b a c k _ i n s e r t e r can be used for a
s t r i n g exactly as for general containers.

===
Appending is a special form of concatenation. Concatenation – constructing a string out of two
strings by placing one after the other – is provided by the + operator:

===
The simple call e r a s e (), with no argument, makes the string into an empty string. This is the
operation that is called c l e a r () for general containers (§16.3.6).
The variety of r e p l a c e () functions matches that of assignment. After all, r e p l a c e () is an
assignment to a substring.

===
The s u b s t r () function lets you specify a substring as a position plus a length:

===
Memoryrelated
issues are handled much as they are for v e c t o r

===
The << operator writes a string to an o s t r e a m (§21.2.1). The >> operator reads a whitespaceterminated
word (§3.6, §21.3.1) to its string, expanding the string as needed to hold the word. Initial
whitespace is skipped, and the terminating whitespace character is not entered into the string.

===
The g e t l i n e () function reads a line terminated by e o l to its string, expanding string as needed
to hold the line (§3.6). If no e o l argument is provided, a newline ´\ n ´ is used as the delimiter. The
line terminator is removed from the stream but not entered into the string. Because a s t r i n g
expands to hold the input, there is no reason to leave the terminator in the stream or to provide a
count of characters read in the way g e t () and g e t l i n e () do for character arrays (§21.3.4).

===
Functions for manipulating Cstyle
strings are found in <s t r i n g .h > and <c s t r i n g >:

===
A pointer is assumed to be nonzero, and the array of c h a r that it points to is assumed to be terminated
by 0 . The s t r n functions
pad with 0 if there are not n characters to copy. String comparisons
return 0 if the strings are equal, a negative number if the first argument is lexicographically before
the second, and a positive number otherwise.

===
Input and output of Cstyle
strings are usually done using the p r i n t f family of functions (§21.8).
In <s t d l i b .h > and <c s t d l i b >, the standard library provides useful functions for converting
strings representing numeric values into numeric values:
d o u b l e a t o f (c o n s t c h a r * p ); // convert p to double
i n t a t o i (c o n s t c h a r * p ); // convert p to int
l o n g a t o l (c o n s t c h a r * p ); // convert p to long
Leading whitespace is ignored. If the string doesn’t represent a number, zero is returned.

===
Equivalent functions for wide characters are found in <c w t y p e > and <w t y p e .h >.

===
20.5 Advice [string.advice]
[1] Prefer s t r i n g operations to Cstyle
string functions; §20.4.1.
[2] Use s t r i n g s as variables and members, rather than as base classes; §20.3, §25.2.1.
[3] You can pass s t r i n g s as value arguments and return them by value to let the system take care
of memory management; §20.3.6.
[4] Useat() rather than iterators or [] when you want range checking; §20.3.2, §20.3.5.
[5] Use iterators and [] rather than a t () when you want to optimize speed; §20.3.2, §20.3.5.
[6] Directly or indirectly, use s u b s t r () to read substrings and r e p l a c e () to write substrings;
§20.3.12, §20.3.13.
[7] Use the f i n d () operations to localize values in a s t r i n g (rather than writing an explicit loop);
§20.3.11.
[8] Append to a s t r i n g when you need to add characters efficiently; §20.3.9.
[9] Use s t r i n g s as targets of nontimecritical
character input; §20.3.15.
[10] Use s t r i n g :: n p o s to indicate ‘‘the rest of the s t r i n g ;’’ §20.3.5.
[11] If necessary, implement heavilyused
s t r i n g s using lowlevel
operations (rather than using
lowlevel
data structures everywhere); §20.3.10.
[12] If you use s t r i n g s, catch r a n g e _ e r r o r and o u t _ o f _ r a n g e somewhere; §20.3.5.
[13] Be careful not to pass a c h a r * with the value 0 to a string function; §20.3.7.
[14] Use c _ s t r rather to produce a Cstyle
string representation of a s t r i n g only when you have to;
§20.3.7.
[15] Use i s a l p h a (), i s d i g i t (), etc., when you need to know the classification of a character rather
that writing your own tests on character values; §20.4.2.
*/
#include <iostream>
#include <algorithm>

//// Although recommend in the book, so far, I dont understand what this declaraton is used for, and this remains compiled albeit it is commented out.
//extern "C" 
//int 
//atoi(const char* );

int
atoi(const std::string& s)
{
  return atoi(s.c_str());
}

int 
main()
{
  using namespace std;
  
  //
  string s;
  s = "vektor";
  
  string::iterator i;
  i = find(s.begin(),s.end(),'k');
  cout << "*i= " << *i << endl;
  
  string::size_type i1 = s.find("k");
  cout << "i1= " << i1 << endl;
  
  string::size_type i5 = s.find("d");
  cout << "i5= " << i5 << endl;
  
  std::string i_str;
  i_str = "88";
  
  int i2;
  i2 = atoi(i_str);
  cout << "i2= " << i2 << endl;
  
  // compare TODO strcmp vs. compare
  string s1 = "vektor";
  string s2 = s1;
  
//  if(s1==s2)
  if( !s1.compare(s2) )
  {
    cout << "s1==s2" << endl;
  }
  
  //
  string str;
  
  cout << "str= ";
  cin >> str;
  
  cout << "inputted str= " << str << endl;
  
  
  return 0; 
}
