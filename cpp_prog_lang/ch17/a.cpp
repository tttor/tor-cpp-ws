/*
===
The standard library defines two kinds of containers: sequences and associative containers.

Except where otherwise stated, the member types and
functions mentioned for v e c t o r can also be used for any other container and produce the same
effect.

===
By default, a v e c t o r (§16.3) should be used; it will be implemented to perform well over a
wide range of uses.

===
A container can be viewed as a sequence either in the order defined by the container’s i t e r a t o r or in
reverse order. For an associative container, the order is based on the container’s comparison criterion
(by default <):

===
Associative containers require that their elements can be ordered. So do many operations that can
be applied to containers (for example s o r t ()). By default, the < operator is used to define the
order. If < is not suitable, the programmer must provide an alternative (§17.4.1.5, §18.4.2). The
ordering criterion must define a strict weak ordering. Informally, this means that both lessthan
and equality must be transitive. That is, for an ordering criterion c m p :
[1] c m p (x ,x ) is f a l s e .
[2] If c m p (x ,y ) and c m p (y ,z ), then c m p (x ,z ).
[3] Define e q u i v (x ,y ) to be !(c m p (x ,y )||c m p (y ,x )). If e q u i v (x ,y ) and e q u i v (y ,z ),
then e q u i v (x ,z ).

===
A l i s t is a sequence optimized for insertion and deletion of elements. Compared to v e c t o r (and
d e q u e ; §17.2.3), subscripting would be painfully slow, so subscripting is not provided for l i s t .
Consequently, l i s t provides bidirectional iterators (§19.2.1) rather than randomaccess
iterators.
This implies that a l i s t will typically be implemented using some form of a doublylinked
list (see
§17.8[16]).
A l i s t provides all of the member types and operations offered by v e c t o r (§16.3), with the
exceptions of subscripting, c a p a c i t y (), and r e s e r v e ():

t e m p l a t e <c l a s s T , c l a s s A = a l l o c a t o r <T > > c l a s s s t d :: l i s t {
p u b l i c :
/ / types and operations like vector’s, except [], at(), capacity(), and reserve()
/ / ...
};

===
Like s p l i c e (), m e r g e () refrains from copying elements. Instead, it removes elements from
the source list and splices them into the target list. After an x .m e r g e (y ), the y list is empty.

===
The first element of a container is called its f r o n t . For a l i s t , front operations are as efficient and
convenient as back operations (§16.3.5). When there is a choice, back operations should be preferred
over front operations. Code written using back operations can be used for a v e c t o r as well as
for a l i s t . So if there is a chance that the code written using a l i s t will ever evolve into a generic
algorithm applicable to a variety of containers, it is best to prefer the more widely available back
operations.

===
t e m p l a t e <c l a s s T , c l a s s A = a l l o c a t o r <T > > c l a s s l i s t {
p u b l i c :
/ / ...
v o i d r e m o v e (c o n s t T & v a l );
t e m p l a t e <c l a s s P r e d > v o i d r e m o v e _ i f (P r e d p );
v o i d u n i q u e (); // remove duplicates using ==
t e m p l a t e <c l a s s B i n P r e d > v o i d u n i q u e (B i n P r e d b ); // remove duplicates using b
v o i d r e v e r s e (); // reverse order of elements
};

===
A d e q u e (it rhymes with check) is a doubleended
queue. That is, a d e q u e is a sequence optimized
so that operations at both ends are about as efficient as for a l i s t , whereas subscripting approaches
the efficiency of a v e c t o r :

t e m p l a t e <c l a s s T , c l a s s A = a l l o c a t o r <T > > c l a s s s t d :: d e q u e {
/ / types and operations like vector (§16.3.3, §16.3.5, §16.3.6)
/ / plus front operations (§17.2.2.2) like list
};

Insertion and deletion of elements ‘‘in the middle’’ have v e c t o r like
(in)efficiencies rather than
l i s t like
efficiencies. Consequently, a d e q u e is used where additions and deletions take place ‘‘at
the ends.’’

===
The v e c t o r , l i s t , and d e q u e sequences cannot be built from each other without loss of efficiency.
On the other hand, s t a c k s and q u e u e s can be elegantly and efficiently implemented using those
three basic sequences. Therefore, s t a c k and q u e u e are defined not as separate containers, but as
adaptors of basic containers.

===
That is, a s t a c k is simply an interface to a container of the type passed to it as a template argument.
All s t a c k does is to eliminate the nonstack
operations on its container from the interface and give
b a c k (), p u s h _ b a c k (), and p o p _ b a c k () their conventional names: t o p (), p u s h (), and p o p ().

By default, a s t a c k makes a d e q u e to hold its elements, but any sequence that provides b a c k (),
p u s h _ b a c k (), and p o p _ b a c k () can be used.

For example:
s t a c k <c h a r > s 1 ; // uses a deque<char> to store elements of type char
s t a c k < i n t ,v e c t o r <i n t > > s 2 ; // uses a vector<int> to store elements of type int

===
Defined in <q u e u e >, a q u e u e is an interface to a container that allows the insertion of elements at
the b a c k () and the extraction of elements at the f r o n t ():

By default, a q u e u e makes a d e q u e to hold its elements, but any sequence that provides f r o n t (),
b a c k (), p u s h _ b a c k (), and p o p _ f r o n t () can be used. Because a v e c t o r does not provide
p o p _ f r o n t (), a v e c t o r cannot be used as the underlying container for a queue.

Messages would be put on the q u e u e using p u s h ().

===
A p r i o r i t y _ q u e u e is a queue in which each element is given a priority that controls the order in
which the elements get to be t o p ():

The declaration of p r i o r i t y _ q u e u e is found in <q u e u e >.

By default, the p r i o r i t y _ q u e u e simply compares elements using the < operator and p o p ()
returns the largest element:

We can supply a comparison criterion without affecting the type of a p r i o r i t y _ q u e u e by providing
a comparison object of the appropriate type as a constructor argument
For example, we
could sort strings in a caseinsensitive
manner by placing them in

p r i o r i t y _ q u e u e <s t r i n g ,N o c a s e > p q ; // use Nocase::operator()() for comparisons (§17.1.4.1)

using p q .p u s h () and then retrieving them using p q .t o p () and p q .p o p ()

By default, a p r i o r i t y _ q u e u e makes a v e c t o r to hold its elements, but any sequence that provides
f r o n t (), p u s h _ b a c k (), p o p _ b a c k (), and random iterators can be used. A p r i o r i t y _ q u e u e
is most likely implemented using a h e a p (§18.8).

===
Associative containers are a generalization of the notion of an associative array. The m a p is a
traditional associative array, where a single value is associated with each unique key. A m u l t i m a p
is an associative array that allows duplicate elements for a given key, and s e t and m u l t i s e t can be
seen as degenerate associative arrays in which no value is associated with a key.

===
A m a p is a sequence of (key,value) pairs that provides for fast retrieval based on the key. At most
one value is held for each key; in other words, each key in a m a p is unique. A m a p provides bidirectional
iterators (§19.2.1).

The m a p requires that a lessthan
operation exist for its key types (§17.1.4.1) and keeps its elements
sorted so that iteration over a m a p occurs in order. For elements for which there is no obvious
order or when there is no need to keep the container sorted, we might consider using a
h a s h _ m a p (§17.6).

Note that the v a l u e _ t y p e of a m a p is a (key,value) p a i r . The type of the mapped values is referred
to as the m a p p e d _ t y p e . Thus, a m a p is a sequence of p a i r <c o n s t K e y ,m a p p e d _ t y p e > elements.

===
Iteration over a m a p is simply an iteration over a sequence of p a i r <c o n s t K e y ,m a p p e d _ t y p e > elements.

We refer to the first element of any p a i r as f i r s t and the second as s e c o n d independently of
what types they actually are:

In a m a p , the key is the first element of the pair and the mapped value is the second.

===
A p a i r is by default initialized to the default values of its element types. In particular, this implies
that elements of builtin
types are initialized to 0 (§5.1.1) and s t r i n g s are initialized to the empty
string (§20.3.4). A type without a default constructor can be an element of a p a i r only provided the
pair is explicitly initialized.

===
Subscripting a m a p adds a default element when the key is not found. Therefore, there is no
version of o p e r a t o r []() for c o n s t m a p s. Furthermore, subscripting can be used only if the
m a p p e d _ t y p e (value type) has a default value. If the programmer simply wants to see if a key is
present, the f i n d () operation (§17.4.1.6) can be used to locate a k e y without modifying the m a p .

===
A m .f i n d (k ) operation simply yields an iterator to an element with the key k . If there is no such
element, the iterator returned is m .e n d (). For a container with unique keys, such as m a p and s e t ,
the resulting iterator will point to the unique element with the key k . For a container with nonunique
keys, such as m u l t i m a p and m u l t i s e t , the resulting iterator will point to the first element that
has that key.

===
Because [] always uses V (), you cannot use subscripting on a m a p with a value type that does
not have a default value.

===
A m u l t i m a p is like a m a p , except that it allows duplicate keys:

This implies that m u l t i m a p cannot support subscripting by key values in the way m a p does.

===
A s e t can be seen as a m a p (§17.4.1), where the values are irrelevant, so we keep track of only the
keys.

Note that s e t relies on a comparison operation (by default <) rather than equality (==). This
implies that equivalence of elements is defined by inequality (§17.1.4.1) and that iteration through
a s e t has a welldefined
order.
Like m a p , s e t provides ==, !=, <, >, <=, >=, and s w a p ().

===
A m u l t i s e t is a s e t that allows duplicate keys:

===
C++ supports the notion
of small sets of flags efficiently through bitwise operations on integers (§6.2.4). These operations
include & (and), | (or), ^ (exclusive or), << (shift left), and >> (shift right). Class b i t s e t <N > generalizes
this notion and offers greater convenience by providing operations on a set of N bits
indexed from 0 through N 1
, where N is known at compile time. For sets of bits that don’t fit into
a l o n g i n t , using a b i t s e t is much more convenient than using integers directly.

===
A b i t s e t <N > is an array of N bits. A b i t s e t differs from a v e c t o r <b o o l > (§16.3.11) by being of
fixed size, from s e t (§17.4.3) by having its bits indexed by integers rather than associatively by
value, and from both v e c t o r <b o o l > and s e t by providing operations to manipulate the bits.

It is not possible to address a single bit directly using a builtin
pointer (§5.1). Consequently,
b i t s e t provides a referencetobit
type.

The b i t s e t template is defined in namespace s t d and presented in <b i t s e t >.
For historical reasons, b i t s e t differs somewhat in style from other standard library classes. For
example, if an index (also known as a bit position) is out of range, an o u t _ o f _ r a n g e exception is
thrown. No iterators are provided. Bit positions are numbered right to left in the same way bits
often are in a word, so the value of b [i ] is p o w (i ,2 ). Thus, a bitset can be thought of as an N bit
binary number:

The default value of a bit is 0 . When an u n s i g n e d l o n g i n t argument is supplied, each bit in the
integer is used to initialize the corresponding bit in the bitset (if any). A b a s i c _ s t r i n g (Chapter 20)
argument does the same, except that the character ´0 ´ gives the bitvalue 0 , the character ´1 ´ gives
the bitvalue 1 , and other characters cause an i n v a l i d _ a r g u m e n t exception to be thrown. By default,
a complete string is used for initialization. However, in the style of a b a s i c _ s t r i n g constructor
(§20.3.4), a user can specify that only the range of characters from p o s to the end of the string or to
p o s +n are to be used. For example:
v o i d f ()
{
b i t s e t <1 0 > b 1 ; // all 0
b i t s e t <1 6 > b 2 = 0 x a a a a ; // 1010101010101010
bitset<32>b3 =0xaaaa; / / 00000000000000001010101010101010
bitset<10>b4("1010101010") ; / / 1010101010
bitset<10>b5("10110111011110",4) ; / / 0111011110
bitset<10>b6("10110111011110",2,8) ; / / 0011011101
b i t s e t <1 0 > b 7 ("n 0 g 0 0 d "); // invalid_argument thrown
b i t s e t <1 0 > b 8 = "n 0 g 0 0 d "; // error: no char* to bitset conversion
}

When bits are shifted, a logical (rather than cyclic) shift is used. That implies that some bits
‘‘fall off the end’’ and that some positions get the default value 0. Note that because s i z e _ t is an
unsigned type, it is not possible to shift by a negative number. It does, however, imply that b <<1
shifts by a very large positive value, thus leaving every bit of the b i t s e t b with the value 0 .

===
A hash function is a function that quickly maps a value to an index in such a way that two distinct
values rarely end up with the same index. Basically, a hash table is implemented by placing a
value at its index, unless another value is already placed there, and ‘‘nearby’’ if one is. Finding an
element placed at its index is fast, and finding one ‘‘nearby’’ is not slow, provided equality testing
is reasonably fast. Consequently, it is not uncommon for a h a s h _ m a p to provide five to ten times
faster lookup than a m a p for larger containers, where the speed of lookup matters most. On the
other hand, a h a s h _ m a p with an illchosen
hash function can be much slower than a m a p .

See: http://en.wikipedia.org/wiki/Hash_table

The most fundamental difference between a m a p and a h a s h _ m a p is that a m a p
requires a < for its element type, while a h a s h _ m a p requires an == and a hash function.

m a p <s t r i n g ,i n t > m 1 ; // compare strings using <
m a p <s t r i n g ,i n t ,N o c a s e > m 2 ; // compare strings using Nocase() (§17.1.4.1)
h a s h _ m a p <s t r i n g ,i n t > h m 1 ; // hash using Hash<string>() (§17.6.2.3), compare using ==
h a s h _ m a p <s t r i n g ,i n t ,h f c t > h m 2 ; // hash using hfct(), compare using ==
h a s h _ m a p <s t r i n g ,i n t ,h f c t ,e q l > h m 3 ; // hash using hfct(), compare using eql

A container using hashed lookup is implemented using one or more tables. In addition to holding
its elements, the container needs to keep track of which values have been associated with each
hashed value (‘‘index’’ in the prior explanation); this is done using a ‘‘hash table.’’ Most hash
table implementations seriously degrade in performance if that table gets ‘‘too full,’’ say 75% full.

The key to efficient hashing is the quality of the hash function. If a good hash function isn’t
available, a m a p can easily outperform a h a s h _ m a p . Hashing based on a Cstyle
string, a s t r i n g , or
an integer is usually very effective. However, it is worth remembering that the effectiveness of a
hash function critically depends on the actual values being hashed (§17.8[35]). A h a s h _ m a p must
be used where < is not defined or is unsuitable for the intended key. Conversely, a hash function
does not define an ordering the way < does, so a m a p must be used when it is important to keep the
elements sorted.

A good hash function takes a key and returns an integer so that different keys yield different integers
with high probability. Choosing a good hash function is an art.

===
17.7 Advice [cont.advice]
[1] By default, use v e c t o r when you need a container; §17.1.
[2] Know the cost (complexity, bigO
measure) of every operation you use frequently; §17.1.2.
[3] The interface, implementation, and representation of a container are distinct concepts. Don’t
confuse them; §17.1.3.
[4] You can sort and search according to a variety of criteria; §17.1.4.1.
[5] Do not use a Cstyle
string as a key unless you supply a suitable comparison criterion;
§17.1.4.1.
[6] You can define a comparison criteria so that equivalent, yet different, key values map to the
same key; §17.1.4.1.
[7] Prefer operations on the end of a sequence (b a c k operations)
when inserting and deleting elements;
§17.1.4.1.
[8] Use list when you need to do many insertions and deletions from the front or the middle of a
container; §17.2.2.
[9] Use m a p or m u l t i m a p when you primarily access elements by key; §17.4.1.
[10] Use the minimal set of operations to gain maximum flexibility; §17.1.1
[11] Prefer a m a p to a h a s h _ m a p if the elements need to be kept in order; §17.6.1.
[12] Prefer a h a s h _ m a p to a m a p when speed of lookup is essential; §17.6.1.
[13] Prefer a h a s h _ m a p to a m a p if no lessthan
operation can be defined for the elements; §17.6.1.
[14] Use f i n d () when you need to check if a key is in an associative container; §17.4.1.6.
[15] U s e e q u a l _ r a n g e () to find all elements of a given key in an associative container; §17.4.1.6.
[16] Use m u l t i m a p when several values need to be kept for a single key; §17.4.2.
[17] Use s e t or m u l t i s e t when the key itself is the only value you need to keep; §17.4.3.
*/
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>

//#include <hash_map>
#include <unordered_map>

using namespace std;

void
print_backward(vector<int>& v)
{
  stack< int,vector<int> > s(v);
  
  while(s.size())
  {
    cout << s.top() << ", ";
    s.pop();
  }
  cout << endl;
}

class MyCmp
{
public:
  bool operator() (const int& i1,const int& i2) const;
};

bool
MyCmp::operator() (const int& i1,const int& i2) const
{
  return i1 > i2;
}

int
main()
{
  using namespace std;
  
  vector<int> v(5,7);
  *(v.begin()) = 1;
  *(v.rbegin()) = 5;
  
  cout << "*(v.begin())= " << *(v.begin()) << endl;
  cout << "*(v.rbegin())= " << *(v.rbegin()) << endl;
  
  deque<int> d(3,7);
  d.push_front(1);

  cout << "d.size()= " << d.size() << endl;
  cout << "d[0]= " << d[0] << endl; 
  
  print_backward(v);
  
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  
  cout << "q.front()= " << q.front() << endl;
  q.pop();
  cout << "q.front()= " << q.front() << endl;
  
  //
  priority_queue<int> pq;
  pq.push(1);
  pq.push(2);
  pq.push(3);
  
  cout << "pq.top()= " << pq.top() << endl;
  
//  priority_queue<int,MyCmp> pq2;// CANNOT compile ! TODO fix me.
//  pq2.push(1);
//  pq2.push(2);
//  pq2.push(3);
//  
//  cout << "pq2.top()= " << pq2.top() << endl;
  
  // Map
  map<string,size_t> m;
  m["vektor"] = 12345;
  m["dewanto"] = 67890;
  
  for(map<string,size_t>::const_iterator i=m.begin(); i!=m.end(); ++i)
  {
    cout << i->first << " has " << i->second << endl;
  }
    
  cout << "m.size()= " << m.size() << endl;
  int n_tor = m["tor"];// BE AWARE: Subscripting a m a p adds a default element when the key is not found.
  cout << "m.size()= " << m.size() << endl;
  
  for(map<string,size_t>::const_iterator i=m.begin(); i!=m.end(); ++i)
  {
    cout << i->first << " has " << i->second << endl;
  }
  
  map<size_t,size_t,MyCmp> m2;
  m2[1] = 2;
  m2[3] = 4;
  m2[5] = 6;
 
  for(map<size_t,size_t,MyCmp>::const_iterator i=m2.begin(); i!=m2.end(); ++i)
  {
    cout << i->first << " has " << i->second << endl;
  }
  cout << "-----------------------------" << endl;
  
  map<size_t,size_t> m3;
  m3[1] = 2;
  m3[3] = 4;
  m3[5] = 6;
  
  for(map<size_t,size_t,MyCmp>::const_iterator i=m3.begin(); i!=m3.end(); ++i)
  {
    cout << i->first << " has " << i->second << endl;
  }
  cout << "-----------------------------" << endl;
  
  map<size_t,size_t> m4(m3.key_comp());
//  map<size_t,size_t> m4(m3.value_comp());// TODO what does value_comp() do?
  m4[1] = 2;
  m4[3] = 4;
  m4[5] = 6;

  for(map<size_t,size_t,MyCmp>::const_iterator i=m4.begin(); i!=m4.end(); ++i)
  {
    cout << i->first << " has " << i->second << endl;
  }
  cout << "-----------------------------" << endl;

  return 0;
}
