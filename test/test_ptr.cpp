#include <iostream>

int
main()
{
  using namespace std;
  
  size_t i = 0;
  
  double* ptr;
  
  if(i == 0)
  {
    double d = 0.4;
    ptr = &d;
    
    cout << "*ptr= " << *ptr << endl; 
  }
  
  // This works, but
  // see http://stackoverflow.com/questions/4536366/is-it-safe-to-keep-a-pointer-to-a-variable-out-of-scope
  cout << "*ptr= " << *ptr << endl;
  
  *ptr = 0.7;
  cout << "*ptr= " << *ptr << endl;

  double d2 = *ptr;
  cout << "d2= " << d2 << endl;
  
  size_t* i_ptr = &i;
  ++(*i_ptr);
  cout << "*i_ptr= " << *i_ptr << endl;
  
  ++(*i_ptr);
  cout << "*i_ptr= " << *i_ptr << endl;

}

