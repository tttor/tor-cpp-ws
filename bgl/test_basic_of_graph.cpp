#include <boost/graph/adjacency_list.hpp>

int
main()
{
  using namespace boost;
  using namespace std;
 
  //===========================================================================
  // Declare the graph type and object, and some property maps.

  typedef 
  adjacency_list<vecS, vecS, directedS, 
                property<vertex_name_t, std::string, property<vertex_color_t, default_color_type> >, 
                property<edge_name_t, std::string, property<edge_weight_t, int> > > 
Graph;
  
  typedef graph_traits<Graph> Traits;
  typedef Traits::vertex_descriptor Vertex;
  typedef Traits::edge_descriptor Edge;
  //===========================================================================
  // Read the data file and construct the graph.
  Graph g;
 
  Edge edge;
  bool inserted;      
  
  tie(edge, inserted) = add_edge(0,1,g);
  put(vertex_name, g, source(edge,g),"0");
  put(vertex_name, g, target(edge,g),"1");
  
  // Test
  graph_traits<Graph>::edge_iterator ei,ei_end;
  tie(ei,ei_end) = edges(g);
  
  if(ei != ei_end)
  {
    cout << "graph exists" << endl;
  }
  else
  {
    cout << "graph does not exist" << endl;
  }
  
  return 0;
}
