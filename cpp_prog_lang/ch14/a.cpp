/*
===
The notion of an exception is provided to help deal with such problems. The
fundamental idea is that a function that finds a problem it cannot cope with throws an exception,
hoping that its (direct or indirect) caller can handle the problem. A function that wants to handle
that kind of problem can indicate that it is willing to catch that exception (§2.4.2, §8.3).

===
Standard C++ doesn’t have the notion of a thread or a process.

===
For example, the exceptions for a mathematical
library might be organized like this:

Here, an O v e r f l o w is handled specifically. 

c l a s s M a t h e r r { };
c l a s s O v e r f l o w : p u b l i c M a t h e r r { };
c l a s s U n d e r f l o w : p u b l i c M a t h e r r { };
c l a s s Z e r o d i v i d e : p u b l i c M a t h e r r { };
/ / ...

This allows us to handle any M a t h e r r without caring precisely which kind it is. For example:

v o i d f ()
{
t r y {
/ / ...
}
c a t c h (O v e r f l o w ) {
/ / handle Overflow or anything derived from Overflow
}
c a t c h (M a t h e r r ) {
/ / handle any Matherr that is not Overflow
}
}

Please note that neither the builtin
mathematical operations nor the basic math library (shared
with C) reports arithmetic errors as exceptions. One reason for this is that detection of some arithmetic
errors, such as dividebyzero,
are asynchronous on many pipelined machine architectures.
The M a t h e r r hierarchy described here is only an illustration.

===
Not every grouping of exceptions is a tree structure. Often, an exception belongs to two groups.
For example:
c l a s s N e t f i l e _ e r r : p u b l i c N e t w o r k _ e r r , p u b l i c F i l e _ s y s t e m _ e r r {  ...  };

Such a N e t f i l e _ e r r can be caught by functions dealing with network exceptions:

v o i d f ()
{
t r y {
/ / something
}
c a t c h (N e t w o r k _ e r r & e ) {
/ / ...
}
}

and also by functions dealing with file system exceptions:

v o i d g ()
{
t r y {
/ / something else
}
c a t c h (F i l e _ s y s t e m _ e r r & e ) {
/ / ...
}
}

===
Consider:

v o i d f ()
{
  t r y {
  t h r o w E ();
  }
  c a t c h (H ) {
  / / when do we get here?
  }
}

The handler is invoked:
[1] If H is the same type as E .
[2] If H is an unambiguous public base of E .
[3] If H and E are pointer types and [1] or [2] holds for the types to which they refer.
[4] If H is a reference and [1] or [2] holds for the type to which H refers.

===
In principle, an exception is copied when it is thrown, so the handler gets hold of a copy of the
original exception. In fact, an exception may be copied several times before it is caught. Consequently,
we cannot throw an exception that cannot be copied.

===
A rethrow
is indicated by a t h r o w without an operand. If a rethrow
is attempted when there is no
exception to rethrow,
t e r m i n a t e () (§14.7) will be called. A compiler can detect and warn about
some, but not all, such cases.

The exception rethrown
is the original exception caught and not just the part of it that was
accessible as a M a t h e r r . In other words, had an I n t _ o v e r f l o w been thrown, a caller of h () could
still catch an I n t _ o v e r f l o w that h () had caught as a M a t h e r r and decided to rethrow.

===
As for functions, the
ellipsis ... indicates ‘‘any argument’’ (§7.6), so c a t c h (...) means ‘‘catch any exception.’’

===
Because a derived exception can be caught by handlers for more than one exception type, the order
in which the handlers are written in a t r y statement is significant. The handlers are tried in order.

===
The destructor will be called independently of whether the function is exited normally or exited
because an exception is thrown.

===
A constructor tries to ensure that its object is completely and correctly constructed. When that
cannot be achieved, a wellwritten
constructor restores – as far as possible – the state of the system
to what it was before creation. Ideally, naively written constructors always achieve one of these
alternatives and don’t leave their objects in some ‘‘halfconstructed’’
state. This can be achieved
by applying the ‘‘resource acquisition is initialization’’ technique to the members.

where this simple model for acquisition of resources is adhered to, the author
of the constructor need not write explicit exceptionhandling
code.

An object is not considered constructed until its constructor has completed. Then and only then
will stack unwinding call the destructor for the object. An object composed of subobjects
is constructed
to the extent that its subobjects
have been constructed. An array is constructed to the
extent that its elements have been constructed (and only fully constructed elements are destroyed
during unwinding).

===
The most common resource acquired in an adhoc
manner is memory. For example:

c l a s s Y {
i n t * p ;
v o i d i n i t ();
p u b l i c :
Y (i n t s ) { p = n e w i n t [s ]; i n i t (); }
~Y () { d e l e t e [] p ; }
/ / ...
};

This practice is common and can lead to ‘‘memory leaks.’’ If an exception is thrown by i n i t (),
then the store acquired will not be freed; the destructor will not be called because the object wasn’t
completely constructed. A safe variant is:

c l a s s Z {
v e c t o r <i n t > p ;
v o i d i n i t ();
p u b l i c :
Z (i n t s ) : p (s ) { i n i t (); }
/ / ...
};

The memory used by p is now managed by v e c t o r . If i n i t () throws an exception, the memory
acquired will be freed when the destructor for p is (implicitly) invoked.

===
The standard library provides the template class a u t o _ p t r , which supports the ‘‘resource acquisition
is initialization’’ technique. Basically, an a u t o _ p t r is initialized by a pointer and can be dereferenced
in the way that a pointer can. Also, the object pointed to will be implicitly deleted at the end
of the a u t o _ p t r ’s scope. For example:

v o i d f (P o i n t p 1 , P o i n t p 2 , a u t o _ p t r <C i r c l e > p c , S h a p e * p b ) // remember to delete pb on exit
{
a u t o _ p t r <S h a p e > p (n e w R e c t a n g l e (p 1 ,p 2 )); // p points to a rectangle
a u t o _ p t r <S h a p e > p b o x (p b );
p >
r o t a t e (4 5 ); // use auto_ptr<Shape> exactly as a Shape*
/ / ...
i f (i n _ a _ m e s s ) t h r o w M e s s ();
/ / ...
}

Here the R e c t a n g l e , the S h a p e pointed to by p b , and the C i r c l e pointed to by p c are deleted
whether or not an exception is thrown.

To achieve this ownership semantics (also called destructive copy semantics), a u t o _ p t r s have a
copy semantics that differs radically from that of ordinary pointers: When one a u t o _ p t r is copied
into another, the source no longer points to anything. Because copying an a u t o _ p t r modifies it, a
c o n s t a u t o _ p t r cannot be copied.

Note that a u t o _ p t r ’s destructive copy semantics means that it does not meet the requirements
for elements of a standard container or for standard algorithms such as s o r t (). For example:
v o i d h (v e c t o r < a u t o _ p t r <S h a p e *> >& v ) // dangerous: use of auto_ptr in container
{
s o r t (v .b e g i n (), v .e n d ()); // Don’t do this: The sort will probably mess up v
}
Clearly, a u t o _ p t r isn’t a general smart pointer. However, it provides the service for which it was
designed – exception safety for automatic pointers – with essentially no overhead.

===
What happens if a member initializer (directly or indirectly) throws an exception? By default, the
exception is passed on to whatever invoked the constructor for the member’s class. However, the
constructor itself can catch such exceptions by enclosing the complete function body – including
the member initializer list – in a tryblock.
For example:

c l a s s X {
V e c t o r v ;
/ / ...
p u b l i c :
X (i n t );
/ / ...
};
X :: X (i n t s )
t r y
:v(s) / / initialize v by s
{
/ / ...
}
c a t c h (V e c t o r :: S i z e ) { // exceptions thrown for v are caught here
/ / ...
}

===
From the point of view of exception handling, a destructor can be called in one of two ways:
[1] Normal call: As the result of a normal exit from a scope (§10.4.3), a d e l e t e (§10.4.5), etc.
[2] Call during exception handling: During stack unwinding (§14.4), the exceptionhandling
mechanism exits a scope containing an object with a destructor.
In the latter case, an exception may not escape from the destructor itself. If it does, it is considered
a failure of the exceptionhandling
mechanism and s t d :: t e r m i n a t e () (§14.7) is called.

If a destructor calls functions that may throw exceptions, it can protect itself. For example:

X: :~X()
try {
f() ; / / might throw
}
c a t c h (...) {
/ / do something
}

The standard library function u n c a u g h t _ e x c e p t i o n () returns t r u e if an exception has been thrown
but hasn’t yet been caught. This allows the programmer to specify different actions in a destructor
depending on whether an object is destroyed normally or as part of stack unwinding.

===
Alternatively, one might think of the
exceptionhandling
mechanisms as simply another control structure. For example:

v o i d f (Q u e u e <X >& q )
{
t r y {
f o r (;;) {
X m = q .g e t (); // throws ‘Empty’ if queue is empty
/ / ...
}
}
c a t c h (Q u e u e <X >:: E m p t y ) {
r e t u r n ;
}
}

Using exceptions as alternate returns can be an elegant technique for terminating search functions
– especially highly recursive search functions such as a lookup in a tree.

===
v o i d f (i n t a ) t h r o w (x 2 , x 3 );

This specifies that f () may throw only exceptions x 2 , x 3 , and exceptions derived from these types,
but no others.

===
In effect,

v o i d f () t h r o w (x 2 , x 3 )
{
/ / stuff
}

is equivalent to:

v o i d f ()
t r y
{
/ / stuff
}
catch (x2) {throw; } / / rethrow
catch (x3) {throw; } / / rethrow
catch (...) {
std: :unexpected() ; / / unexpected() will not return
}

===
A function declared without an exceptionspecification
is assumed to throw every exception.
For example:
i n t f (); // can throw any exception
A function that will throw no exceptions can be declared with an empty list:
i n t g () t h r o w (); // no exception thrown

===
If any declaration of a function has an exceptionspecification,
every declaration of that function
(including the definition) must have an exceptionspecification
with exactly the same set of exception
types. For example:

i n t f () t h r o w (s t d :: b a d _ a l l o c );

i n t f () // error: exceptionspecification
missing
{
/ / ...
}

===
A virtual function may be overridden only by a function that has an exceptionspecification
at
least as restrictive as its own (explicit or implicit) exceptionspecification.
For example:

c l a s s B {
p u b l i c :
v i r t u a l v o i d f (); // can throw anything
v i r t u a l v o i d g () t h r o w (X ,Y );
v i r t u a l v o i d h () t h r o w (X );
};

c l a s s D : p u b l i c B {
p u b l i c :
v o i d f () t h r o w (X ); // ok
v o i d g () t h r o w (X ); // ok: D::g() is more restrictive than B::g()
v o i d h () t h r o w (X ,Y ); // error: D::h() is less restrictive than B::h()
};

===
Similarly, you can assign a pointer to function that has a more restrictive exceptionspecification
to a pointer to function that has a less restrictive exceptionspecification,
but not vice
versa. For example:

v o i d f () t h r o w (X );
v o i d (*p f 1 )() t h r o w (X ,Y ) = &f ; // ok
void (*pf2)()throw() = &f; / / error: f() is less restrictive than pf2

In particular, you cannot assign a pointer to a function without an exceptionspecification
to a
pointer to function that has one:

v o i d g (); // might throw anything
v o i d (*p f 3 )() t h r o w (X ) = &g ; // error: g() less restrictive than pf3

An exceptionspecification
is not part of the type of a function and a t y p e d e f may not contain one.
For example:
t y p e d e f v o i d (*P F )() t h r o w (X ); // error

===
A welldefined
subsystem Y will often have all its exceptions derived from a class Y e r r . For
example, given

c l a s s S o m e _ Y e r r : p u b l i c Y e r r {  ...  };

a function declared
v o i d f () t h r o w (X e r r , Y e r r , e x c e p t i o n );

will pass any Y e r r on to its caller. In particular, f () would handle a S o m e _ Y e r r by passing it on to
its caller. Thus, no Y e r r in f () will trigger u n e x p e c t e d ().

All exceptions thrown by the standard library are derived from class e x c e p t i o n (§14.10).

===
The simplest way of achieving that is to add the standard library exception s t d :: b a d _ e x c e p t i o n
to an exceptionspecification.
In that case, u n e x p e c t e d () will simply throw b a d _ e x c e p t i o n instead
of invoking a function to try to cope. For example:

c l a s s X { };

c l a s s Y { };

v o i d f () t h r o w (X ,s t d :: b a d _ e x c e p t i o n )
{
/ / ...
t h r o w Y (); // throw ‘‘bad’’ exception
}

The exceptionspecification
will catch the unacceptable exception Y and throw an exception of type
b a d _ e x c e p t i o n instead.
There is actually nothing particularly bad about b a d _ e x c e p t i o n ; it simply provides a mechanism
that is less drastic than calling t e r m i n a t e (). However, it is still rather crude. In particular,
information about which exception caused the problem is lost.

===
Consider a function g () written for a nonnetworked
environment. Assume further that g () has
been declared with an exceptionspecification
so that it will throw only exceptions related to its
‘‘subsystem Y:’’

v o i d g () t h r o w (Y e r r );

Now assume that we need to call g () in a networked environment.
Naturally, g () will not know about network exceptions and will invoke u n e x p e c t e d () when it
encounters one. To use g () in a distributed environment, we must either provide code that handles
network exceptions or rewrite g (). Assuming a rewrite is infeasible or undesirable, we can handle
the problem by redefining the meaning of u n e x p e c t e d ().

===
If an exception is thrown but not caught, the function s t d :: t e r m i n a t e () will be called.

The t e r m i n
a t e () function will also be called when the exceptionhandling
mechanism finds the stack corrupted
and when a destructor called during stack unwinding caused by an exception tries to exit
using an exception.

By default, t e r m i n a t e () will call a b o r t () (§9.4.1.1).

Note that a b o r t () indicates abnormal exit from the program. The function e x i t () can be used
to exit a program with a return value that indicates to the surrounding system whether the exit is
normal or abnormal (§9.4.1.1).

===
There is no way of catching exceptions thrown during initialization of global variables. The
only way of gaining control in case of t h r o w from an initializer of a nonlocal static object is
s e t _ u n e x p e c t e d () (§14.6.2). This is another reason to avoid global variables whenever possible.

===
When an exception is caught, the exact point where it was thrown is generally not known. This
represents a loss of information compared to what a debugger might know about the state of a program.
In some C++ development environments, for some programs, and for some people, it might
therefore be preferable n o t to catch exceptions from which the program isn’t designed to recover.

===
The standard exceptions are derived from e x c e p t i o n . However, not every exception is, so it would
be a mistake to try to catch every exception by catching e x c e p t i o n . Similarly, it would be a mistake
to assume that every exception derived from e x c e p t i o n is a standard library exception: programmers
can add their own exceptions to the e x c e p t i o n hierarchy .

===
14.11 Advice [except.advice]
[1] Use exceptions for error handling; §14.1, §14.5, §14.9.
[2] Don’t use exceptions where more local control structures will suffice; §14.1.
[3] Use the ‘‘resource allocation is initialization’’ technique to manage resources; §14.4.
[4] Not every program needs to be exception safe; §14.4.3.
[5] Use ‘‘resource allocation is initialization’’ and exception handlers to maintain invariants;
§14.3.2.
[6] Minimize the use of tryblocks.
Use ‘‘resource acquisition is initialization’’ instead of explicit
handler code; §14.4.
[7] Not every function needs to handle every possible error; §14.9.
[8] Throw an exception to indicate failure in a constructor; §14.4.6.
[9] Avoid throwing exceptions from copy constructors; §14.4.6.1.
[10] Avoid throwing exceptions from destructors; §14.4.7.
[11] Have m a i n () catch and report all exceptions; §14.7.
[12] Keep ordinary code and errorhandling
code separate; §14.4.5, §14.5.
[13] Be sure that every resource acquired in a constructor is released when throwing an exception
in that constructor; §14.4.
[14] Keep resource management hierarchical; §14.4.
[15] Use exceptionspecifications
for major interfaces; §14.9.
[16] Beware of memory leaks caused by memory allocated by n e w not being released in case of an
exception; §14.4.1, §14.4.2, §14.4.4.
[17] Assume that every exception that can be thrown by a function will be thrown; §14.6.
[18] Don’t assume that every exception is derived from class e x c e p t i o n ; §14.10.
[19] A library shouldn’t unilaterally terminate a program. Instead, throw an exception and let a
caller decide; §14.1.
[20] A library shouldn’t produce diagnostic output aimed at an end user. Instead, throw an exception
and let a caller decide; §14.1.
[21] Develop an errorhandling
strategy early in a design; §14.9.
*/
#include <iostream>

struct DummyErr
{
  
};

class Matherr
{
public:
  virtual 
  void
  debug_print() const
  {
    std::cerr << "Math err" << std::endl;
  }
};

class Int_overflow: public Matherr
{
  const char* op;
  int a1, a2;
  
public:
  Int_overflow(const char* p,int a,int b)
  {
    op = p;
    a1 = a;
    a2 = b;
  }
  
  virtual
  void
  debug_print() const
  {
    std::cerr << op << "(" << a1 << "," << a2 << ")" << std::endl;
  }
  
};

void g() throw(Int_overflow,std::bad_exception);

void
g() throw(Int_overflow,std::bad_exception)
{
//  throw Int_overflow("+",1,2);
}

// Practicing 14.6.3 Mapping Exceptions [except.mapping], BUT does not work yet
void
g_2() throw(Int_overflow,std::bad_exception)
{
  throw DummyErr();// this is an unexpected exception
}


int
main()
{
  try
  {
//    g();  
    g_2();
  }
//  catch(Int_overflow ioe)
//  {
//    ioe.debug_print();
//  }
//  catch(Matherr me)
//  {
////    When the M a t h e r r handler is entered, m is a M a t h e r r object – even if the call to g () threw
////    I n t _ o v e r f l o w . This implies that the extra information found in an I n t _ o v e r f l o w is inaccessible.
//    me.debug_print();
//  }
  catch(const Matherr& me)
  {
//    As always, pointers or references can be used to avoid losing information permanently.
//    Had the exception been caught by value rather than by reference,
//    M a t h e r r :: d e b u g _ p r i n t () would have been invoked instead.

//    add c o n s t to the type used to catch an exception in the same way that we can
//    add it to a function parameter. This doesn’t change the set of exceptions we can catch; it only
//    restricts us from modifying the exception caught.

    me.debug_print();
  }
  catch(...)
  {
    std::cerr << "catch(...)" << std::endl;
  }
  
  return 0;
}
