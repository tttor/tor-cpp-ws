/*
===
s t r u c t M a n a g e r : p u b l i c E m p l o y e e {
s e t <E m p l o y e e *> g r o u p ;
s h o r t l e v e l ;
/ / ...
};

The M a n a g e r is derived from E m p l o y e e , and conversely, E m p l o y e e is a base class for M a n a g e r .
The class M a n a g e r has the members of class E m p l o y e e (n a m e , a g e , etc.) in addition to its own
members (g r o u p , l e v e l , etc.).

Derivation is often represented graphically by a pointer from the derived class to its base class
indicating that the derived class refers to its base (rather than the other way around):

===
Consequently,
a class must be defined in order to be used as a base (§5.7):

c l a s s E m p l o y e e ; // declaration only, no definition

c l a s s M a n a g e r : p u b l i c E m p l o y e e { // error: Employee not defined
/ / ...
};

===
A member of a derived class can use the public – and protected (see §15.3) – members of its base
class as if they were declared in the derived class itself.

However, a derived class cannot use a base class’ private names

Where it is acceptable, p r o t e c t e d – rather than p r i v a t e – members
can be used. A protected member is like a public member to a member of a derived class, yet it is
like a private member to other functions (see §15.3).

Typically, the cleanest solution is for the derived class to use only the public members of its
base class.

===
A derived class constructor can specify initializers for its own members and immediate bases only;
it cannot directly initialize members of a base.

E m p l o y e e :: E m p l o y e e (c o n s t s t r i n g & n , i n t d )
: f a m i l y _ n a m e (n ), d e p a r t m e n t (d ) // initialize members
{
/ / ...
}

M a n a g e r :: M a n a g e r (c o n s t s t r i n g & n , i n t d , i n t l v l )
: E m p l o y e e (n ,d ), // initialize base
l e v e l (l v l ) // initialize members
{
/ / ...
}

===
Class objects are constructed from the bottom up: first the base, then the members, and then the
derived class itself. They are destroyed in the opposite order: first the derived class itself, then the
members, and then the base. Members and bases are constructed in order of declaration in the class
and destroyed in the reverse order.

===
c l a s s E m p l o y e e {
/ / ...
E m p l o y e e & o p e r a t o r =(c o n s t E m p l o y e e &);
E m p l o y e e (c o n s t E m p l o y e e &);
};

v o i d f (c o n s t M a n a g e r & m )
{
E m p l o y e e e = m ; // construct e from Employee part of m
e = m ; // assign Employee part of m to e
}

Because the E m p l o y e e copy functions do not know anything about M a n a g e r s, only the E m p l o y e e
part of a M a n a g e r is copied. This is commonly referred to as slicing and can be a source of surprises
and errors

===
The keyword v i r t u a l indicates that p r i n t () can act as an interface to the p r i n t () function defined
in this class and the p r i n t () functions defined in classes derived from it. Where such p r i n t ()
functions are defined in derived classes, the compiler ensures that the right p r i n t () for the given
E m p l o y e e object is invoked in each case.

A virtual member function is sometimes called a method.

A virtual function can be used even if no class is derived from its class, and a derived class that
does not need its own version of a virtual function need not provide one.

===
A virtual function is ‘‘made pure’’ by the initializer = 0 :

c l a s s S h a p e { // abstract class
p u b l i c :
v i r t u a l v o i d r o t a t e (i n t ) = 0 ; // pure virtual function
v i r t u a l v o i d d r a w () = 0 ; // pure virtual function
v i r t u a l b o o l i s _ c l o s e d () = 0 ; // pure virtual function
/ / ...
};

A class with one or more pure virtual functions is an abstract class, and no objects of that abstract
class can be created:

S h a p e s ; // error: variable of abstract class Shape

===
A pure virtual function that is not defined in a derived class remains a pure virtual function, so the
derived class is also an abstract class.

===
12.6 Advice [derived.advice]
[1] Avoid type fields; §12.2.5.
[2] Use pointers and references to avoid slicing; §12.2.3.
[3] Use abstract classes to focus design on the provision of clean interfaces; §12.3.
[4] Use abstract classes to minimize interfaces; §12.4.2.
[5] Use abstract classes to keep implementation details out of interfaces; §12.4.2.
[6] Use virtual functions to allow new implementations to be added without affecting user code;
§12.4.1.
[7] Use abstract classes to minimize recompilation of user code; §12.4.2.
[8] Use abstract classes to allow alternative implementations to coexist; §12.4.3.
[9] A class with a virtual function should have a virtual destructor; §12.4.2.
[10] An abstract class typically doesn’t need a constructor; §12.4.2.
[11] Keep the representations of distinct concepts distinct; §12.4.1.1.
*/
#include <iostream>
#include <vector>
#include <set>

class Employee
{
  std::string first_name, family_name;
  short department;
  
  public:
  Employee(const std::string& n,int d);
  virtual void print() const;
};

class Manager: public Employee
{
  std::set<Employee*> group;
  short level;
  
  public:
  Manager(const std::string& n,int d,int lvl);
};

Employee::Employee(const std::string& n,int d)
: family_name(n),department(d)
{

}

Manager::Manager(const std::string& n,int d,int lvl)
: Employee(n,d),level(lvl)
{

}


int
main()
{
  Employee emp1("vektor",3);
  Manager mgr1("dewanto",1,1);
  
  std::vector<Employee> emps;
  emps.push_back(emp1);
  emps.push_back(mgr1);// M a n a g e r can be used wherever an E m p l o y e e is acceptable
  
}
