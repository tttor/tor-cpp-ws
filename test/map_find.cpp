// map::find
#include <iostream>
#include <map>
using namespace std;

int main ()
{
//  map<char,int> mymap;
//  map<char,int>::iterator it;
  
  map<char,double> mymap;
  map<char,double>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it=mymap.find('b');
  mymap.erase (it);
  mymap.erase (mymap.find('d'));

  // print content:
  cout << "elements in mymap:" << endl;
  cout << "a => " << mymap.find('a')->second << endl;
  cout << "c => " << mymap.find('c')->second << endl;
  cout << "x => " << mymap.find('x')->second << endl;

  return 0;
}
