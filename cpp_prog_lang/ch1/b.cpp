/*
Concepts:
>> generic programming
*/
#include <iostream>

template<class T> class Stack
{
  T* v_;
  size_t max_size_;
  size_t top_;
  
  public:
  class Underflow{};
  class Overflow{};
  
  Stack(size_t max_size): max_size_(max_size)
  {
    top_ = 0;
    v_ = new T[max_size];
  }
  ~Stack()
  {
    delete[] v_;
  };
  
  void push(T);
  T pop();
};

template<class T>
void 
Stack<T>::push(T c)// ATT: it _must_be ...Stack<T>
{
  if(top_ == max_size_)
  {
    throw Overflow();
  }

  v_[top_] = c;
  ++top_;
}

template<class T>
T
Stack<T>::pop()
{
  if(top_ == 0)
    throw Underflow();
 --top_;  
 return v_[top_];
}

int
main()
{
  Stack<int> st(3);

  for(size_t i=0; i<7; ++i) 
  {
    try
    {
      st.push(i);
    }
    catch(Stack<int>::Overflow)
    {
      std::cerr << "Overflow \n";
    }
  }    
}
