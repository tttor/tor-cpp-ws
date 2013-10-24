#include <iostream>
#include <fstream>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int.hpp>
#include <boost/random/variate_generator.hpp>

static boost::mt19937 g_rng( std::time(0) );

//! Randomize instances, important because the data order matters as it influences how the model is updated; works like randperm() in matlab
void
randomize(std::vector<std::string>* inst_paths)
{
  if (inst_paths->empty() )
    return;

  boost::uniform_int<> dist( 0,inst_paths->size()-1 ) ;
  boost::variate_generator< boost::mt19937&, boost::uniform_int<> > rnd(g_rng,dist);

  std::vector<size_t> idxes;// Store indexes of the randomized instance order
  for(size_t i=0; i<inst_paths->size(); ++i)
  {
    size_t idx;
    bool already;
    
    do
    {
      already = false;
      
      idx = rnd();
      
      std::vector<size_t>::iterator it;
      it = std::find(idxes.begin(),idxes.end(),idx);
      
      if(it != idxes.end())
        already = true;
    }
    while(already);
    
    idxes.push_back(idx);
  }
  
  std::vector<std::string> tmp_inst_paths;
  tmp_inst_paths = *inst_paths;
  for(size_t i=0; i<tmp_inst_paths.size(); ++i)
    inst_paths->at(i) = tmp_inst_paths.at(idxes.at(i));
}

int
main()
{
  using namespace std;
  
  boost::filesystem::path base_data_path = "";
  string inst_type = "";
  
  // Obtain unique instance paths
  if( !exists(base_data_path) or !is_directory(base_data_path) )
  {
    cerr << base_data_path << " -> !exists(.) or !is_directory(.)" << endl;
    return false;
  }

  bool specific;
  if( !strcmp(inst_type.c_str(),std::string("0obj").c_str()) )
    specific = false;
  else
    specific = true;
  
  std::vector<std::string> inst_paths;
  boost::filesystem::directory_iterator end_itr; // default construction yields past-the-end
  for ( boost::filesystem::directory_iterator itr(path);itr != end_itr; ++itr )
  {
    if ( is_directory(itr->status()) )
    {
      std::string inst_path;
      inst_path = itr->path().string();
      
      if(!specific)
      {
        inst_paths.push_back(inst_path);
      }
      else
      {
        std::vector<std::string> inst_path_parts;
        boost::split( inst_path_parts,inst_path,boost::is_any_of("/") );// Split e.g. /home/vektor/rss-2013/data/with_v.4.2/baseline/run.1obj.20130430a.1
        
        std::vector<std::string> inst_path_subparts;
        boost::split( inst_path_subparts,inst_path_parts.back(),boost::is_any_of(".") );
        if(inst_path_subparts.at(0).size() == 0) return false;
        
        std::string local_inst_type;
        local_inst_type = inst_path_subparts.at(1);
        
        if( !strcmp(local_inst_type.c_str(),inst_type.c_str()) )
          inst_paths.push_back(inst_path);
      }
    }
  }

  // Randomize
  randomize(&inst_paths);
  
  // Write inst_path order
  
}// main())
