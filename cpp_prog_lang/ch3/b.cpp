// ostream_iterator example
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main () {
  vector<int> myvector;
  for (int i=1; i<10; ++i) myvector.push_back(i*10);

  ostream_iterator<int> out_it (cout,", ");
  copy ( myvector.begin(), myvector.end(), out_it );
  return 0;
}
