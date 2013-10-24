#include <iostream>
#include <boost/filesystem.hpp>

using namespace std;

int
main()
{
  boost::filesystem::path src_tidy_cfg_path( std::string("/home/vektor/tor-cpp-ws/copy_src/tidy.cfg") );
  boost::filesystem::path des_tidy_cfg_path( std::string("/home/vektor/tor-cpp-ws/copy_des/tidy.cfg") );
  
//  boost::filesystem::copy_file( src_tidy_cfg_path,des_tidy_cfg_path );
  
  boost::filesystem::copy_file( std::string("/home/vektor/tor-cpp-ws/copy_src/tidy.cfg"),std::string("/home/vektor/tor-cpp-ws/copy_des/tidy.cfg") );
        
  return 0;
}
