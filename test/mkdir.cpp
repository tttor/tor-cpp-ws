#include <boost/filesystem.hpp>
#include <iostream>

using namespace std;

int
main()
{
  boost::filesystem::create_directories("/home/vektor/tor-cpp-ws/test/a/b/c");
  
  return 0;
}
