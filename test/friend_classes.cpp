// classes_as_friends2.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;

class YourClass 
{
friend class YourOtherClass;  // Declare a friend class

public:
   YourClass() 
   : topSecret(0)
   {}
   
   void printMember() { cout << topSecret << endl; }
   
   void change_me();
private:
   int topSecret;
   
};

class YourOtherClass 
{
public:
  YourOtherClass(YourClass* yc_ptr)
  : yc_ptr_(yc_ptr)
  {
  
  }

//   void change( YourClass& yc, int x );//{yc.topSecret = x;}
     void change_her( int x );//{yc.topSecret = x;}
private:
  YourClass* yc_ptr_;     
};

//void
//YourClass::change_me()
//{
//  YourOtherClass yoc1;

//  yoc1.change( *this, 7 );
//}

void
YourClass::change_me()
{
  YourOtherClass yoc1(this);

  yoc1.change_her( 7 );
}

void
YourOtherClass::change_her(int x)
{
  yc_ptr_->topSecret = x;
}

int main() {
   YourClass yc1;
   yc1.printMember();
   
   yc1.change_me();
   yc1.printMember();   
}
