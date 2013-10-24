#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main ()
{
  std::string name;
  name = "TidyHome";
  
  std::vector<std::string> name_parts;
  boost::split( name_parts, name, boost::is_any_of("_"), token_compress_on );
//  boost::split( name_parts, name, boost::is_any_of(";"));
  
  cout << "name_parts.size()= " <<  name_parts.size() << endl;
  for(std::vector<std::string>::const_iterator i=name_parts.begin(); i!=name_parts.end(); ++i)
  {
    cout << *i << endl;
  }
  
  return 0;
}
