#include <iostream>

using namespace std;

class A {
 public:
  A(): i_(7) {
  
  }

 protected:
  int i_;
};

class B: public A {
 public:
  B() {
  
  }
  
  void print_i() {
    cout << "i_= " << i_ << endl;
  }

};

int main() {
  B b;
  b.print_i();
  
  return 0;
}
