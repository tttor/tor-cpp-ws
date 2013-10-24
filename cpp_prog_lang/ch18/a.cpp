/*
===
Remember, a
primary aim of writing code is to make its meaning clear to the next person reading it – and that
person just might be yourself a few years hence.

===
a sequence is called ‘‘half
open’’ because it includes the first value mentioned and not the second. A halfopen
sequence
allows many algorithms to be expressed without making the empty sequence a special case.

A sequence – especially a sequence in which random access is possible – is often called a
range. Traditional mathematical notations for a halfopen
range are [f i r s t ,l a s t ) and [f i r s t ,l a s t [.

===
An object of a class with an application operator (§11.9) is called a functionlike
object, a
functor, or simply a function object.

The most obvious, and probably also the most important, use of the () operator is to provide
the usual function call syntax for objects that in some way behave like functions. An object that
acts like a function is often called a functionlike
object or simply a function object (§18.4).

The standard library provides many useful function objects. To aid the writing of function objects,
the library provides a couple of base classes:

t e m p l a t e <c l a s s A r g , c l a s s R e s > s t r u c t u n a r y _ f u n c t i o n {
t y p e d e f A r g a r g u m e n t _ t y p e ;
t y p e d e f R e s r e s u l t _ t y p e ;
};

t e m p l a t e <c l a s s A r g , c l a s s A r g 2 , c l a s s R e s > s t r u c t b i n a r y _ f u n c t i o n {
t y p e d e f A r g f i r s t _ a r g u m e n t _ t y p e ;
t y p e d e f A r g 2 s e c o n d _ a r g u m e n t _ t y p e ;
t y p e d e f R e s r e s u l t _ t y p e ;
};

The purpose of these classes is to provide standard names for the argument and return types for use
by users of classes derived from u n a r y _ f u n c t i o n and b i n a r y _ f u n c t i o n .

===
A predicate is a function object (or a function) that returns a b o o l . For example, <f u n c t i o n a l >
defines:

t e m p l a t e <c l a s s T > s t r u c t l o g i c a l _ n o t : p u b l i c u n a r y _ f u n c t i o n <T ,b o o l > {
b o o l o p e r a t o r ()(c o n s t T & x ) c o n s t { r e t u r n !x ; }
};

t e m p l a t e <c l a s s T > s t r u c t l e s s : p u b l i c b i n a r y _ f u n c t i o n <T ,T ,b o o l > {
b o o l o p e r a t o r ()(c o n s t T & x , c o n s t T & y ) c o n s t { r e t u r n x <y ; }
};

v o i d f (v e c t o r <i n t >& v i , l i s t <i n t >& l i )
{
t y p e d e f l i s t <i n t >:: i t e r a t o r L I ;
t y p e d e f v e c t o r <i n t >:: i t e r a t o r V I ;
p a i r <V I ,L I > p 1 = m i s m a t c h (v i .b e g i n (), v i .e n d (), l i .b e g i n (), l e s s <i n t >());
/ / ...
}

Because an object is needed rather than a type, l e s s <i n t >() (with the parentheses) is used
rather than the tempting l e s s <i n t >.

===
In <f u n c t i o n a l >, the standard library supplies a few common predicates:
e q u a l _ t o Binary arg1==arg2
not_  equal_  to Binary arg1!=arg2
greater Binary arg1>arg2
less Binary arg1<arg2
greater_  equal Binary arg1>=arg2
less_  equal Binary arg1<=arg2
logical_  and Binary arg1&&arg2
logical_  or Binary arg1ïïarg2
logical_  not Unary !arg

Consequently, in <f u n c t i o n a l > the standard library provides:
p l u s Binary arg1+arg2
minus Binary arg1– arg2
multiplies Binary arg1*arg2
divides Binary arg1/arg2
modulus Binary arg1%arg2
negate Unary – arg

===
The standard library supports the composition
of function objects:

§18.4.4.1 A binder allows a twoargument
function object to be used as a singleargument
function by binding one argument to a value.

§18.4.4.2 A member function adapter allows a member function to be used as an argument to
algorithms.

§18.4.4.3 A pointer to function adapter allows a pointer to function to be used as an argument
to algorithms.

§18.4.4.4 A negater allows us to express the opposite of a predicate.

Collectively, these function objects are referred to as a d a p t e r s .

===
In parallel to b i n d 2 n d () and b i n d e r 2 n d , <f u n c t i o n a l > provides b i n d 1 s t () and b i n d e r 1 s t for
binding the first argument of a binary function.
By binding an argument, b i n d 1 s t () and b i n d 2 n d () perform a service very similar to what is
commonly referred to as Currying.

===
In addition, we need a class and a m e m _ f u n () function for handling a member function taking an
argument. We also need versions to be called directly for an object rather than through a pointer;
these are named m e m _ f u n _ r e f (). Finally, we need versions for c o n s t member functions:

t e m p l a t e <c l a s s R , c l a s s T > m e m _ f u n _ t <R ,T > m e m _ f u n (R (T :: *f )());
/ / and versions for unary member, for const member, and const unary member (see table in §18.4.4)
t e m p l a t e <c l a s s R , c l a s s T > m e m _ f u n _ r e f _ t <R ,T > m e m _ f u n _ r e f (R (T :: *f )());
/ / and versions for unary member, for const member, and const unary member (see table in §18.4.4

===
Consequently, the standard library supplies two adapters to allow pointers to functions to be
used together with the standard algorithms in <f u n c t i o n a l >.

t e m p l a t e <c l a s s A , c l a s s R > p o i n t e r _ t o _ u n a r y _ f u n c t i o n <A ,R > p t r _ f u n (R (*f )(A ));

t e m p l a t e <c l a s s A , c l a s s A 2 , c l a s s R >
p o i n t e r _ t o _ b i n a r y _ f u n c t i o n <A ,A 2 ,R > p t r _ f u n (R (*f )(A , A 2 ));

===
If you want to accumulate information from
the elements, consider a c c u m u l a t e () (§22.6). If you want to find something in a sequence, consider
f i n d () and f i n d _ i f () (§18.5.2). If you change or remove elements, consider r e p l a c e ()
(§18.6.4) or r e m o v e () (§18.6.5). In general, before using f o r _ e a c h (), consider if there is a more
specialized algorithm that would do more for you.

===
The algorithms f i n d () and f i n d _ i f () return an iterator to the first element that matches a value and
a predicate, respectively. In fact, f i n d () can be understood as the version of f i n d _ i f () with the
predicate ==. Why aren’t they both called f i n d ()? The reason is that function overloading cannot
always distinguish calls of two template functions with the same number of arguments.

===
The f i n d _ f i r s t _ o f () algorithm finds the first element of a sequence that has a match in a second
sequence

The a d j a c e n t _ f i n d () algorithm finds a pair of adjacent matching values:

===
The c o u n t () and c o u n t _ i f () algorithms count occurrences of a value in a sequence:

===
The e q u a l () algorithm simply tells whether all corresponding pairs of elements of two sequences
compare equal; m i s m a t c h () looks for the first pair of elements that compares unequal and returns
iterators to those elements.

===
The s e a r c h () algorithm looks for its second sequence as a subsequence of its first. If that second
sequence is found, an iterator for the first matching element in the first sequence is returned. The
end of sequence (l a s t ) is returned to represent ‘‘not found.’’ Thus, the return value is always in the
[f i r s t ,l a s t ] sequence.

Thus, s e a r c h () is an operation for finding a substring generalized to all sequences.

The f i n d _ e n d () algorithm looks for its second input sequence as a subsequence of its first
input sequence. If that second sequence is found, f i n d _ e n d () returns an iterator pointing to the
last match in its first input. In other words, f i n d _ e n d () is s e a r c h () ‘‘backwards.’’ It finds the
last occurrence of its second input sequence in its first input sequence, rather than the first occurrence
of its second sequence.

The s e a r c h _ n () algorithm finds a sequence of at least n matches for its v a l u e argument in the
sequence. It returns an iterator to the first element of the sequence of n matches.

===
Copying is the simplest way to produce one sequence from another. The definitions of the basic
copy operations are trivial:

t e m p l a t e <c l a s s I n , c l a s s O u t > O u t c o p y (I n f i r s t , I n l a s t , O u t r e s )
{
w h i l e (f i r s t != l a s t ) *r e s ++ = *f i r s t ++;
r e t u r n r e s ;
}

t e m p l a t e <c l a s s B i , c l a s s B i 2 > B i 2 c o p y _ b a c k w a r d (B i f i r s t , B i l a s t , B i 2 r e s )
{
w h i l e (f i r s t != l a s t ) *r
e s = *l
a s t ;
r e t u r n r e s ;
}

The target of a copy algorithm need not be a container.
Anything that can be described by an output
iterator (§19.2.6) will do. For example:
v o i d f (l i s t <C l u b >& l c , o s t r e a m & o s )
{
c o p y (l c .b e g i n (), l c .e n d (), o s t r e a m _ i t e r a t o r <C l u b >(o s ));
}

===
Somewhat confusingly, t r a n s f o r m () doesn’t necessarily change its input. Instead, it produces an
output that is a transformation of its input based on a usersupplied
operation:

===
Whenever information is collected, duplication can occur. The u n i q u e () and u n i q u e _ c o p y ()
algorithms eliminate adjacent duplicate values:

The u n i q u e () algorithm eliminates adjacent duplicates from a sequence, u n i q u e _ c o p y () makes a
copy without duplicates. For example:
v o i d f (l i s t <s t r i n g >& l s , v e c t o r <s t r i n g >& v s )
{
l s .s o r t (); // list sort (§17.2.2.1)
u n i q u e _ c o p y (l s .b e g i n (), l s .e n d (), b a c k _ i n s e r t e r (v s ));
}
This copies l s to v s , eliminating duplicates in the process. The s o r t () is needed to get equal
strings adjacent.

Like other standard algorithms, u n i q u e () operates on iterators. It has no way of knowing the
type of container these iterators point into, so it cannot modify that container. It can only modify
the values of the elements. This implies that u n i q u e () does not eliminate duplicates from its input
sequence in the way we naively might expect. Rather, it moves unique elements towards the front
(head) of a sequence and returns an iterator to the end of the subsequence of unique elements:

The elements after the unique subsequence are left unchanged. Therefore, this does not eliminate
duplicates in a vector:
v o i d f (v e c t o r <s t r i n g >& v s ) // warning: bad code!
{
s o r t (v s .b e g i n (), v s .e n d ()); // sort vector
u n i q u e (v s .b e g i n (), v s .e n d ()); // eliminate duplicates (no it doesn’t!)
}

To eliminate duplicates from a container, we must explicitly shrink it:
t e m p l a t e <c l a s s C > v o i d e l i m i n a t e _ d u p l i c a t e s (C & c )
{
s o r t (c .b e g i n (), c .e n d ()); // sort
t y p e n a m e C :: i t e r a t o r p = u n i q u e (c .b e g i n (), c .e n d ()); // compact
c .e r a s e (p ,c .e n d ()); // shrink
}

To eliminate all duplicates, the input sequences must be sorted (§18.7.1). Both u n i q u e () and
u n i q u e _ c o p y () use == as the default criterion for comparison and allow the user to supply alternative
criteria.

===
The r e p l a c e () algorithms traverse a sequence, replacing values by other values as specified. They
follow the patterns outlined by f i n d /f i n d _ i f and u n i q u e /u n i q u e _ c o p y , thus yielding four variants
in all.

===
The r e m o v e () algorithms remove elements from a sequence based on a value or a predicate:

===
The f i l l () algorithm assigns a specified value; the g e n e r a t e () algorithm assigns values obtained
by calling its function argument repeatedly. Thus, f i l l () is simply the special case of g e n e r a t e ()
in which the generator function returns the same value repeatedly. The _ n versions assign to the
first n elements of the sequence.

The g e n e r a t e () and f i l l () functions assign rather than initialize. If you need to manipulate raw
storage, say to turn a region of memory into objects of welldefined
type and state, you must use an
algorithm like u n i n i t i a l i z e d _ f i l l () from <m e m o r y > (§19.4.4) rather than algorithms from <a l g o r
i t h m >.

===
The r e v e r s e () algorithm reverses the order of the elements so that the first element becomes the
last, etc. The r e v e r s e _ c o p y () algorithm produces a copy of its input in reverse order.
The r o t a t e () algorithm considers its [f i r s t ,l a s t [ sequence a circle and rotates its elements
until its former m i d d l e element is placed where its f i r s t element used to be.

By default, r a n d o m _ s h u f f l e () shuffles its sequence using a uniform distribution randomnumber
generator. That is, it chooses a permutation of the elements of the sequence in such a way
that each permutation has the same chance of being chosen. If you want a different distribution or
simply a better randomnumber
generator, you can supply one. For example, using the U r a n d generator
from §22.7 we might shuffle a deck of cards like this:

v o i d f (d e q u e <C a r d >& d c )
{
r a n d o m _ s h u f f l e (d c .b e g i n (), d c .e n d (), U r a n d (5 2 ));
/ / ...
}

===
To swap elements, you need a temporary. There are clever tricks to eliminate that need in specialized
cases, but they are best avoided in favor of the simple and obvious. The s w a p () algorithm is
specialized for important types for which it matters (§16.3.9, §13.5.2).
The i t e r _ s w a p () algorithm swaps the elements pointed to by its iterator arguments.
The s w a p _ r a n g e s algorithm swaps elements in its two input ranges.

===
If guaranteed worstcase
behavior is important or
a stable sort is required, s t a b l e _ s o r t () should be used; that is, an N *l o g (N )*l o g (N ) algorithm
that improves towards N *l o g (N ) when the system has sufficient extra memory. The relative order
of elements that compare equal is preserved by s t a b l e _ s o r t () but not by s o r t ().

The plain p a r t i a l _ s o r t () algorithms put the elements in the range f i r s t to m i d d l e in order. The
p a r t i a l _ s o r t _ c o p y () algorithms produce N elements, where N is the lower of the number of elements
in the output sequence and the number of elements in the input sequence. We need to specify
both the start and the end of the result sequence because that’s what determines how many elements
we need to sort.

===
A sequential search such as f i n d () (§18.5.2) is terribly inefficient for large sequences, but it is
about the best we can do without sorting or hashing (§17.6). Once a sequence is sorted, however,
we can use a binary search to determine whether a value is in a sequence:

A b i n a r y _ s e a r c h () returns a b o o l indicating whether a value was present. As with f i n d (), we
often also want to know where the elements with that value are in that sequence. However, there
can be many elements with a given value in a sequence, and we often need to find either the first or
all such elements. Consequently, algorithms are provided for finding a range of equal elements,
e q u a l _ r a n g e (), and algorithms for finding the l o w e r _ b o u n d ()and u p p e r _ b o u n d () of that range:

===
Given two sorted sequences, we can merge them into a new sorted sequence using m e r g e () or
merge two parts of a sequence using i n p l a c e _ m e r g e ():

The i n p l a c e _ m e r g e () algorithm is primarily useful when you have a sequence that can be
sorted by more than one criterion. For example, you might have a v e c t o r of fish sorted by species
(for example, cod, haddock, and herring). If the elements of each species are sorted by weight, you
can get the whole vector sorted by weight by applying i n p l a c e _ m e r g e () to merge the information
for the different species (§18.13[20]).

===
To partition a sequence is to place every element that satisfies a predicate before every element that
doesn’t. The standard library provides a s t a b l e _ p a r t i t i o n (), which maintains relative order
among the elements that do and do not satisfy the predicate. In addition, the library offers p a r t i t
i o n () which doesn’t maintain relative order, but which runs a bit faster when memory is limited:

===
The i n c l u d e s () algorithm tests whether every member of the first sequence is also a member of
the second:

===
The s e t _ d i f f e r e n c e () algorithm produces a sequence of elements that are members of its first, but
not its second, input sequence. The s e t _ s y m m e t r i c _ d i f f e r e n c e () algorithm produces a sequence
of elements that are members of either, but not of both, of its input sequences

===
When discussing algorithms, ‘‘heap’’
often refers to a way of organizing a sequence such that it has a first element that is the element
with the highest value. Addition of an element (using p u s h _ h e a p ()) and removal of an element
(using p o p _ h e a p ()) are reasonably fast, with a worstcase
performance of O (l o g (N )), where N
is the number of elements in the sequence. Sorting (using s o r t _ h e a p ()) has a worstcase
performance
of O (N *l o g (N )).

===
The m a x () and m i n () operations can be generalized to apply to sequences in the obvious manner:

t e m p l a t e <c l a s s F o r > F o r m a x _ e l e m e n t (F o r f i r s t , F o r l a s t );
t e m p l a t e <c l a s s F o r , c l a s s C m p > F o r m a x _ e l e m e n t (F o r f i r s t , F o r l a s t , C m p c m p );
t e m p l a t e <c l a s s F o r > F o r m i n _ e l e m e n t (F o r f i r s t , F o r l a s t );
t e m p l a t e <c l a s s F o r , c l a s s C m p > F o r m i n _ e l e m e n t (F o r f i r s t , F o r l a s t , C m p c m p );

===
Cstyle
strings and s t r i n g s are sequences, so l e x i c o g r a p h i c a l _ c o m p a r e () can be used as a
string compare function

===
The n e x t _ p e r m u t a t i o n () and p r e v _ p e r m u t a t i o n () functions deliver such permutations of a
sequence:

The permutations are produced in lexicographical order (§18.9). The return value of
n e x t _ p e r m u t a t i o n () indicates whether a next permutation actually exists. If not, f a l s e is returned
and the sequence is the permutation in which the elements are in lexicographical order

===
18.12 Advice [algo.advice]
[1] Prefer algorithms to loops; §18.5.1.
[2] When writing a loop, consider whether it could be expressed as a general algorithm; §18.2.
[3] Regularly review the set of algorithms to see if a new application has become obvious; §18.2.
[4] Be sure that a pair of iterator arguments really do specify a sequence; §18.3.1.
[5] Design so that the most frequentlyused
operations are simple and safe; §18.3, §18.3.1.
[6] Express tests in a form that allows them to be used as predicates; §18.4.2.
[7] Remember that predicates are functions and objects, not types; §18.4.2.
[8] You can use binders to make unary predicates out of binary predicates; §18.4.4.1.
[9] Use m e m _ f u n () and m e m _ f u n _ r e f () to apply algorithms on containers; §18.4.4.2.
[10] Use p t r _ f u n () when you need to bind an argument of a function; §18.4.4.3.
[11] Remember that s t r c m p () differs from == by returning 0 to indicate ‘‘equal;’’ §18.4.4.4.
[12] Use f o r _ e a c h () and t r a n s f o r m () only when there is no morespecific
algorithm for a task;
§18.5.1.
[13] Use predicates to apply algorithms using a variety of comparison and equality criteria;
§18.4.2.1, §18.6.3.1.
[14] Use predicates and other function objects so as to use standard algorithms with a wider range
of meanings; §18.4.2.
[15] The default == and < on pointers are rarely adequate for standard algorithms; §18.6.3.1.
[16] Algorithms do not directly add or subtract elements from their argument sequences; §18.6.
[17] Be sure that the lessthan
and equality predicates used on a sequence match; §18.6.3.1.
[18] Sometimes, sorted sequences can be used to increase efficiency and elegance; §18.7.
[19] Use q s o r t () and b s e a r c h () for compatibility only; §18.11.
*/
#include <iostream>
#include <vector>
#include <functional> // For The standard function objects
#include <algorithm>

class A
{
public:
  void
  print()
  {
    std::cout << "I am A \n";
  }
};

//template <typename T>
//void
//print_vec(const std::vector<T>& v) const
//{
//  for(typename std::vector<T>::const_iterator i=v.begin(); i!=v.end(); ++i)
//    std::cout << *i << " ";
//  std::cout << std::endl;
//}

void
print_vec(const std::vector<size_t>& v)
{
  for(std::vector<size_t>::const_iterator i=v.begin(); i!=v.end(); ++i)
    std::cout << *i << " ";
  std::cout << std::endl;
}

int
main()
{
  using namespace std;
  
  vector<size_t> v(5);
  v[0] = 0;
  v[1] = 1;
  v[2] = 2;
  v[3] = 3;
  v[4] = 4;
  
  vector<size_t>::iterator i;
  i = find(v.begin(),v.end(),3);
  cout << "*i= " << *i << endl;

//  // TODO do we have to define Iseq() ourself? 
//  vector<size_t>::iterator i2;
////  i2 = find( iseq(v),3 );
//  i2 = find( Iseq<size_t>(v.begin(),v.end()),2 )
//  cout << "*i2= " << *i2 << endl;
 
  //
  vector<size_t>::const_iterator ci;
  ci = find_if(v.begin(),v.end(),bind2nd(less<size_t>(),3));
  cout << "*ci= " << *ci << endl;
  
//  // TODO fix, this does not work
//  vector<size_t>::const_iterator ci2;
//  ci2 = find_if(  v.begin(),v.end(),not2( bind2nd(less<size_t>(),3))  );
//  cout << "*ci2= " << *ci2 << endl;
  
  //
  vector<A*> v2;
  v2.push_back(new A);
  v2.push_back(new A);
  
  for_each(v2.begin(),v2.end(),mem_fun(&A::print)); 
  
  //
  vector<size_t> vs(5,10);
  vector<size_t> vt(3,7);
  
//  copy(vs.begin(),vs.end(),vt.begin());
  copy(vs.begin(),vs.end(),back_inserter(vt));
  
  print_vec(vt);
   
  return 0;
}
