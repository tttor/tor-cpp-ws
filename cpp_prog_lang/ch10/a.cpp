/*
===
The p u b l i c label separates the class body into two parts. The names in the first, private, part can be
used only by member functions. The second, public, part constitutes the public interface to objects
of the class. A s t r u c t is simply a c l a s s whose members are public by default (§10.2.8); member
functions can be defined and used exactly as before.

===
A variable that is part of a class, yet is not part of an object of that class, is called a
s t a t i c member. There is exactly one copy of a s t a t i c member instead of one copy per object, as for
ordinary nons
t a t i c members. Similarly, a function that needs access to members of a class, yet
doesn’t need to be invoked for a particular object, is called a s t a t i c member function.

A static member can be referred to like any
other member. In addition, a static member can be referred to without mentioning an object.
Instead, its name is qualified by the name of its class. For example:
v o i d f ()
{
D a t e :: s e t _ d e f a u l t (4 ,5 ,1 9 4 5 );
}

===
D a t e t o d a y = D a t e (2 3 ,6 ,1 9 8 3 );
D a t e x m a s (2 5 ,1 2 ,1 9 9 0 ); // abbreviated form

===
Each (nonstatic) member function knows what object it was invoked for and can explictly refer to
it.

For example:
D a t e & D a t e :: a d d _ y e a r (i n t n )
{
i f (d ==2 9 && m ==2 && !l e a p y e a r (y +n )) { // beware of February 29
d = 1 ;
m = 3 ;
}
y += n ;
r e t u r n *t h i s ;
}
The expression *t h i s refers to the object for which a member function is invoked.

In a nonstatic member function, the keyword t h i s is a pointer to the object for which the function
was invoked. In a nonc
o n s t member function of class X , the type of t h i s is X *c o n s t . The
c o n s t makes it clear that the user is not supposed to change the value of t h i s . In a c o n s t member
function of class X , the type of t h i s is c o n s t X *c o n s t to prevent modification of the object itself

For example,
the a d d _ y e a r function could equivalently, but tediously, have been defined like this:
D a t e & D a t e :: a d d _ y e a r (i n t n )
{
i f (t h i s >
d ==2 9 && t h i s >
m ==2 && !l e a p y e a r (t h i s >
y +n )) {
t h i s >
d = 1 ;
t h i s >
m = 3 ;
}
t h i s >
y += n ;
r e t u r n *t h i s ;
}

===
The storage specifier m u t a b l e specifies that a member should be stored in a way that allows updating
– even when it is a member of a c o n s t object. In other words, m u t a b l e means ‘‘can never be
c o n s t .’’

===
A default constructor is a
constructor that can be called without supplying an argument. Because of the default argument 1 5 ,
T a b l e :: T a b l e (s i z e _ t ) is a default constructor. If a user has declared a default constructor, that
one will be used; otherwise, the compiler will try to generate one if needed and if the user hasn’t
declared other constructors. A compilergenerated
default constructor implicitly calls the default
constructors for a class’ members of class type and bases

Because c o n s t s and references must be initialized (§5.5, §5.4), a class containing c o n s t or reference
members cannot be defaultconstructed
unless the programmer explicitly supplies a constructor
(§10.4.6.1). For example:
s t r u c t X {
c o n s t i n t a ;
c o n s t i n t & r ;
};
X x ; // error: no default constructor for X

===
If an object of a class can be constructed without supplying an explicit initializer, then arrays of that
class can be defined. For example:
T a b l e t b l [1 0 ];
This will create an array of 1 0 T a b l e s

===
As always, if you find Cstyle
arrays too cumbersome, use a class such as v e c t o r (§3.7.1, §16.3)
instead. For example:
v o i d g ()
{
v e c t o r <T a b l e >* p 1 = n e w v e c t o r <T a b l e >(1 0 );
T a b l e * p 2 = n e w T a b l e ;
d e l e t e p 1 ;
d e l e t e p 2 ;
}

===
10.5 Advice [class.advice]
[1] Represent concepts as classes; §10.1.
[2] Use public data (s t r u c t s) only when it really is just data and no invariant is meaningful for the
data members; §10.2.8.
[3] A concrete type is the simplest kind of class. Where applicable, prefer a concrete type over
more complicated classes and over plain data structures; §10.3.
[4] Make a function a member only if it needs direct access to the representation of a class;
§10.3.2.
[5] Use a namespace to make the association between a class and its helper functions explicit;
§10.3.2.
[6] Make a member function that doesn’t modify the value of its object a c o n s t member function;
§10.2.6.
[7] Make a function that needs access to the representation of a class but needn’t be called for a
specific object a s t a t i c member function; §10.2.4.
[8] Use a constructor to establish an invariant for a class; §10.3.1.
[9] If a constructor acquires a resource, its class needs a destructor to release the resource;
§10.4.1.
[10] If a class has a pointer member, it needs copy operations (copy constructor and copy assignment);
§10.4.4.1.
[11] If a class has a reference member, it probably needs copy operations (copy constructor and
copy assignment); §10.4.6.3.
[12] If a class needs a copy operation or a destructor, it probably needs a constructor, a destructor, a
copy assignment, and a copy constructor; §10.4.4.1.
[13] Check for selfassignment
in copy assignments; §10.4.4.1.
[14] When writing a copy constructor, be careful to copy every element that needs to be copied
(beware of default initializers); §10.4.4.1.
[15] When adding a new member to a class, always check to see if there are userdefined
constructors
that need to be updated to initialize the member; §10.4.6.3.
[16] Use enumerators when you need to define integer constants in class declarations; §10.4.6.1.
[17] Avoid order dependencies when constructing global and namespace objects; §10.4.9.
[18] Use firsttime
switches to minimize order dependencies; §10.4.9.
[19] Remember that temporary objects are destroyed at the end of the full expression in which they
are created; §10.4.10.
*/
