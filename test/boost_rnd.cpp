#include <iostream>
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"

#include <boost/random/normal_distribution.hpp>

using namespace std;

//int main() 
//{
//  typedef boost::mt19937 RNGType;
//  RNGType rng;

//  boost::uniform_int<> one_to_six( 1, 6 );
//  boost::variate_generator< RNGType, boost::uniform_int<> > dice(rng, one_to_six);
//  
//  for ( int i = 0; i < 6; i++ ) 
//  {
//      int n  = dice();
//      cout << n << endl;
//  }
//}

int main()
{
  boost::mt19937 rng; // I don't seed it on purpouse (it's not relevant)

  boost::normal_distribution<> nd(0.0, 1.0);

  boost::variate_generator<boost::mt19937&, 
                           boost::normal_distribution<> > var_nor(rng, nd);

  int i = 0; for (; i < 10; ++i)
  {
    double d = var_nor();
    std::cout << d << std::endl;
  }
}
