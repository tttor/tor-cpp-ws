#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct{
  int* int_pointer;
} Test;

#ifdef __cplusplus
}
#endif

int main(){
  using namespace std;

  int i = 7;
  
//  // 
//  int ia[3];
//  ia[0] = 0;
//  ia[1] = 1;
//  ia[2] = 2;
//  
//  int* p;
//  p = ia;
//  
//  cout << "p[0]= " << p[0] << endl;
//  cout << "p[1]= " << p[1] << endl;
//  
//  return 0;
  
//  //
//  Test t;
//  
//  t.int_pointer = &i;
//  
//  cout << "&i= " << &i << endl;
//  cout << "t.int_pointer= " << t.int_pointer << endl;

  cout << "======\n";
  
  int a[] = {1,2,3};
  
  Test t_src;
  t_src.int_pointer = a;
  
  Test* t2;
  t2 = &t_src;
  
  cout << "t2->int_pointer[0]= " << t2->int_pointer[0] << endl;
  
  cout << "check1 \n ";
  t2->int_pointer[0] = i;
  
  cout << "&i= " << &i << endl;
  cout << "t2->int_pointer[0]= " << t2->int_pointer[0] << endl;

//  //
//  string s = 
//  "vektor \
//   dewanto";
//  
//  cout << "s= " << s << endl;
  
  return 0;
}
