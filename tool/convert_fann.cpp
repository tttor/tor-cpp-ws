#include <boost/algorithm/string.hpp>
#include <fstream>
#include <vector>

using namespace std;
using namespace boost;

int
main(int argc, char* argv[])
{
  // Get the number of samples==number of lines
  std::string csv_file_path = "/home/vektor/hiroken-ros-pkg/planner_manager/data/1/data.csv";
  std::ifstream csv_file_in(csv_file_path.c_str());
  
  size_t n = 0;
  if (csv_file_in.is_open())
  {
    while ( csv_file_in.good() )
    {
      std::string line;
      getline (csv_file_in,line);// Just for counting the line
      ++n;
    }
    --n;// Remove the bias from the method above!
    
    csv_file_in.close();
  }
  
  // Put the header information
  std::string fann_data_file_path = "/home/vektor/hiroken-ros-pkg/planner_manager/data/1/fann_training.data";
  std::ofstream fann_data_file;
  fann_data_file.open(fann_data_file_path.c_str());// Overwrite
  
  // TODO make this adapt!
  size_t n_input_feature = 33;
  size_t n_output = 1;
  
  fann_data_file << n << " " << n_input_feature << " " << n_output << endl;
  fann_data_file.close();
  
  // Read and Rewrite in the fann file. TODO it should use only one csv_file_path
  std::string csv_file_path_2 = "/home/vektor/hiroken-ros-pkg/planner_manager/data/1/data.csv";
  std::ifstream csv_file_in_2(csv_file_path_2.c_str());
  
  if (csv_file_in_2.is_open())
  {
    while ( csv_file_in_2.good() )
    {
      std::string line;
      getline (csv_file_in_2,line);
      
      std::vector<std::string> line_parts;
      boost::split( line_parts, line, boost::is_any_of(",") );
      
      // Write to the fann data file
      std::ofstream fann_data_file_2;
      fann_data_file_2.open(fann_data_file_path.c_str(), std::ios_base::app);
      
      // Write the input
      for(std::vector<std::string>::const_iterator i=line_parts.begin(); i!=line_parts.end()-1; ++i)
        fann_data_file_2 << *i << " ";
      fann_data_file_2 << endl;
      
      //Write the output
      fann_data_file_2 << *(line_parts.end()-1) << endl;
      
      fann_data_file_2.close();
      
//      break;
    }
    csv_file_in_2.close();
  }
  
  return 0;
}
