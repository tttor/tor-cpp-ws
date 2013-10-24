#include <iostream>
#include <vector>
#include <fstream>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main ()
{
  string log_path;
  log_path = "/home/vektor/rss-2013/data/onlwpr_log/onlwpr_2.log";
  cerr << log_path << endl;
  
  vector<size_t> idx_1;
  vector<size_t> idx_2;
  vector<size_t> idx_3;
  vector<size_t> idx_4;
  vector<size_t> idx_5;

  ifstream log_in(log_path.c_str());
  if(log_in.is_open())
  {
    string line;
    size_t n;
    while ( log_in.good() )
    {
      ++n;
      
      getline(log_in,line);
//      cout << line << endl;
      
      vector<string> line_comps;
      boost::split( line_comps, line, boost::is_any_of("/") );
      
      if(line_comps.at(0).size()==0)
        break;
        
      string obj;
      obj = line_comps.at(7);
//      cout << obj << endl;
      
      if( !strcmp(obj.c_str(),"1obj") )
        idx_1.push_back(n);
      else if( !strcmp(obj.c_str(),"2obj") )
        idx_2.push_back(n);
      else if( !strcmp(obj.c_str(),"3obj") )
        idx_3.push_back(n);
      else if( !strcmp(obj.c_str(),"4obj") )
        idx_4.push_back(n);
      else if( !strcmp(obj.c_str(),"5obj") )
        idx_5.push_back(n);
    }

    log_in.close();
  }
  else
  {
   cerr << "Unable to open the foo.cfg file" << endl;
   return false;
  }

  for(vector<size_t>::const_iterator i=idx_1.begin(); i!=idx_1.end();++i)
    cerr << *i << " ";
  cerr << endl;
  
  for(vector<size_t>::const_iterator i=idx_2.begin(); i!=idx_2.end();++i)
    cerr << *i << " ";
  cerr << endl;
    
  for(vector<size_t>::const_iterator i=idx_3.begin(); i!=idx_3.end();++i)
    cerr << *i << " ";
  cerr << endl;
  
  for(vector<size_t>::const_iterator i=idx_4.begin(); i!=idx_4.end();++i)
    cerr << *i << " ";
  cerr << endl;
  
  for(vector<size_t>::const_iterator i=idx_5.begin(); i!=idx_5.end();++i)
    cerr << *i << " ";
  cerr << endl;
  
  for(size_t i=0;i<idx_5.size();++i);//Commenting this line leads to error TODO why?
//    cerr << idx_5.at(i) << " ";
//  cerr << endl;
  
  // TODO HAVE NO IDEA WHY BELOW IS A BUG!  
//  for(size_t j=0;j<idx_2.size();++j)
//    cerr << idx_2.at(j) << " ";
//  cerr << endl;
//  
//  for(size_t i=0;i<idx_3.size();++i)
//    cerr << idx_3.at(i) << " ";
//  cerr << endl;
//  
//  for(size_t i=0;i<idx_4.size();++i)
//    cerr << idx_4.at(i) << " ";
//  cerr << endl;
//  
//  for(size_t i=0;i<idx_5.size();++i)
//    cerr << idx_5.at(i) << " ";
//  cerr << endl;
  
  return 0;
}
