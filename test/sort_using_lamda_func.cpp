//http://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm> 

using namespace std;
  
bool 
myfunction(pair<string,size_t> p1,pair<string,size_t> p2)
{ 
  return p1.second < p2.second;
}

// MAKE using
// $ g++ sort_using_lamda_func.cpp -std=c++0x

int
main()
{
  cout << "hi..." << endl;
  
  vector< pair<string,size_t> > pairs;
  pairs.push_back( std::make_pair("dewa",17) );  
  pairs.push_back( std::make_pair("tor",7) );
  
//  sort(pairs.begin(),pairs.end(),
//       [&pairs](pair<string,size_t> p1,pair<string,size_t> p2) {return p1.second < p2.second;});
       
  sort(pairs.begin(),pairs.end(),myfunction);
  
  for(size_t i=0; i<pairs.size(); ++i)
    cout << pairs.at(i).second << endl;
    
  return 0;
}
