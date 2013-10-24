// accessing mapped values
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main ()
{
  map<char,string> mymap;

  mymap['a']="vektor";
  mymap['b']="dewanto";
  mymap['c']=mymap['b'];

  cout << "mymap['a'] is " << mymap['a'] << endl;
  cout << "mymap['b'] is " << mymap['b'] << endl;
  cout << "mymap['c'] is " << mymap['c'] << endl;
  cout << "mymap now contains " << (int) mymap.size() << " elements." << endl;

  cout << "mymap['d'] is " << mymap['d'] << endl;
  cout << "mymap now contains " << (int) mymap.size() << " elements." << endl;
  
  map<size_t, double> map_2;
  map_2.insert( pair<size_t, double>(1, 1.23) );
  
  cout << map_2[1] << endl;
  cout << map_2[2] << endl;// is default double value, i.e. 0.
  cout << "map_2.size()= " << map_2.size() << endl;

  return 0;
}
