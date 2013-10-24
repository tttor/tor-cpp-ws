/*
===
The use of more than one immediate base class is usually called multiple inheritance. In contrast,
having just one direct base class is called single inheritance.

c l a s s S a t e l l i t e : p u b l i c T a s k , p u b l i c D i s p l a y e d {
/ / ...
};

In addition to whatever operations are defined specifically for a S a t e l l i t e , the union of operations
on T a s k s and D i s p l a y e d s can be applied. For example:
v o i d f (S a t e l l i t e & s )
{
s .d r a w (); // Displayed::draw()
s.delay(10) ; / / Task::delay()
s .t r a n s m i t (); // Satellite::transmit()
}
Similarly, a S a t e l l i t e can be passed to functions that expect a T a s k or a D i s p l a y e d . For example:
v o i d h i g h l i g h t (D i s p l a y e d *);
v o i d s u s p e n d (T a s k *);
v o i d g (S a t e l l i t e * p )
{
h i g h l i g h t (p ); // pass a pointer to the Displayed part of the Satellite
s u s p e n d (p ); // pass a pointer to the Task part of the Satellite
}

Virtual functions work as usual. For example:
c l a s s T a s k {
/ / ...
v i r t u a l v o i d p e n d i n g () = 0 ;
};
c l a s s D i s p l a y e d {
/ / ...
v i r t u a l v o i d d r a w () = 0 ;
};

c l a s s S a t e l l i t e : p u b l i c T a s k , p u b l i c D i s p l a y e d {
/ / ...
v o i d p e n d i n g (); // override Task::pending()
v o i d d r a w (); // override Displayed::draw()
};

===
c l a s s S a t e l l i t e : p u b l i c T a s k , p u b l i c D i s p l a y e d {
/ / ...
d e b u g _ i n f o * g e t _ d e b u g () // override Task::get_debug() and Displayed::get_debug()
{
d e b u g _ i n f o * d i p 1 = T a s k :: g e t _ d e b u g ();
d e b u g _ i n f o * d i p 2 = D i s p l a y e d :: g e t _ d e b u g ();
r e t u r n d i p 1 >
m e r g e (d i p 2 );
}
};
This localizes the information about S a t e l l i t e ’s base classes. Because S a t e l l i t e :: g e t _ d e b u g ()
overrides the g e t _ d e b u g () functions from both of its base classes, S a t e l l i t e :: g e t _ d e b u g () is
called wherever g e t _ d e b u g () is called for a S a t e l l i t e object.

===
Usingdeclarations
allow a programmer to compose a set of overloaded functions from base classes
and the derived class. Functions declared in the derived class hide functions that would otherwise
be available from a base. Virtual functions from bases can be overridden as ever (§15.2.3.1).

A usingdeclaration
(§8.2.2) in a class definition must refer to members of a base class. A
usingdeclaration
may not be used for a member of a class from outside that class, its derived
classes, and their member functions. A usingdirective
(§8.2.3) may not appear in a class definition
and may not be used for a class.

c l a s s A {
p u b l i c :
i n t f (i n t );
c h a r f (c h a r );
/ / ...
};
c l a s s B {
p u b l i c :
d o u b l e f (d o u b l e );
/ / ...
};
c l a s s A B : p u b l i c A , p u b l i c B {
p u b l i c :
u s i n g A :: f ;
u s i n g B :: f ;
c h a r f (c h a r ); // hides A::f(char)
A B f (A B );
};
v o i d g (A B & a b )
{
a b .f (1 ); // A::f(int)
ab.f(´a´) ; / / AB::f(char)
ab.f(2.0) ; / / B::f(double)
ab.f(ab) ; / / AB::f(AB)
}

===
virtual inheritance:

Every v i r t u a l base of a derived class is represented by the same (shared) object. For
example:

c l a s s T r a n s m i t t e r : p u b l i c v i r t u a l S t o r a b l e {
p u b l i c :
v o i d w r i t e ();
/ / ...
};

c l a s s R e c e i v e r : p u b l i c v i r t u a l S t o r a b l e {
p u b l i c :
v o i d w r i t e ();
/ / ...
};

c l a s s R a d i o : p u b l i c T r a n s m i t t e r , p u b l i c R e c e i v e r {
p u b l i c :
v o i d w r i t e ();
/ / ...
};

In an inheritance graph, every base class of a
given name that is specified to be virtual will be represented by a single object of that class. On the
other hand, each base class not specified v i r t u a l will have its own subobject
representing it.

===
A member of a class can be p r i v a t e , p r o t e c t e d , or p u b l i c :
– If it is p r i v a t e , its name can be used only by member functions and friends of the class in
which it is declared.
– If it is p r o t e c t e d , its name can be used only by member functions and friends of the class in
which it is declared and by member functions and friends of classes derived from this class
(see §11.5).
– If it is p u b l i c , its name can be used by any function

In a c l a s s , a member is by default private; in a s t r u c t , a member is by default public (§10.2.8).

===
Like a member, a base class can be declared p r i v a t e , p r o t e c t e d , or p u b l i c . For example:
c l a s s X : p u b l i c B { };
c l a s s Y : p r o t e c t e d B { };
c l a s s Z : p r i v a t e B { };

The access specifier for a base class controls the access to members of the base class and the
conversion of pointers and references from the derived class type to the base class type. Consider a
class D derived from a base class B :
– If B is a p r i v a t e base, its public and protected members can be used only by member functions
and friends of D . Only friends and members of D can convert a D * to a B *.
– If B is a p r o t e c t e d base, its public and protected members can be used only by member
functions and friends of D and by member functions and friends of classes derived from D .
Only friends and members of D and friends and members of classes derived from D can
convert a D * to a B *.
– If B is a p u b l i c base, its public members can be used by any function. In addition, its protected
members can be used by members and friends of D and members and friends of
classes derived from D . Any function can convert a D * to a B *.

The access specifier for a base class can be left out. In that case, the base defaults to a private
base for a c l a s s and a public base for a s t r u c t . For example:
c l a s s X X : B {  }; // B is a private base
s t r u c t Y Y : B {  }; // B is a public base

===
A using declaration
cannot be used to gain access to additional information. It is simply a mechanism
for making accessible information more convenient to use. On the other hand, once access is
available, it can be granted to other users. For example:
c l a s s B {
p r i v a t e :
i n t a ;
p r o t e c t e d :
i n t b ;
p u b l i c :
i n t c ;
};
c l a s s D : p u b l i c B {
p u b l i c :
u s i n g B :: a ; // error: B::a is private
u s i n g B :: b ; // make B::b publically available through D
};
When a usingdeclaration
is combined with private or protected derivation, it can be used to specify
interfaces to some, but not all, of the facilities usually offered by a class. For example:
c l a s s B B : p r i v a t e B { // give access to B::b and B::c, but not B::a
u s i n g B :: b ;
u s i n g B :: c ;
};

===
Recovering the ‘‘lost’’ type of an object requires us to somehow ask the object to reveal its
type. Any operation on an object requires us to have a pointer or reference of a suitable type for the
object. Consequently, the most obvious and useful operation for inspecting the type of an object at
run time is a type conversion operation that returns a valid pointer if the object is of the expected
type and a null pointer if it isn’t. The d y n a m i c _ c a s t operator does exactly that. For example,
assume that ‘‘the system’’ invokes m y _ e v e n t _ h a n d l e r () with a pointer to a B B w i n d o w , where an
activity has occurred. I then might invoke my application code using I v a l _ b o x ’s d o _ s o m e t h i n g ():

v o i d m y _ e v e n t _ h a n d l e r (B B w i n d o w * p w )
{
i f (I v a l _ b o x * p b = d y n a m i c _ c a s t <I v a l _ b o x *>(p w )) // does pw point to an Ival_box?
p b >
d o _ s o m e t h i n g ();
e l s e {
/ / Oops! unexpected event
}
}

===
Casting from a base class to a derived class is often called a downcast because of the convention
of drawing inheritance trees growing from the root down. Similarly, a cast from a derived class to
a base is called an upcast. A cast that goes from a base to a sibling class, like the cast from B B w i n d
o w to I v a l _ b o x , is called a crosscast.

The use of type information at run time is conventionally referred to as ‘‘runtime
type information’’
and often abbreviated to RTTI.

===
The d y n a m i c _ c a s t operator takes two operands, a type bracketed by < and >, and a pointer or reference
bracketed by ( and ).
Consider first the pointer case:
d y n a m i c _ c a s t <T *>(p )
If p is of type T * or an accessible base class of T , the result is exactly as if we had simply assigned
p to a T *.

The purpose of d y n a m i c _ c a s t is to deal with the case in which the correctness of the conversion
cannot be determined by the compiler. In that case,
d y n a m i c _ c a s t <T *>(p )
looks at the object pointed to by p (if any). If that object is of class T or has a unique base class of
type T , then d y n a m i c _ c a s t returns a pointer of type T * to that object; otherwise, 0 is returned. If
the value of p is 0 , d y n a m i c _ c a s t <T *>(p ) returns 0 . Note the requirement that the conversion
must be to a uniquely identified object. It is possible to construct examples where the conversion
fails and 0 is returned because the object pointed to by p has more than one subobject
representing
bases of type T (see §15.4.2).

For a pointer p , d y n a m i c _ c a s t <T *>(p ) can be seen as the question,
‘‘Is the object pointed to by p of type T ?’’

===
On the other hand, we may legitimately assume that a reference refers to an object. Consequently,
d y n a m i c _ c a s t <T &>(r ) of a reference r is not a question but an assertion: ‘‘The object
referred to by r is of type T .’’ The result of a d y n a m i c _ c a s t for a reference is implicitly tested by
the implementation of d y n a m i c _ c a s t itself. If the operand of a d y n a m i c _ c a s t to a reference isn’t of
the expected type, a b a d _ c a s t exception is thrown. For example:

v o i d f (I v a l _ b o x * p , I v a l _ b o x & r )
{
i f (I v a l _ s l i d e r * i s = d y n a m i c _ c a s t <I v a l _ s l i d e r *>(p )) { // does p point to an Ival_slider?
/ / use ‘is’
}
e l s e {
/ / *p not a slider
}
I v a l _ s l i d e r & i s = d y n a m i c _ c a s t <I v a l _ s l i d e r &>(r ); // r references an Ival_slider!
/ / use ‘is’
}

===
A d y n a m i c _ c a s t can cast from a polymorphic virtual base class to a derived class or a sibling class
(§15.4.1). A s t a t i c _ c a s t (§6.2.7) does not examine the object it casts from, so it cannot:

v o i d g (R a d i o & r )
{
R e c e i v e r * p r e c = &r ; // Receiver is ordinary base of Radio
R a d i o * p r = s t a t i c _ c a s t <R a d i o *>(p r e c ); // ok, unchecked
p r = d y n a m i c _ c a s t <R a d i o *>(p r e c ); // ok, runtime
checked
S t o r a b l e * p s = &r ; // Storable is virtual base of Radio
p r = s t a t i c _ c a s t <R a d i o *>(p s ); // error: cannot cast from virtual base
p r = d y n a m i c _ c a s t <R a d i o *>(p s ); // ok, runtime
checked
}

===
Why would anyone want to use a s t a t i c _ c a s t for class hierarchy navigation? There is a small
runtime
cost associated with the use of a d y n a m i c _ c a s t (§15.4.1). More significantly, there are
millions of lines of code that were written before d y n a m i c _ c a s t became available. This code relies
on alternative ways of making sure that a cast is valid, so the checking done by d y n a m i c _ c a s t is
seen as redundant. However, such code is typically written using the Cstyle
cast (§6.2.7); often
obscure errors remain. Where possible, use the safer d y n a m i c _ c a s t .

===
The compiler cannot assume anything about the memory pointed to by a v o i d *. This implies
that d y n a m i c _ c a s t – which must look into an object to determine its type – cannot cast from a
v o i d *. For that, a s t a t i c _ c a s t is needed. For example:

R a d i o * f (v o i d * p )
{
S t o r a b l e * p s = s t a t i c _ c a s t <S t o r a b l e *>(p ); // trust the programmer
r e t u r n d y n a m i c _ c a s t <R a d i o *>(p s );
}

===
Both d y n a m i c _ c a s t and s t a t i c _ c a s t respect c o n s t and access controls. For example:

c l a s s U s e r s : p r i v a t e s e t <P e r s o n > { };

v o i d f (U s e r s * p u , c o n s t R e c e i v e r * p c r )
{
s t a t i c _ c a s t <s e t <P e r s o n >*>(p u ); // error: access violation
d y n a m i c _ c a s t <s e t <P e r s o n >*>(p u ); // error: access violation
s t a t i c _ c a s t <R e c e i v e r *>(p c r ); // error: can’t cast away const
d y n a m i c _ c a s t <R e c e i v e r *>(p c r ); // error: can’t cast away const
R e c e i v e r * p r = c o n s t _ c a s t <R e c e i v e r *>(p c r ); // ok
/ / ...
}

It is not possible to cast to a private base class, and ‘‘casting away c o n s t ’’ requires a c o n s t _ c a s t
(§6.2.7). Even then, using the result is safe only provided the object wasn’t originally declared
c o n s t (§10.2.7.1) .

===
A t y p e i d () is most
commonly used to find the type of an object referred to by a reference or a pointer:

v o i d f (S h a p e & r , S h a p e * p )
{
t y p e i d (r ); // type of object referred to by r
t y p e i d (*p ); // type of object pointed to by p
t y p e i d (p ); // type of pointer, that is, Shape* (uncommon, except as a mistake)
}

If the value of a pointer or a reference operand is 0 , t y p e i d () throws a b a d _ t y p e i d exception.

Another, much simpler, use has been to obtain the name of a class for diagnostic
output:

#i n c l u d e <t y p e i n f o >
v o i d g (C o m p o n e n t * p )
{
c o u t << t y p e i d (*p ).n a m e ();
}

The character representation of a class’ name is implementationdefined

The implementationindependent
part of t y p e _ i n f o looks like this:

c l a s s t y p e _ i n f o {
p u b l i c :
v i r t u a l ~t y p e _ i n f o (); // is polymorphic
b o o l o p e r a t o r ==(c o n s t t y p e _ i n f o &) c o n s t ; // can be compared
b o o l o p e r a t o r !=(c o n s t t y p e _ i n f o &) c o n s t ;
b o o l b e f o r e (c o n s t t y p e _ i n f o &) c o n s t ; // ordering
c o n s t c h a r * n a m e () c o n s t ; // name of type
p r i v a t e :
t y p e _ i n f o (c o n s t t y p e _ i n f o &); // prevent copying
t y p e _ i n f o & o p e r a t o r =(c o n s t t y p e _ i n f o &); // prevent copying
/ / ...
};

The b e f o r e () function allows t y p e _ i n f o s to be sorted. There is no relation between the relationships
defined by b e f o r e and inheritance relationships.
It is not guaranteed that there is only one t y p e _ i n f o object for each type in the system. In fact,
where dynamically linked libraries are used it can be hard for an implementation to avoid duplicate
t y p e _ i n f o objects. Consequently, we should use == on t y p e _ i n f o objects to test equality, rather
than == on pointers to such objects.

===
A pointer to member m can be used in combination with an object. The operators >*
and .*
allow the programmer to express such combinations. For example, p >*
m binds m to the object
pointed to by p , and o b j .*m binds m to the object o b j . The result can be used in accordance with
m ’s type. It is not possible to store the result of a >*
or a .* operation for later use.

Naturally, if we knew which member we wanted to call we would invoke it directly rather than
mess with pointers to members. Just like ordinary pointers to functions, pointers to member functions
are used when we need to refer to a function without having to know its name. However, a
pointer to member isn’t a pointer to a piece of memory the way a pointer to a variable or a pointer
to a function is. It is more like an offset into a structure or an index into an array. When a pointer
to member is combined with a pointer to an object of the right type, it yields something that identifies
a particular member of a particular object.

===
A static member isn’t associated with a particular object, so a pointer to a static member is simply
an ordinary pointer. For example:

c l a s s T a s k {
/ / ...
s t a t i c v o i d s c h e d u l e ();
};

v o i d (*p )() = &T a s k :: s c h e d u l e ; // ok

void (Task: :*pm)() = &Task: :schedule; / / error: ordinary pointer assigned
/ / to pointer to member

===
A derived class has at least the members that it inherits from its base classes. Often it has more.
This implies that we can safely assign a pointer to a member of a base class to a pointer to a member
of a derived class, but not the other way around. This property is often called contravariance.
For example:

c l a s s t e x t : p u b l i c S t d _ i n t e r f a c e {
p u b l i c :
v o i d s t a r t ();
v o i d s u s p e n d ();
/ / ...
v i r t u a l v o i d p r i n t ();
p r i v a t e :
v e c t o r s ;
};

v o i d (S t d _ i n t e r f a c e :: * p m i )() = &t e x t :: p r i n t ; // error

v o i d (t e x t :: *p m t )() = &S t d _ i n t e r f a c e :: s t a r t ; // ok

===
Member o p e r a t o r n e w ()s and o p e r a t o r d e l e t e ()s are implicitly s t a t i c members.
Consequently,
they don’t have a t h i s pointer and do not modify an object. They provide storage that a constructor
can initialize and a destructor can clean up.

v o i d * E m p l o y e e :: o p e r a t o r n e w (s i z e _ t s )
{
/ / allocate ‘s’ bytes of memory and return a pointer to it
}

v o i d E m p l o y e e :: o p e r a t o r d e l e t e (v o i d * p , s i z e _ t s )
{
/ / assume ‘p’ points to ‘s’ bytes of memory allocated by Employee::operator new()
/ / and free that memory for reuse
}

How does a compiler know how to supply the right size to o p e r a t o r d e l e t e ()? As long as the
type specified in the d e l e t e operation matches the actual type of the object, this is easy. However,
that is not always the case:
c l a s s M a n a g e r : p u b l i c E m p l o y e e {
i n t l e v e l ;
/ / ...
};
v o i d f ()
{
E m p l o y e e * p = n e w M a n a g e r ; // trouble (the exact type is lost)
d e l e t e p ;
}
In this case, the compiler will not get the size right. As when an array is deleted, the user must help.
This is done by adding a virtual destructor to the base class, E m p l o y e e :
c l a s s E m p l o y e e {
p u b l i c :
v o i d * o p e r a t o r n e w (s i z e _ t );
v o i d o p e r a t o r d e l e t e (v o i d *, s i z e _ t );
v i r t u a l ~E m p l o y e e ();
/ / ...
};
Even an empty destructor will do:
E m p l o y e e :: ~E m p l o y e e () { }

In principle, deallocation is then done from within the destructor (which knows the size). Furthermore,
the presence of a destructor in E m p l o y e e ensures that every class derived from it will be supplied
with a destructor (thus getting the size right), even if the derived class doesn’t have a userdefined
destructor. For example:

v o i d f ()
{
E m p l o y e e * p = n e w M a n a g e r ;
d e l e t e p ; // now fine (Employee is polymorphic)
}
Allocation is done by a (compilergenerated)
call:
E m p l o y e e :: o p e r a t o r n e w (s i z e o f (M a n a g e r ))
and deallocation by a (compilergenerated)
call:
E m p l o y e e :: o p e r a t o r d e l e t e (p ,s i z e o f (M a n a g e r ))

In other words, if you want to supply an allocator/deallocator pair that works correctly for derived
classes, you must either supply a virtual destructor in the base class or refrain from using the s i z e _ t
argument in the deallocator.

===
c l a s s E m p l o y e e {
p u b l i c :
v o i d * o p e r a t o r n e w [](s i z e _ t );
v o i d o p e r a t o r d e l e t e [](v o i d *, s i z e _ t );
/ / ...
};
v o i d f (i n t s )
{
E m p l o y e e * p = n e w E m p l o y e e [s ];
/ / ...
d e l e t e [] p ;
}
Here, the memory needed will be obtained by a call,
E m p l o y e e :: o p e r a t o r n e w [](s i z e o f (E m p l o y e e )*s +d e l t a )
where d e l t a is some minimal implementationdefined
overhead, and released by a call:
E m p l o y e e :: o p e r a t o r d e l e t e [](p ,s *s i z e o f (E m p l o y e e )+d e l t a )
The number of elements (s ) is ‘‘remembered’’ by the system.

===
To construct an object, a constructor needs the exact type of the object it is to create. Consequently,
a constructor cannot be virtual. Furthermore, a constructor is not quite an ordinary function.
In particular, it interacts with memory management routines in ways ordinary member functions
don’t. Consequently, you cannot have a pointer to a constructor.

c l a s s E x p r {
p u b l i c :
E x p r (); // default constructor
E x p r (c o n s t E x p r &); // copy constructor
v i r t u a l E x p r * n e w _ e x p r () { r e t u r n n e w E x p r (); }
v i r t u a l E x p r * c l o n e () { r e t u r n n e w E x p r (*t h i s ); }
/ / ...
};

Because functions such as n e w _ e x p r () and c l o n e () are virtual and they (indirectly) construct
objects, they are often called ‘‘virtual constructors’’ – by a strange misuse of the English language.
Each simply uses a constructor to create a suitable object.

===
15.7 Advice [hier.advice]
[1] Use ordinary multiple inheritance to express a union of features; §15.2, §15.2.5.
[2] Use multiple inheritance to separate implementation details from an interface; §15.2.5.
[3] Use a v i r t u a l base to represent something common to some, but not all, classes in a hierarchy;
§15.2.5.
[4] Avoid explicit type conversion (casts); §15.4.5.
[5] Use d y n a m i c _ c a s t where class hierarchy navigation is unavoidable; §15.4.1.
[6] Prefer d y n a m i c _ c a s t over t y p e i d ; §15.4.4.
[7] Prefer p r i v a t e to p r o t e c t e d ; §15.3.1.1.
[8] Don’t declare data members p r o t e c t e d ; §15.3.1.1.
[9] If a class defines o p e r a t o r d e l e t e (), it should have a virtual destructor; §15.6.
[10] Don’t call virtual functions during construction or destruction; §15.4.3.
[11] Use explicit qualification for resolution of member names sparingly and preferably use it in
overriding functions; §15.2.1
*/
#include <iostream>
#include <typeinfo>

class A
{

};

class Tor
{

};

class Std_interface
{
public:

virtual void suspend() = 0;
};

class C: public Std_interface
{
  public:
  void
  suspend()
  {
    std::cout << "Hi, inside suspend() \n";
  }

};

// see: http://stackoverflow.com/questions/4295432/typedef-function-pointer
typedef void (Std_interface::* Pstd_mem)();// pointer to member type

void
f(Std_interface* p)
{
  Pstd_mem s = &Std_interface::suspend;// compile equally as:  void (Std_interface::* s)();
  void (Std_interface::* s2)();
  
  p->suspend();// direct call
  (p->*s)(); // call through pointer to member
}


class Employee
{
public:
//void* operator new(size_t);
//void  operator delete(void*,size_t);
virtual ~Employee();
};

Employee::~Employee()
{
  std::cout << "inside Employee::~Employee() \n"; 
}

class Manager: public Employee
{

};

void
f2()
{
  Employee* p = new Manager;
  delete p;
}

int
main()
{
  using namespace std;
  
  A* a = new A;
  cout << typeid(*a).name() << endl;
  
  Tor* b = new Tor;
  cout << typeid(*b).name() << endl;
  
  C* c = new C;
  f(c);
  
  f2();
    
  return 0;
}
