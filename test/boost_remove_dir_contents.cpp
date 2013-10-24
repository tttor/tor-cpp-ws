#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include <iostream>               // for std::cout

using namespace boost::filesystem; 
using namespace std;

bool
remove_dir_contents(path dir_path)
{
  if ( !exists( dir_path ) ) return false;
  
  for ( directory_iterator itr( dir_path ),end_itr; itr != end_itr; ++itr )
    remove(itr->path());
  
  return true;
}

int
main()
{
  remove_dir_contents(path("/home/vektor/tor-cpp-ws/copy_des"));
  return 0;
}
