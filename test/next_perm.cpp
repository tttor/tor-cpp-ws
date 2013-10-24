// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

int main () {
//  int vec[] = {1,2,3};
//  char vec[] = {'a','b','c'};
//  std::sort (vec,vec+3);

//  std::vector<int> vec;
//  vec.push_back(1);
//  vec.push_back(2);
//  vec.push_back(3);    
  
  std::vector<std::string> vec;
  vec.push_back("/home/vektor/rss-2013/data/baseline/v.3/1obj/run.1obj.20130308a.0");
  vec.push_back("/home/vektor/rss-2013/data/baseline/v.3/1obj/run.1obj.20130308a.1");
  vec.push_back("/home/vektor/rss-2013/data/baseline/v.3/1obj/run.1obj.20130308a.2");

  std::sort(vec.begin(),vec.end());

  std::cout << "The 3! possible permutations with 3 elements:" << factorial(3) << "\n";
  do {
    std::cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << '\n';
  } while ( std::next_permutation(vec.begin(),vec.end()) );

  std::cout << "After loop: " << vec[0] << ' ' << vec[1] << ' ' << vec[2] << '\n';

  return 0;
}
