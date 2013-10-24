/*
===
Members of a namespace must be introduced using this notation:
n a m e s p a c e n a m e s p a c e n
a m e {
/ / declaration and definitions
}

===
Ideally, every entity in a program belongs to some recognizable logical unit (‘‘module’’).
Therefore, every declaration in a nontrivial program should ideally be in some namespace named to
indicate its logical role in the program. The exception is m a i n (), which must be global in order
for the runtime
environment to recognize it as special (§8.3.3).

===
A namespace is a scope. The usual scope rules hold for namespaces, so if a name is previously
declared in the namespace or in an enclosing scope, it can be used without further fuss.

===
we can simply leave the namespace without a name:
Clearly, there has to be some way of accessing members of an unnamed namespace from the outside.
Consequently, an unnamed namespace has an implied usingdirective.
see pp.177

===
providing a short alias for a longer namespace name:
/ / use namespace alias to shorten names:
n a m e s p a c e A T T = A m e r i c a n _ T e l e p h o n e _ a n d _ T e l e g r a p h ;

n a m e s p a c e L i b = F o u n d a t i o n _ l i b r a r y _ v 2 r 1 1 ;

===
Overloading (§7.4) works across namespaces

===
A namespace is open; that is, you can add names to it from several namespace declarations.

===
The construct
c a t c h (  ...  ) {
/ / ...
}
is called an exception handler. It can be used only immediately after a block prefixed with the keyword
t r y or immediately after another exception handler; c a t c h is also a keyword. The parentheses
contain a declaration that is used in a way similar to how a function argument declaration is used.
That is, it specifies the type of the objects that can be caught by this handler and optionally names
the object caught.

===
8.4 Advice [name.advice]
[1] Use namespaces to express logical structure; §8.2.
[2] Place every nonlocal name, except m a i n (), in some namespace; §8.2.
[3] Design a namespace so that you can conveniently use it without accidentally gaining access to
unrelated namespaces; §8.2.4.
[4] Avoid very short names for namespaces; §8.2.7.
[5] If necessary, use namespace aliases to abbreviate long namespaces names; §8.2.7.
[6] Avoid placing heavy notational burdens on users of your namespaces; §8.2.2, §8.2.3.
[7] Use the N a m e s p a c e :: m e m b e r notation when defining namespace members; §8.2.8.
[8] Use u s i n g n a m e s p a c e only for transition or within a local scope; §8.2.9.
[9] Use exceptions to decouple the treatment of ‘‘errors’’ from the code dealing with the ordinary
processing; §8.3.3.
[10] Use userdefined
rather than builtin
types as exceptions; §8.3.2.
[11] Don’t use exceptions when local control structures are sufficient; §8.3.3.1.
*/

#include<iostream>

namespace ns_a
{

void
f1();

void
f2();
}

void
ns_a::f1()
{
  using std::cout;
  using std::endl;
  
  cout << "inside f1()" << endl;
  
  f2();// no qualification needed
}

void
ns_a::f2()
{
  using std::cout;
  using std::endl;
  
  cout << "inside f2()" << endl;
}

namespace ns_a_alias = ns_a;

namespace Error
{
int n_err;

double
err(const char* s)
{
  std::cerr << "err: " << s << "\n";
  n_err++;
  return 1;
}
}


int
main()
{
  ns_a::f1();
  
  return 0;
}
