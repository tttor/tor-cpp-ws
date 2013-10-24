/*
===
The following operators cannot be defined by a user:
:: (scope resolution; §4.9.4, §10.2.4),
. (member selection; §5.7), and
.* (member selection through pointer to function; §15.5).

===
It is not possible to define new operator tokens, but you can use the functioncall
notation when
this set of operators is not adequate. For example, use p o w (), not **.

===
The name of an operator function is the keyword o p e r a t o r followed by the operator itself; for
example, o p e r a t o r <<. An operator function is declared and can be called like any other function.
A use of the operator is only a shorthand for an explicit call of the operator function. For example:
v o i d f (c o m p l e x a , c o m p l e x b )
{
c o m p l e x c = a + b ; // shorthand
c o m p l e x d = a .o p e r a t o r +(b ); // explicit call
}

===
Because of historical accident, the operators = (assignment), & (addressof),
and , (sequencing;
§6.2.2) have predefined meanings when applied to class objects. These predefined meanings can
be made inaccessible to general users by making them private:

===
An operator is either a member of a class or defined in some namespace (possibly the global namespace).

===
A member
function X :: o p e r a t o r T (), where T is a type name, defines a conversion from X to T .

Note that the type being converted to is part of the name of the
operator and cannot be repeated as the return value of the conversion function:
T i n y :: o p e r a t o r i n t () c o n s t { r e t u r n v ; } // right
i n t T i n y :: o p e r a t o r i n t () c o n s t { r e t u r n v ; } // error
In this respect also, a conversion operator resembles a constructor.

Using a constructor to specify type conversion is convenient but has implications that can be undesirable.
A constructor cannot specify
[1] an implicit conversion from a userdefined
type to a basic type (because the basic types are
not classes), or
[2] a conversion from a new class to a previously defined class (without modifying the declaration
for the old class).

===
An assignment of a value of type V to an object of class X is legal if there is an assignment operator
X :: o p e r a t o r =(Z ) so that V is Z or there is a unique conversion of V to Z . Initialization is treated
equivalently.

===
Once the types of both sides of an initialization or assignment have been determined, both types
are used to resolve the initialization or assignment. For example:

c l a s s R e a l {
p u b l i c :
o p e r a t o r d o u b l e ();
o p e r a t o r i n t ();
/ / ...
};
v o i d g (R e a l a )
{
d o u b l e d = a ; // d = a.double();
i n t i = a ; // i = a.int();
d = a ; // d = a.double();
i = a ; // i = a.int();
}

===
An ordinary member function declaration specifies three logically distinct things:
[1] The function can access the private part of the class declaration, and
[2] the function is in the scope of the class, and
[3] the function must be invoked on an object (has a t h i s pointer).
By declaring a member function s t a t i c (§10.2.4), we can give it the first two properties only. By
declaring a function a f r i e n d , we can give it the first property only.

===
A f r i e n d declaration can be placed in either the private or the public part of a class declaration; it
does not matter where. Like a member function, a friend function is explicitly declared in the
declaration of the class of which it is a friend.

we declare the o p e r a t o r * a friend of both:

c l a s s M a t r i x ;// Declare the class Matrix here!

c l a s s V e c t o r {
f l o a t v [4 ];
/ / ...
f r i e n d V e c t o r o p e r a t o r *(c o n s t M a t r i x &, c o n s t V e c t o r &);
};

c l a s s M a t r i x {
V e c t o r v [4 ];
/ / ...
f r i e n d V e c t o r o p e r a t o r *(c o n s t M a t r i x &, c o n s t V e c t o r &);
};

V e c t o r o p e r a t o r *(c o n s t M a t r i x & m , c o n s t V e c t o r & v )
{
  ...
}

===
A member function of one class can be the friend of another. For example:

c l a s s L i s t _ i t e r a t o r {
/ / ...
i n t * n e x t ();
};

c l a s s L i s t {
f r i e n d i n t * L i s t _ i t e r a t o r :: n e x t ();
/ / ...
};

It is not unusual for all functions of one class to be friends of another. There is a shorthand for this:

c l a s s L i s t {
f r i e n d c l a s s L i s t _ i t e r a t o r ;
/ / ...
};

This friend declaration makes all of L i s t _ i t e r a t o r ’s member functions friends of L i s t .

===
For a class X for which the assignment operator X :: o p e r a t o r =(c o n s t X &) and the copy constructor
X :: X (c o n s t X &) are not explicitly declared by the programmer, the missing operation or
operations will be generated by the compiler (§10.2.5).

===
By default, a single argument constructor also defines an implicit conversion. For some types, that
is ideal. For example:
c o m p l e x z = 2 ; // initialize z with complex(2)

Implicit conversion can be suppressed by declaring a constructor e x p l i c i t . That is, an e x p l i c i t
constructor will be invoked only explicitly. In particular, where a copy constructor is in principle
needed (§11.3.4), an e x p l i c i t constructor will not be implicitly invoked.

c l a s s S t r i n g {
/ / ...
e x p l i c i t S t r i n g (i n t n ); // preallocate n bytes
S t r i n g (c o n s t c h a r * p ); // initial value is the Cstyle
string p
};

S t r i n g s 1 = ´a ´; // error: no implicit char– >String conversion
S t r i n g s 2 (1 0 ); // ok: String with space for 10 characters
S t r i n g s 3 = S t r i n g (1 0 ); // ok: String with space for 10 characters
S t r i n g s 4 = "B r i a n "; // ok: s4 = String("Brian")

===
An o p e r a t o r [] function can be used to give subscripts a meaning for class objects. The second
argument (the subscript) of an o p e r a t o r [] function may be of any type.

===
The most obvious, and probably also the most important, use of the () operator is to provide
the usual function call syntax for objects that in some way behave like functions. An object that
acts like a function is often called a functionlike
object or simply a function object (§18.4).

===
Like other members, a member class (often called a nested class) can be declared in the class itself
and defined later:

c l a s s S t r i n g {

s t r u c t S r e p ; // representation
Srep *rep;

public:
c l a s s C r e f ; // reference to char
c l a s s R a n g e { }; // for exceptions
/ / ...

};

===
11.13 Advice [class.advice]
[1] Define operators primarily to mimic conventional usage; §11.1.
[2] For large operands, use c o n s t reference argument types; §11.6.
[3] For large results, consider optimizing the return; §11.6.
[4] Prefer the default copy operations if appropriate for a class; §11.3.4.
[5] Redefine or prohibit copying if the default is not appropriate for a type; §11.2.2.
[6] Prefer member functions over nonmembers for operations that need access to the representation;
§11.5.2.
[7] Prefer nonmember functions over members for operations that do not need access to the representation;
§11.5.2.
[8] Use namespaces to associate helper functions with ‘‘their’’ class; §11.2.4.
[9] Use nonmember functions for symmetric operators; §11.3.2.
[10] Use () for subscripting multidimensional arrays; §11.9.
[11] Make constructors that take a single ‘‘size argument’’ e x p l i c i t ; §11.7.1.
[12] For nonspecialized
uses, prefer the standard s t r i n g (Chapter 20) to the result of your own
exercises; §11.12.
[13] Be cautious about introducing implicit conversions; §11.4.
[14] Use member functions to express operators that require an lvalue as its lefthand
operand;
§11.3.5.
*/