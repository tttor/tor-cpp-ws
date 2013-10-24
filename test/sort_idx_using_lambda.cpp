//http://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm> 

using namespace std;

//bool 
//cmp(size_t i1, size_t i2)
//{ 
//  return p1.second < p2.second;
//}
  
template <typename T>
vector<size_t> 
sort_indexes(const vector<T> &v) 
{

  // initialize original index locations
  vector<size_t> idx(v.size());
  for (size_t i = 0; i != idx.size(); ++i) idx[i] = i;

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] < v[i2];});

  return idx;
}

template<typename T> 
class CompareIndicesByAnotherVectorValues 
{ 
  std::vector<T>* _values; 
  
  public: 
  CompareIndicesByAnotherVectorValues(std::vector<T>* values) : _values(values) {} 
  
  public: 
  bool 
  operator() (const int& a, const int& b) const 
  { 
  return (*_values)[a] > (*_values)[b]; 
  } 
};

int
main()
{
  
  cout << "hi..." << endl;
  
  vector<size_t> vals;
  vals.push_back(17);
  vals.push_back(7);
  vals.push_back(1);

  for(size_t i=0; i<vals.size(); ++i)
    cout << vals.at(i) << endl;
      
  vector<size_t> sorted_idx;
  
//  sorted_idx = sort_indexes<size_t>(vals);
//  for(size_t i=0; i<sorted_idx.size(); ++i)
//    cout << sorted_idx.at(i) << endl;
    
  CompareIndicesByAnotherVectorValues<size_t> cmper(&vals);
  sort(vals.begin(),vals.end(),cmper);

  for(size_t i=0; i<vals.size(); ++i)
    cout << vals.at(i) << endl;
 
  return 0;
}
