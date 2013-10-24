#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main ()
{
  string str1="Hello Dolly, Hello World!";
//  replace_first(str1, "Dolly", "Jane");      // str1 == "Hello  Jane,   Hello World!"
//  replace_last(str1, "Hello", "Goodbye");    // str1 == "Hello  Jane,   Goodbye World!"
//  erase_all(str1, " ");                      // str1 == "HelloJane,GoodbyeWorld!"
//  erase_head(str1, 6);                       // str1 == "Jane,GoodbyeWorld!"
  erase_tail(str1,2);
    
  cout << "str1= " << str1 << endl;
  
  return 0;
}
