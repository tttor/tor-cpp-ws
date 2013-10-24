#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

int
main()
{
  using namespace std;
  using namespace boost;
  
  double d = std::numeric_limits<double>::max();
  cout << "d= " << d << endl;
  
  if(d==std::numeric_limits<double>::max())
  {
    cout << "d==std::numeric_limits<double>::max()" << endl;
  }
  
  d += d;
  string s = boost::lexical_cast<string>(d);
  cout << "s= " << s << endl;
  
  double d2;
  try
  {
    d2 = boost::lexical_cast<double>(s);
  }
  catch(std::exception const&  ex)
  {
    std::cerr << ex.what() << std::endl;
  }
  
  cout << "d2= " << d2 << endl;
  
  return 0;
}
