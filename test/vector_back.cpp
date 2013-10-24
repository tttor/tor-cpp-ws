// vector::back
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main ()
{
  std::vector<int> myvector;

  myvector.push_back(10);
  myvector.push_back(20);
  myvector.push_back(30);
  
  std::cout << myvector.back() << std::endl;
//  while (myvector.back() != 0)
//  {
//    myvector.push_back ( myvector.back() -1 );
//  }

//  std::cout << "myvector contains:";
//  for (unsigned i=0; i<myvector.size() ; i++)
//    std::cout << ' ' << myvector[i];
//  std::cout << '\n';

//  std::set<int> my_set(myvector.begin(),myvector.end());

//  for(std::set<int>::const_iterator i=my_set.begin(); i!=my_set.end(); ++i)
//    cout << *i << endl;
    
  return 0;
}
