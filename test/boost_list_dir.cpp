#include "boost/filesystem.hpp"   // includes all needed Boost.Filesystem declarations
#include <iostream>               // for std::cout

using namespace boost::filesystem; 
using namespace std;

//bool find_file( const path & dir_path,         // in this directory,
//                const std::string & file_name, // search for this name,
//                path & path_found )            // placing path here if found
//{
//  if ( !exists( dir_path ) ) return false;
//  
//  directory_iterator end_itr; // default construction yields past-the-end
//  for ( directory_iterator itr( dir_path );
//        itr != end_itr;
//        ++itr )
//  {
//    if ( is_directory(itr->status()) )
//    {
//      if ( find_file( itr->path(), file_name, path_found ) ) return true;
//    }
//    else if ( itr->leaf() == file_name ) // see below
//    {
//      path_found = itr->path();
//      return true;
//    }
//  }
//  return false;
//}

int
main()
{
  path dir_path = path("/home/vektor/rss-2013/data/baseline/v.4/1obj");
  std::vector<string> list;  
    
  directory_iterator end_itr; // default construction yields past-the-end
  for ( directory_iterator itr( dir_path );
        itr != end_itr;
        ++itr )
  {
    if ( is_directory(itr->status()) )
    {
      cout << itr->path().string() << endl;
    }
  }
  

  return 0;
}
