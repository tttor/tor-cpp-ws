/*
===
The t e m p l a t e <c l a s s C > prefix specifies that a template is being declared and that a type argument
C will be used in the declaration. After its introduction, C is used exactly like other type names.
The scope of C extends to the end of the declaration prefixed by t e m p l a t e <c l a s s C >. Note that
t e m p l a t e <c l a s s C > says that C is a type name; it need not be the name of a class.

===
It is usually a good idea to debug a particular class, such as S t r i n g , before turning it into a template
such as S t r i n g <C >.

===
When such a member is defined outside its class, it must explicitly be
declared a template. For example:

t e m p l a t e <c l a s s C > C S t r i n g <C >:: r e a d (i n t i ) c o n s t { r e t u r n r e p > s [i ]; }

t e m p l a t e <c l a s s C > S t r i n g <C >:: S t r i n g ()
{
p = n e w S r e p (0 ,C ());
}

===
It is not possible to overload a class template name, so if a class template is declared in a scope,
no other entity can be declared there with the same name (see also §13.5). For example:
t e m p l a t e <c l a s s T > c l a s s S t r i n g {  ...  };
c l a s s S t r i n g {  ...  }; // error: double definition

===
A template can take type parameters, parameters of ordinary types such as i n t s, and template
parameters (§C.13.3). Naturally, a template can take several parameters. For example:

t e m p l a t e <c l a s s T , T d e f _ v a l > c l a s s C o n t {  ...  };

A template argument can be a constant expression (§C.5), the address of an object or function
with external linkage (§9.2), or a nonoverloaded
pointer to member (§15.5). A pointer used as a
template argument must be of the form &o f , where o f is the name of an object or a function, or of
the form f , where f is the name of a function. A pointer to member must be of the form &X :: o f ,
where o f is the name of an member. In particular, a string literal is not acceptable as a template
argument.

An integer template argument must be a constant:

v o i d f (i n t i )
{
B u f f e r <i n t ,i > b x ; // error: constant expression expected
}

The compiler can evaluate constant expressions (§C.5), so B u f f e r <c h a r ,2 0 1
0 > is recognized
to be the same type as B u f f e r <c h a r ,1 0 >.

===
When a template function is called, the types of the function arguments determine which version of
the template is used; that is, the template arguments are deduced from the function arguments
(§13.3.1).

t e m p l a t e <c l a s s T > v o i d s o r t (v e c t o r <T >&); // declaration

v o i d f (v e c t o r <i n t >& v i , v e c t o r <s t r i n g >& v s )
{
s o r t (v i ); // sort(vector<int>&);
s o r t (v s ); // sort(vector<string>&);
}

Note that class template parameters are never deduced.

If a template argument cannot be deduced from the template function arguments (§C.13.4), we
must specify it explicitly. This is done in the same way template arguments are explicitly specified
for a template class. For example:
...
t e m p l a t e <c l a s s T > T * c r e a t e (); // make a T and return a pointer to it
...
i n t * p = c r e a t e <i n t >(); // function, template argument ‘int’

===
As with default function arguments (§7.5), only trailing arguments can be left out of a list of
explicit template arguments.

===
One can declare several function templates with the same name and even declare a combination of
function templates and ordinary functions with the same name.

===
we can supply the normal convention as a default template argument:

t e m p l a t e <c l a s s T , c l a s s C = C m p <T > >
i n t c o m p a r e (c o n s t S t r i n g <T >& s t r 1 , c o n s t S t r i n g <T >& s t r 2 )
{ }

===
The t e m p l a t e <> prefix says that this is a specialization that can be specified without a template
parameter. The template arguments for which the specialization is to be used are specified in <>
brackets after the name. That is, the <v o i d *> says that this definition is to be used as the implementation
of every V e c t o r for which T is void* .

t e m p l a t e <> c l a s s V e c t o r <v o i d *> {
v o i d ** p ;
/ / ...
v o i d *& o p e r a t o r [](i n t i );
};

The V e c t o r <v o i d *> is a complete specialization. That is, there is no template parameter to
specify or deduce when we use the specialization; V e c t o r <v o i d *> is used for V e c t o r s declared like
this:
V e c t o r <v o i d *> v p v ;

To define a specialization that is used for every V e c t o r of pointers and only for V e c t o r s of pointers,
we need a partial specialization:
t e m p l a t e <c l a s s T > c l a s s V e c t o r <T *> : p r i v a t e V e c t o r <v o i d *> {
p u b l i c :
t y p e d e f V e c t o r <v o i d *> B a s e ;
V e c t o r () : B a s e () {}
e x p l i c i t V e c t o r (i n t i ) : B a s e (i ) {}
T *& e l e m (i n t i ) { r e t u r n s t a t i c _ c a s t <T *&>(B a s e :: e l e m (i )); }
T *& o p e r a t o r [](i n t i ) { r e t u r n s t a t i c _ c a s t <T *&>(B a s e :: o p e r a t o r [](i )); }
/ / ...
};
The specialization pattern <T *> after the name says that this specialization is to be used for every
pointer type; that is, this definition is to be used for every V e c t o r with a template argument that can
be expressed as T *. For example:
V e c t o r <S h a p e *> v p s ; // <T*> is <Shape*> so T is Shape
V e c t o r <i n t **> v p p i ; // <T*> is <int**> so T is int*

Note that when a partial specialization is used, a template parameter is deduced from the specialization
pattern; the template parameter is not simply the actual template argument. In particular, for
V e c t o r <S h a p e *>, T is S h a p e and not S h a p e *.

===
t e m p l a t e <c l a s s T > c l a s s V e c t o r ; // general
t e m p l a t e <c l a s s T > c l a s s V e c t o r <T *>; // specialized for any pointer
t e m p l a t e <> c l a s s V e c t o r <v o i d *>; // specialized for void*

===
Specialization is useful when there
is a more efficient alternative to a general algorithm for a set of template arguments (here,
s w a p ()). In addition, specialization comes in handy when an irregularity of an argument type
causes the general algorithm to give an undesired result (here, l e s s ()). These ‘‘irregular types’’
are often the builtin
pointer and array types.

===
To distinguish them, what virtual functions provide is
called runtime
polymorphism, and what templates offer is called compiletime
polymorphism or
parametric polymorphism.

===
So when do we choose to use a template and when do we rely on an abstract class? In either
case, we manipulate objects that share a common set of operations. If no hierarchical relationship
is required between these objects, they are best used as template arguments. If the actual types of
these objects cannot be known at compiletime,
they are best represented as classes derived from a
common abstract class. If runtime
efficiency is at a premium, that is, if inlining of operations is
essential, a template should be used.

===
A class or a class template can have members that are themselves templates.
A member template cannot be v i r t u a l .

===
Consider:
t e m p l a t e <c l a s s T > c l a s s P t r { // pointer to T

T * p ;

p u b l i c :
P t r (T *);
t e m p l a t e <c l a s s T 2 > o p e r a t o r P t r <T 2 > (); // convert Ptr<T> to Ptr<T2>
/ / ...

};

We would like to define the conversion operators to provide the inheritance relationships we are
accustomed to for builtin
pointers for these userdefined
P t r s. For example:

v o i d f (P t r <C i r c l e > p c )
{
P t r <S h a p e > p s = p c ; // should work
P t r <C i r c l e > p c 2 = p s ; // should give error
}

We want to allow the first initialization if and only if S h a p e really is a direct or indirect public base
class of C i r c l e . In general, we need to define the conversion operator so that the P t r <T > to
P t r <T 2 > conversion is accepted if and only if a T * can be assigned to a T 2 *. That can be done
like this:
t e m p l a t e <c l a s s T >
t e m p l a t e <c l a s s T 2 >
P t r <T >:: o p e r a t o r P t r <T 2 > () { r e t u r n P t r <T 2 >(p ); }

===
There are two obvious ways of organizing code using templates:
[1] Include template definitions before their use in a translation unit.
[2] Include template declarations (only) before their use in a translation unit, and compile their
definitions separately.

===
The separate compilation strategy is the logical conclusion of this line of thinking: if the template
definition isn’t included in the user code, none of its dependencies can affect that code. Thus
we split the original o u t .c into two files:

/ / out.h:
t e m p l a t e <c l a s s T > v o i d o u t (c o n s t T & t );

/ / out.c:
#i n c l u d e <i o s t r e a m >
#i n c l u d e "o u t .h "
e x p o r t t e m p l a t e <c l a s s T > v o i d o u t (c o n s t T & t ) { s t d :: c e r r << t ; }
The file o u t .c now holds all of the information needed to define o u t (), and o u t .h holds only what
is needed to call it.

===
Note that to be accessible from other compilation units, a template definition must be explicitly
declared e x p o r t (§9.2.3). This can be done by adding e x p o r t to the definition or to a preceding
declaration. Otherwise, the definition must be in scope wherever the template is used.

===
13.8 Advice [temp.advice]
[1] Use templates to express algorithms that apply to many argument types; §13.3.
[2] Use templates to express containers; §13.2.
[3] Provide specializations for containers of pointers to minimize code size; §13.5.
[4] Always declare the general form of a template before specializations; §13.5.
[5] Declare a specialization before its use; §13.5.
[6] Minimize a template definition’s dependence on its instantiation contexts; §13.2.5, §C.13.8.
[7] Define every specialization you declare; §13.5.
[8] Consider if a template needs specializations for Cstyle
strings and arrays; §13.5.2.
[9] Parameterize with a policy object; §13.4.
[10] Use specialization and overloading to provide a single interface to implementations of the
same concept for different types; §13.5.
[11] Provide a simple interface for simple cases and use overloading and default arguments to
express less common cases; §13.5, §13.4.
[12] Debug concrete examples before generalizing to a template; §13.2.1.
[13] Remember to e x p o r t template definitions that need to be accessible from other translation
units; §13.7.
[14] Separately compile large templates and templates with nontrivial context dependencies; §13.7.
[15] Use templates to express conversions but define those conversions very carefully; §13.6.3.1.
[16] Where necessary, constrain template arguments using a c o n s t r a i n t () member function;
§13.9[16].
[17] Use explicit instantiation to minimize compile time and link time; §C.13.10.
[18] Prefer a template over derived classes when runtime
efficiency is at a premium; §13.6.1.
[19] Prefer derived classes over a template if adding new variants without recompilation is important;
§13.6.1.
[20] Prefer a template over derived classes when no common base can be defined; §13.6.1.
[21] Prefer a template over derived classes when builtin
types and structures with compatibility
constraints are important; §13.6.1.
*/
#include <iostream>
#include <vector>

template<typename T, int i>
class Buffer
{
  T v[i];
  int sz;
  
  public:
  Buffer()
  : sz(i)
  { } 
};

template<typename T>
void
print(const std::vector<T>& vec)
{
  for(size_t i=0; i<vec.size(); ++i)
    std::cout << vec[i] << " ";
  std::cout << std::endl;
}

int
main()
{
  Buffer<char,8> cbuf;
  
  std::vector<double>  vec(3);
  
  print(vec);
  print<double>(vec);// same as above, the specializaton can be deduced from the argument

  return 0;
}
