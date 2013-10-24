#include <boost/graph/graphviz.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <string>
#include <fstream>
#include <boost/graph/iteration_macros.hpp>

#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/astar_search.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random.hpp>
#include <boost/random.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/graph_utility.hpp>

#include </home/vektor/hiroken-ros-pkg/hiro_common/include/tmm_utils.hpp>

using namespace boost;
using namespace std;

typedef boost::adjacency_list<vecS, vecS, directedS,
                               property < vertex_name_t, std::string, property < vertex_color_t, std::string, property <vertex_index_t, std::string> > >,
                              property<edge_weight_t, double> > Digraph;

//int
//main(int argc, char* argv[])
//{
//  TaskMotionMultigraph tmm;
//  boost::dynamic_properties dp;

////  dp.property("id", get(vertex_name, tmm));
////  dp.property("id", get(vertex_index, tmm));
////  dp.property("label", get(vertex_name, tmm));
////  dp.property("label", get(edge_name, tmm));
//  
//  std::ifstream in("/home/vektor/hiroken-ros-pkg/planner_manager/data/tmm.dot");
//  read_graphviz(in, tmm, dp, "id");
//    
//  cout << "num_vertices(tmm)= " << num_vertices(tmm) << endl;
//  
//  write_graphviz_dp(std::cout, tmm, dp, std::string("id"));
//  
//  return 0;  
//}

int
main(int argc, char* argv[])
{
//  std::string dot_path = "/home/vektor/hiroken-ros-pkg/planner_manager/data/tmg.dot";
  std::string dot_path = "test.dot";  
  
  std::ifstream in( dot_path.c_str() );
  
  Digraph g;
  
  dynamic_properties dp;
  dp.property("id", get(vertex_name, g));
//  dp.property("mass", get(vertex_color, g)); 
  dp.property("color", get(vertex_color, g));
  dp.property("weight", get(edge_weight, g)); 
  
  read_graphviz(in, g, dp, "id");
  
  cout << "num_vertices(g)= " << num_vertices(g) << endl;
  
  dynamic_properties dp2;
  dp2.property("id", get(vertex_name, g));
  
  write_graphviz_dp(std::cout, g, dp2, std::string("id"));
  
}
