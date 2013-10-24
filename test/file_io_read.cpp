// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <vector>

using namespace std;

int main () {
  string metadata;
  ifstream myfile ("for_file_io_read.txt");
  
  size_t n_line = 0;
  
  if (myfile.is_open())
  {
//    while ( myfile.good() )
//    {
      ++n_line;
      getline (myfile,metadata);
      cout << metadata << endl;
//    }
    myfile.close();
  }
  else cout << "Unable to open file"; 

  std::vector<std::string> feature_ids_vec;
  boost::split( feature_ids_vec, metadata, boost::is_any_of(",") );

  cout << "feature_ids_vec.size()= " << feature_ids_vec.size() << endl;
  
  for(size_t i=0; i<feature_ids_vec.size(); ++i)
    cout << feature_ids_vec.at(i) << endl;
    
  cout << "n_line= " << n_line << endl;
  
  return 0;
}
