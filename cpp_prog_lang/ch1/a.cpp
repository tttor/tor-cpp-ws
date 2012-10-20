/*
Concepts:
>> static keyword
>> namespace, with separate declaration
>> interface, virtual class
>> exception
*/

#include <iostream>
#include <list>

class Stack
{
public:
class Underflow{};
class Overflow{};

virtual void push(char c) = 0; 
virtual char pop() = 0;
// The curious =0 syntax says that some class derived from Stack must define the function
};

// The ‘‘:p ub li c’’ can be read as ‘‘is derived from,’’ ‘‘implements,’’ and ‘‘is a subtype of.’’
class List_Stack: public Stack
{
  std::list<char> lc_;
  size_t max_size_;
  size_t curr_size_;
  
public:
  List_Stack()
  {
    max_size_ = 3;
    curr_size_ = 0;
  }
  
  List_Stack(size_t max_size): max_size_(max_size)
  {
    curr_size_ = 0;
  }

  void push(char c)
  {
    if(curr_size_ == max_size_)
    {
      std::cerr << "a\n";
      throw Overflow();// make this exit/return from push()
    }
    std::cerr << "b\n";
    
    lc_.push_front(c);
    ++curr_size_;
  }
  
  char pop()
  {
    char x = lc_.front();
    lc_.pop_front();
    return x;
  }
};

int
main()
{
  List_Stack ls(2);

  for(size_t i=0; i<7; ++i) 
  {
    try
    {
      ls.push('v');
    }
    catch(Stack::Overflow)
    {
      std::cerr << "Overflow \n";
    }
  }    
 
 std::cout << ls.pop() << std::endl;
 
 return 0;
}
