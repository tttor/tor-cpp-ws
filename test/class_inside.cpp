#include <iostream>

using namespace std;

class A
{
public:
A()
{ 
  i_ = 5;
}

size_t
get_i()
{
  return i_;
}

A
create_A()
{
  A a;
  
  return a;
}
private:
size_t i_;

};

int
main()
{
  A a1;
  
  A a2;
  
  a2 = a1.create_A();
  
  cout << "a2.get_i()= " << a2.get_i() << endl;
  
  return 0;
}
