#include <iostream>

class A {
 private:
  static int s_id;
  int id;

 public:
  A() {
    id = s_id++;
  }
  
  int get_id() const {
    return id;
  }
};

int A::s_id = 1;

int main () {
  A a1;
  A a2;
  A a3;
  
  using namespace std;
  cout << a1.get_id() << endl;
  cout << a2.get_id() << endl;
  cout << a3.get_id() << endl;
}
