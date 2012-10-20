/*
Concepts: 
> namespace dumping
> standard io
> string
> container
> iterator

The containers are defined in namespace s t d and presented in headers <v e c t o r >, <l i s t >, <m a p >, etc. (§16.2).
*/
#include <iostream>
#include <stdio.h>// for: printf
#include <vector>
#include <list>
#include <algorithm>// for: find(), count(), unique_copy(), sort(), etc...
#include <iterator>


void print(size_t i) 
{
  std::cout << " " << i;
}

size_t 
count(const std::string& s, const char& c)// Why did he use (..., char c) ? 
{
  std::string::const_iterator i = find(s.begin(), s.end(), c);
  size_t n = 0;

  while(i != s.end())
  {
    ++n;
    i = find(i+1, s.end(), c);
  }
  
  return n;
}

// count with generic prog.
template<class C, class T>
size_t
count(const C& v, const T& val)
{
  ///,,, as above
}

int// cannot be change to e.g. size_t !
main()
{
  {
    using namespace std;// to use scoping for dumping names from a namespace into the global namespace namespace is preferable
    
    cout << "tor\n";
  }
  
  ////////////////////// STRING
  /*
  {
  using namespace std;
  
  std::string s1 = "vektor";// without the need to explicitly #include <string> here!
  
  if (s1 == "vektor") // can be compared against each other and against string literals, NOTE: c.f. strcmp(), strcmp compares the contents of the strings while == compares the address of the first elements in the strings
    cout << "yes\n";
  else
    cout << "no\n";
  
  string subs1;
  subs1 = s1.substr(1,3);// returns a string that is a copy of the substring indicated by its arguments. The first argument is an index into the string (a position), and the second argument is the length of the desired substring.
  cout << subs1 << endl;
  
  s1.replace(0,2, "dewanto ");// replaces a substring with a value. Note that the replacement string need not be the same size as the substring that it is replacing.
  cout << s1 << endl;
  
  printf("%s \n", s1.c_str());// A Cstyle string is a zero-terminated array of characters; WHAT DOES THIS MEAN?
  
  cout << "your name: " ;
  
  string name;
  cin >>  name;// a whitespace character (§5.2.2) such as a space terminates the read
  cout << "ok, " << name << endl;
  
  cout << "your name: " ;
  
  string name2;
  getline(cin, name2);// to read a whole line
  cout << "ok, " << name2 << endl;   
  }
  */
  ////////////////////// VECTOR
  {
  using namespace std;
 
  vector<int> v_int(3); 
  vector<int> v_int_2[3];// NO compiletion err, bUT error: request for member ‘size’ in ‘v_int_2’, which is of non-class type ‘std::vector<int, std::allocator<int> > [3]’
  
  cout << "v_int.size()= " << v_int.size() << endl;
  
  //NOTE: Assigning a v e c t o r involves copying its elements.
  // The a t () operation is a v e c t o r subscript operation that throws an exception of type o u t _ o f _ r a n g e if its argument is out of the v e c t o r ’s range (§16.3.3).
 
 /* 
  try
  {
    cout << v_int[1] << endl;
  }
  catch(out_of_range)// leads to compile-error  error: expected type-specifier before ‘out_of_range’, but see p.54, so?
  {
  }
 */    
  }//end of: namespace block for VECTOR
  
  /////////////////////// LIST
  // When we use a list, we tend not to access elements using subscripting the way we commonly do for vectors. Instead, we might search the list looking for an element with a given value.
  // handy methods of a list: push_front(e), push_back(e), insert(i, e) [add before the element ‘i’ refers to]
 
  ///////////////////////// MAP
  // If no match was found for the key s , a default value is returned of its element type, e.g. 0 for integer
  // A m a p resembles a l i s t of (key,value) pairs except that it is optimized for finding values based on keys.
 
  ////////////////////////// Algorithm
  //sort()
  //copy()
  //uniquie_copy()
  //find()
  //count()
  //find_if()
  //count_if()

  //many algorithms return iterators. For example, find()
  //A m a p keeps its elements ordered so that an iteration traverses the m a p in (increasing) order.
  //Like C, C++ wasn’t designed primarily with numerical computation in mind  
  //standard library facilities are defined in namespace s t d
  
  //?? how to use for_each where the function predicate is a member function of the same class where for_each is called
  //A: try to use mem_fun that takes a pointer to a member function (§15.5) as its argument and produces something that can be called for a pointer to the member’s class.
  
  {
  using namespace std;
  
  vector<size_t> v;
  v.push_back(3);
  v.push_back(1);
  v.push_back(5);
  v.push_back(5);
  v.push_back(8);    
  
  sort(v.begin(),v.end());
  for_each(v.begin(),v.end(),print); cout << endl;
  
  list<size_t> l;
  
  unique_copy(v.begin(),v.end(),back_inserter(l));
  for_each(l.begin(), l.end(), print); cout << endl;
  
  }
  ///////////////////////// OTHERS
  {
  using namespace std;
  
  string name = "vektor dewanto";
  cout << count(name.begin(), name.end(), 'e') << endl; 
  
  ostream_iterator<string> oo(cout);// WHat to include?
  
  *oo = "tor ";
  oo++;
  *oo = "dewa\n";

  }
  
  return 0;
}
