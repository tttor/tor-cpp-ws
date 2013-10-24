/*
===
The facilities of the standard library are defined in the s t d namespace and presented as a set of
headers.

A standard header with a name starting with the letter c is equivalent to a header in the C standard
library. For every header <c X > defining names in the s t d namespace, there is a header <X .h >
defining the same names in the global namespace (see §9.2.2).

===
A container is an object that holds other objects. Examples are lists, vectors, and associative arrays.
In general, you can add objects to a container and remove objects from it.

===
t e m p l a t e <c l a s s T , c l a s s A = a l l o c a t o r <T > > c l a s s v e c t o r {
p u b l i c :
/ / ...
/ / iterators:
i t e r a t o r b e g i n (); // points to first element
c o n s t _ i t e r a t o r b e g i n () c o n s t ;
i t e r a t o r e n d (); // points to onepastlast
element
c o n s t _ i t e r a t o r e n d () c o n s t ;
r e v e r s e _ i t e r a t o r r b e g i n (); // points to first element of reverse sequence
c o n s t _ r e v e r s e _ i t e r a t o r r b e g i n () c o n s t ;
r e v e r s e _ i t e r a t o r r e n d (); // points to onepastlast
element of reverse sequence
c o n s t _ r e v e r s e _ i t e r a t o r r e n d () c o n s t ;
/ / ...
};

===
Indexing is done by o p e r a t o r []() and a t (); o p e r a t o r []() provides unchecked access, whereas
a t () does a range check and throws o u t _ o f _ r a n g e if an index is out of range.

That is, if the range has already been checked, the unchecked subscripting
operator can be used safely; otherwise, it is wise to use the rangechecked
a t () function.

The access operations return values of type r e f e r e n c e or c o n s t _ r e f e r e n c e depending on
whether or not they are applied to a c o n s t object.

===
Of the standard sequences, only v e c t o r and d e q u e (§17.2.3) support subscripting.

===
Note that f r o n t ()
returns a reference to the element to which b e g i n () returns an iterator. I often think of f r o n t () as
the first element and b e g i n () as a pointer to the first element. The correspondence between
b a c k () and e n d () is less simple: b a c k () is the last element and e n d () points to the lastplusone
element position.

===
A v e c t o r provides fast access to arbitrary elements, but changing its size is relatively expensive.
Consequently, we typically give an initial size when we create a v e c t o r .

Note that the default constructor for a builtin
type performs initialization to
0 of the appropriate type (§4.9.5, §10.4.2).

If a type does not have a default constructor, it is not possible to create a vector with elements
of that type without explicitly providing the value of each element. For example:

c l a s s N u m { // infinite precision
p u b l i c :
N u m (l o n g );
/ / no default constructor
/ / ...
};
v e c t o r <N u m > v 1 (1 0 0 0 ); // error: no default Num
v e c t o r <N u m > v 2 (1 0 0 0 ,N u m (0 )); // ok

===
For a
v e c t o r with many elements, that can be an expensive operation, so v e c t o r s are typically passed by
reference.

===
The a s s i g n functions exist to provide counterparts to the multiargument
constructors. They are
needed because = takes a single righthand
operand, so a s s i g n () is used where a default argument
value or a range of values is needed. For example:
c l a s s B o o k {
/ / ...
};
v o i d f (v e c t o r <N u m >& v n , v e c t o r <c h a r >& v c , v e c t o r <B o o k >& v b , l i s t <B o o k >& l b )
{
v n .a s s i g n (1 0 ,N u m (0 )); // assign vector of 10 copies of Num(0) to vn
c h a r s [] = "l i t e r a l ";
v c .a s s i g n (s ,&s [s i z e o f (s )1
]); // assign "literal" to vc
v b .a s s i g n (l b .b e g i n (), l b .e n d ()); // assign list elements
/ / ...
}

v o i d f ()
{
v e c t o r <c h a r > v (1 0 ,´x ´); // v.size()==10, each element has the value ’x’
v .a s s i g n (5 ,´a ´); // v.size()==5, each element has the value ’a’
/ / ...
}

===
it becomes obvious that stack operations make sense for a v e c t o r :

t e m p l a t e <c l a s s T , c l a s s A = a l l o c a t o r <T > > c l a s s v e c t o r {
p u b l i c :
/ / ...
/ / stack operations:
v o i d p u s h _ b a c k (c o n s t T & x ); // add to end
v o i d p o p _ b a c k (); // remove last element
/ / ...
};

===
The s i z e () of a v e c t o r is implicitly increased by p u s h _ b a c k () so the v e c t o r cannot overflow
(as long as there is memory available to acquire; see §19.4.1). However, a v e c t o r can underflow:
v o i d f ()
{
v e c t o r <i n t > v ;
v .p o p _ b a c k (); // undefined effect: the state of v becomes undefined
v .p u s h _ b a c k (7 ); // undefined effect (the state of v is undefined), probably bad
}
The effect of underflow is undefined, but the obvious implementation of p o p _ b a c k () causes memory
not owned by the v e c t o r to be overwritten. Like overflow, underflow must be avoided.

===
When a v e c t o r is resized to accommodate more (or fewer) elements, all of its elements may be
moved to new locations. Consequently, it is a bad idea to keep pointers to elements in a v e c t o r that
might be resized; after r e s i z e (), such pointers could point to deallocated memory. Instead, we can
keep indices. Note that p u s h _ b a c k (), i n s e r t (), and e r a s e () implicitly resize a v e c t o r .

===
In addition to the elements held, an application may keep some space for potential expansion.
A programmer who knows that expansion is likely can tell the v e c t o r implementation to r e s e r v e ()
space for future expansion.

A call v .r e s e r v e (n ) ensures that no allocation will be needed when the size of v is increased until
v .s i z e () exceeds n .

Reserving space in advance has two advantages. First, even a simpleminded
implementation
can then allocate sufficient space in one operation rather than slowly acquiring enough memory
along the way. However, in many cases there is a logical advantage that outweighs the potential
efficiency gain. The elements of a container are potentially relocated when a v e c t o r grows. Thus,
the links built between the elements of v in the previous example are guaranteed only because the
call of r e s e r v e () ensures that there are no allocations while the vector is being built. That is, in
some cases r e s e r v e () provides a guarantee of correctness in addition to whatever efficiency
advantages it gives.
That same guarantee can be used to ensure that potential memory exhaustion and potentially
expensive reallocation of elements take place at predictable times. For programs with stringent
realtime
constraints, this can be of great importance.
Note that r e s e r v e () doesn’t change the size of a v e c t o r . Thus, it does not have to initialize any
new elements. In both respects, it differs from r e s i z e ().

===
In the same way as s i z e () gives the current number of elements, c a p a c i t y () gives the current
number of reserved memory slots; c .c a p a c i t y ()c
.s i z e () is the number of elements that can be
inserted without causing reallocation.

Decreasing the size of a v e c t o r doesn’t decrease its capacity. It simply leaves room for the
v e c t o r to grow into later. If you want to give memory back to the system, assign a new value to the
v e c t o r . For example:
v = v e c t o r <i n t >(4 ,9 9 );

A v e c t o r gets the memory it needs for its elements by calling member functions of its allocator
(supplied as a template parameter). The default allocator, called a l l o c a t o r (§19.4.1), uses n e w to
obtain storage so that it will throw b a d _ a l l o c if no more storage is obtainable. Other allocators can
use different strategies (see §19.4.2).

===
Two v e c t o r s can be compared using == and <:

Two v e c t o r s v 1 and v 2 compare equal if v 1 .s i z e ()==v 2 .s i z e () and v 1 [n ]==v 2 [n ] for every
valid index n . Similarly, < is a lexicographical ordering. In other words, < for v e c t o r s could be
defined like this:

t e m p l a t e <c l a s s T , c l a s s A >
i n l i n e b o o l s t d :: o p e r a t o r <(c o n s t v e c t o r <T ,A >& x , c o n s t v e c t o r <T ,A >& y )
{
r e t u r n l e x i c o g r a p h i c a l _ c o m p a r e (x .b e g i n (), x .e n d (), y .b e g i n (), y .e n d ()); // see §18.9
}

This means that x is less than y if the first element x [i ] that is not equal to the corresponding element
y [i ] is less than y [i ], or x .s i z e ()<y .s i z e () with every x [i ] equal to its corresponding
y [i ].

===
Since a pointer cannot
address a unit of memory smaller than a byte, v e c t o r <b o o l >:: i t e r a t o r cannot be a pointer. In particular,
one cannot rely on b o o l * as an iterator for a v e c t o r <b o o l >:
v o i d f (v e c t o r <b o o l >& v )
{
b o o l * p = v .b e g i n (); // error: type mismatch {I think this will be mismatched all the time, even if it is not a bool, why did they give this example?}
/ / ...
}

===
16.4 Advice [org.advice]
[1] Use standard library facilities to maintain portability; §16.1.
[2] Don’t try to redefine standard library facilities; §16.1.2.
[3] Don’t believe that the standard library is best for everything.
[4] When building a new facility, consider whether it can be presented within the framework
offered by the standard library; §16.3.
[5] Remember that standard library facilities are defined in namespace s t d ; §16.1.2.
[6] Declare standard library facilities by including its header, not by explicit declaration; §16.1.2.
[7] Take advantage of late abstraction; §16.2.1.
[8] Avoid fat interfaces; §16.2.2.
[9] Prefer algorithms with reverse iterators over explicit loops dealing with reverse order; §16.3.2.
[10] Use b a s e () to extract an i t e r a t o r from a r e v e r s e _ i t e r a t o r ; §16.3.2.
[11] Pass containers by reference; §16.3.4.
[12] Use iterator types, such as l i s t <c h a r >:: i t e r a t o r , rather than pointers to refer to elements of a
container; §16.3.1.
[13] Use c o n s t iterators where you don’t need to modify the elements of a container; §16.3.1.
[14] Use a t (), directly or indirectly, if you want range checking; §16.3.3.
[15] Use p u s h _ b a c k () or r e s i z e () on a container rather than r e a l l o c () on an array; §16.3.5.
[16] Don’t use iterators into a resized v e c t o r ; §16.3.8.
[17] Use r e s e r v e () to avoid invalidating iterators; §16.3.8.
[18] When necessary, use r e s e r v e () to make performance predictable; §16.3.8.
*/
#include <iostream>
#include <vector>

int
main()
{
  using namespace std;
  
  int i = 1;
  int& ri = i;
  int* pt = &i;
  
  cout << "&i= " << &i << endl;
  cout << "&ri= " << &ri << endl;
  cout << "&pt= " << &pt << endl;
  cout << "pt= " << pt << endl;
  
  vector<int> vi(1);
  cout << "vi.size()= " << vi.size() << endl; 
  
  vi.assign(10,7); 
  cout << "vi.size()= " << vi.size() << endl; 
  
  vi.pop_back();// Decreasing the size of a v e c t o r doesn’t decrease its capacity. 
  cout << "vi.size()= " << vi.size() << endl; 
  
  cout << "vi.max_size()= " << vi.max_size() << endl;
  cout << "vi.capacity()= " << vi.capacity() << endl;
  
  vi = vector<int>(4,7);// DOES NOT give memory back to the system, why?
  cout << "vi.size()= " << vi.size() << endl;
  cout << "vi.capacity()= " << vi.capacity() << endl;
  
  vector<int> vi2(2);
  cout << "vi2.capacity()= " << vi2.capacity() << endl;
  
  vi = vi2;
  cout << "vi.size()= " << vi.size() << endl;
  cout << "vi.capacity()= " << vi.capacity() << endl;
  
  bool b = true;
  bool* pb = &b;// It is said that  a pointer cannot address a unit of memory smaller than a byte, BUT this works so b is not a bit, isn't it?
  cout << "&pb= " << &pb << endl;
  cout << "pb= " << pb << endl;
  
  return 0;
}
