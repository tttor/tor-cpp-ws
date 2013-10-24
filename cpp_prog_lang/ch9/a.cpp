/*
===
A user presents a source file to the compiler. The file is then preprocessed; that is, macro processing
(§7.8) is done and #i n c l u d e directives bring in headers (§2.4.1, §9.2.1). The result of preprocessing
is called a translation unit. This unit is what the compiler proper works on and what the
C++ language rules describe.

===
The linker is the program that binds together the separately compiled parts. A linker is
sometimes (confusingly) called a loader. Linking can be done completely before a program starts
to run. Alternatively, new code can be added to the program (‘‘dynamically linked’’) later.

===
The keyword e x t e r n indicates
that the declaration of x in f i l e 2 .c is (just) a declaration and not a definition (§4.9).

Had x
been initialized, e x t e r n would simply be ignored because a declaration with an initializer is always
a definition.

===
Note that a
variable defined without an initializer in the global or a namespace scope is initialized by default.
This is not the case for local variables (§4.9.5, §10.4.2) or objects created on the free store (§6.2.6).

===
In C and older C++ programs, the keyword s t a t i c is (confusingly) used to mean ‘‘use internal
linkage’’ (§B.2.3). Don’t use s t a t i c except inside functions (§7.1.2) and classes (§10.2.4).

The use of s t a t i c to indicate ‘‘local to translation unit’’ is deprecated in C++. Use unnamed
namespaces instead (§8.2.5.1).

Global variables that are local to a single compilation unit are a common source of confusion and
are best avoided. To ensure consistency, you should usually place global c o n s t s and i n l i n e s in
header files only (§9.2.1).

===
To include standard library headers, use the angle brackets < and > around the name instead of
quotes. For example:
#i n c l u d e <i o s t r e a m > // from standard include directory
#i n c l u d e "m y h e a d e r .h " // from current directory
Unfortunately, spaces are significant within the< > or" " of an include directive:
#i n c l u d e < i o s t r e a m > // will not find <iostream>

===
No
suffix is needed for standard library headers; they are known to be headers because they are
included using the #i n c l u d e <...> syntax rather than #i n c l u d e "...". The absence of a .h suffix
does not imply anything about how the header is stored.

For each C standardlibrary
header <X .h >, there is a corresponding standard C++ header <c X >.
For example, #i n c l u d e <c s t d i o > provides what #i n c l u d e <s t d i o .h > does.

===
A template definition can be #i n c l u d e d in several translation units as long as the ODR is
adhered to. In addition, an exported template can be used given only a declaration:
/ / file1.c:
e x p o r t t e m p l a t e <c l a s s T > T t w i c e (T t ) { r e t u r n t +t ; }
/ / file2.c:
t e m p l a t e <c l a s s T > T t w i c e (T t ); // declaration
i n t g (i n t i ) { r e t u r n t w i c e (i ); }
The keyword e x p o r t means ‘‘accessible from another translation unit’’ (§13.7).
9.2.4

===
To be recognized as the m a i n () of the program, m a i n () must be a global function, so no namespace
is used here.

===
In principle, a variable defined outside any function (that is, global, namespace, and class s t a t i c
variables) is initialized before m a i n () is invoked.

===
A program can terminate in several ways:
– By returning from m a i n ()
– By calling e x i t ()
– By calling a b o r t ()
– By throwing an uncaught exception

===
9.5 Advice [file.advice]
[1] Use header files to represent interfaces and to emphasize logical structure; §9.1, §9.3.2.
[2] #i n c l u d e a header in the source file that implements its functions; §9.3.1.
[3] Don’t define global entities with the same name and similarbutdifferent
meanings in different
translation units; §9.2.
[4] Avoid noninline
function definitions in headers; §9.2.1.
[5] Use #i n c l u d e only at global scope and in namespaces; §9.2.1.
[6] #i n c l u d e only complete declarations; §9.2.1.
[7] Use include guards; §9.3.3.
[8] #i n c l u d e C headers in namespaces to avoid global names; §9.3.2.
[9] Make headers selfcontained;
§9.2.3.
[10] Distinguish between users’ interfaces and implementers’ interfaces; §9.3.2.
[11] Distinguish between average users’ interfaces and expert users’ interfaces; §9.3.2.
[12] Avoid nonlocal objects that require runtime
initialization in code intended for use as part of
nonC++
programs; §9.4.1.
*/

