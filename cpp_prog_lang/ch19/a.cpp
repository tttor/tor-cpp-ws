/*
===
Iterators support an abstract model of data as sequences of objects (§19.2). Allocators provide a
mapping from a lowerlevel
model of data as arrays of bytes into the higherlevel
object model
(§19.4).

===
The iterator classes and functions are declared in namespace s t d and found in <i t e r a t o r >.

===
An iterator is not a general pointer. Rather, it is an abstraction of the notion of a pointer into an
array. There is no concept of a ‘‘null iterator.’’ The test to determine whether an iterator points to
an element or not is conventionally done by comparing it against the end of its sequence (rather
than comparing it against a n u l l element).

===
An iterator that points to an element is said to be valid and can be dereferenced (using *, [], or
>
appropriately).

===
The
end of a sequence can be thought of as an iterator pointing to a hypothetical element position onepastthelast
element of a sequence.

===
Both read and write are through the iterator dereferenced by *:
*p = x ; // write x through p
x = *p ; // read through p into x

===
Only randomaccess
iterators can have an integer added or subtracted for relative addressing.

However, except for output iterators, the distance between two iterators can always be found by
iterating through the elements, so a d i s t a n c e () function is provided:
t e m p l a t e <c l a s s I n > t y p e n a m e i t e r a t o r _ t r a i t s <I n >:: d i f f e r e n c e _ t y p e d i s t a n c e (I n f i r s t , I n l a s t )
{
t y p e n a m e i t e r a t o r _ t r a i t s <I n >:: d i f f e r e n c e _ t y p e d = 0 ;
w h i l e (f i r s t ++!=l a s t ) d ++;
r e t u r n d ;
}

===
To express such
operations, we must be able to refer to types related to an iterator such as ‘‘the type of the object
referred to by an iterator’’ and ‘‘the type of the distance between two iterators.’’ The related types
of an iterator are described by a small set of declarations in an i t e r a t o r _ t r a i t s template class:

t e m p l a t e <c l a s s I t e r > s t r u c t i t e r a t o r _ t r a i t s {
t y p e d e f t y p e n a m e I t e r :: i t e r a t o r _ c a t e g o r y i t e r a t o r _ c a t e g o r y ; // §19.2.3
t y p e d e f t y p e n a m e I t e r :: v a l u e _ t y p e v a l u e _ t y p e ; // type of element
t y p e d e f t y p e n a m e I t e r :: d i f f e r e n c e _ t y p e d i f f e r e n c e _ t y p e ;
t y p e d e f t y p e n a m e I t e r :: p o i n t e r p o i n t e r ; // return type of operator– >()
t y p e d e f t y p e n a m e I t e r :: r e f e r e n c e r e f e r e n c e ; // return type of operator*()
};

The d i f f e r e n c e _ t y p e is the type used to represent the difference between two iterators, and the
i t e r a t o r _ c a t e g o r y is a type indicating what operations the iterator supports. For ordinary pointers,
specializations (§13.5) for <T *> and <c o n s t T *> are provided. In particular:
t e m p l a t e <c l a s s T > s t r u c t i t e r a t o r _ t r a i t s <T *> { // specialization for pointers
t y p e d e f r a n d o m _ a c c e s s _ i t e r a t o r _ t a g i t e r a t o r _ c a t e g o r y ;
t y p e d e f T v a l u e _ t y p e ;
t y p e d e f p t r d i f f _ t d i f f e r e n c e _ t y p e ;
t y p e d e f T * p o i n t e r ;
t y p e d e f T & r e f e r e n c e ;
};

===
Note that r e f e r e n c e and p o i n t e r are not iterators. They are intended to be the return types of o p e r a
t o r *() and o p e r a t o r >(),
respectively, for some iterator.

===
Using i t e r a t o r _ t r a i t s <T >:: i t e r a t o r _ c a t e g o r y allows a programmer to provide alternative
implementations so that a user who cares nothing about the implementation of algorithms automatically
gets the most appropriate implementation for each data structure used. In other words, it
allows us to hide an implementation detail behind a convenient interface. Inlining can be used to
ensure that this elegance is not bought at the cost of runtime
efficiency.

===
The b a c k _ i n s e r t e r () causes elements to be added to the end of the container, f r o n t _ i n s e r t e r ()
causes elements to be added to the front, and ‘‘plain’’ i n s e r t e r () causes elements to be added
before its iterator argument. For i n s e r t e r (c ,p ), p must be a valid iterator for c .

When written to, an inserter inserts a new element into a sequence using p u s h _ b a c k (),
p u s h _ f r o n t (), or i n s e r t () (§16.3.6) rather than overwriting an existing element.

===
The standard containers provide r b e g i n () and r e n d () for iterating through elements in reverse
order (§16.3.2)

A r e v e r s e _ i t e r a t o r is implemented using an i t e r a t o r called c u r r e n t . That i t e r a t o r can (only) point
to the elements of its sequence plus its onepasttheend
element. However, the r e v e r s e _ i t e r a t o r ’s
onepasttheend
element is the original sequence’s (inaccessible) onebeforethebeginning
element.
Thus, to avoid access violations, c u r r e n t points to the element after the one the
r e v e r s e _ i t e r a t o r refers to. This implies that * returns the value *(c u r r e n t 1
) and that ++ is
implemented using on
c u r r e n t .

===
Note that postincrement (postfix ++) involves a temporary and preincrement does not. For this
reason, it is best to prefer ++p over p ++ for iterators.

===
An a l l o c a t o r is used to insulate implementers of algorithms and containers that must allocate memory
from the details of physical memory. An allocator provides standard ways of allocating and
deallocating memory and standard names of types used as pointers and references. Like an iterator,
an allocator is a pure abstraction. Any type that behaves like an allocator is an allocator.

===
NEXT
[1] When writing an algorithm, decide which kind of iterator is needed to provide acceptable efficiency
and express the algorithm using the operators supported by that kind of iterator (only);
§19.2.1.
[2] Use overloading to provide moreefficient
implementations of an algorithm when given as
arguments iterators that offer more than minimal support for the algorithm; §19.2.3.
[3] Use i t e r a t o r _ t r a i t s to express suitable algorithms for different iterator categories; §19.2.2.
[4] Remember to use ++ between accesses of i s t r e a m _ i t e r a t o r s and o s t r e a m _ i t e r a t o r s; §19.2.6.
[5] Use inserters to avoid container overflow; §19.2.4.
[6] Use extra checking during debugging and remove checking later only where necessary;
§19.3.1.
[7] Prefer ++p top++; §19.3.
[8] Use uninitialized memory to improve the performance of algorithms that expand data structures;
§19.4.4.
[9] Use temporary buffers to improve the performance of algorithms that require temporary data
structures; §19.4.4.
[10] Think twice before writing your own allocator; §19.4.
[11] Avoid m a l l o c (), f r e e (), r e a l l o c (), etc.; §19.4.6.
[12] You can simulate a t y p e d e f of a template by the technique used for r e b i n d ; §19.4.1.
*/
#include <iostream>
#include <iterator>     // std::ostream_iterator
#include <cstring> // strcmp

using namespace std;

//v o i d f ()
//{
//o s t r e a m _ i t e r a t o r <i n t > o s (c o u t ); // write ints to cout through os
//*o s = 7 ; // output 7
//++o s ; // get ready for next output
//*o s = 7 9 ; // output 79
//}

void 
f()
{
  ostream_iterator<int> os(cout);
  *os = 7;
  ++os;
  *os = 79;
}
  
int 
main()
{
//  f();

 std::string nihongo = "みんあのにほんご";
 std::cout << nihongo << std::endl;
 
 std::string nihongo_2 = "みんあのにほんご";
 std::string nihongo_3 = "にほん";
  
 if( !strcmp(nihongo.c_str(),nihongo_3.c_str()) )
   std::cout << "same" << std::endl; 
 else
   std::cout << "not same" << std::endl; 
 return 0;
}

