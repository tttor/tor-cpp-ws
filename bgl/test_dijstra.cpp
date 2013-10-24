#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/adjacency_list.hpp>

namespace boost {
  enum graph_color_t { graph_color = 5556 };
  BOOST_INSTALL_PROPERTY(graph, color);
}

int
main()
{
  using namespace boost;
  using namespace std;
  //===========================================================================
  // Declare the graph type and object, and some property maps.

//  typedef 
//  adjacency_list<vecS, vecS, directedS, 
//                      property<vertex_name_t, std::string, property<vertex_color_t, default_color_type> >, 
//                      property<edge_name_t, std::string, property<edge_weight_t, int> > > Graph;
  
    typedef 
    adjacency_list<vecS, vecS, directedS,
                   property<vertex_name_t, std::string>, 
                   property<edge_color_t, std::string,
                            property<edge_weight_t, double> >,
                   property<graph_color_t, std::string> >
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
    
  tie(edge, inserted) = add_edge(1,2,g);
  put(vertex_name, g, source(edge,g),"1");
  put(vertex_name, g, target(edge,g),"2");
    
  tie(edge, inserted) = add_edge(1,3,g);
  put(vertex_name, g, source(edge,g),"1");  
  put(vertex_name, g, target(edge,g),"3");

  tie(edge, inserted) = add_edge(3,4,g);
  put(vertex_name, g, source(edge,g),"3");  
  put(vertex_name, g, target(edge,g),"4");  
  
  tie(edge, inserted) = add_edge(3,5,g);
  put(vertex_name, g, source(edge,g),"3");  
  put(vertex_name, g, target(edge,g),"5"); 
  
  tie(edge, inserted) = add_edge(2,4,g);
  put(vertex_name, g, source(edge,g),"2");  
  put(vertex_name, g, target(edge,g),"4");   

  tie(edge, inserted) = add_edge(4,6,g);
  put(vertex_name, g, source(edge,g),"4");  
  put(vertex_name, g, target(edge,g),"6");
  
  tie(edge, inserted) = add_edge(1,7,g);
  put(vertex_name, g, source(edge,g),"1");  
  put(vertex_name, g, target(edge,g),"7");
  
  tie(edge, inserted) = add_edge(7,8,g);
  put(vertex_name, g, source(edge,g),"7");  
  put(vertex_name, g, target(edge,g),"8");
  
  tie(edge, inserted) = add_edge(8,2,g);
  put(vertex_name, g, source(edge,g),"8");  
  put(vertex_name, g, target(edge,g),"2");
  
  graph_traits < Graph >::edge_iterator ei, ei_end;
  for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei) 
  {
    int weight = 1;
    put(edge_weight,g,*ei,weight);
  }
  //===========================================================================
  Vertex src = 7;
  Vertex goal = 6;      

  // All vertices start out as there own parents
  std::vector < Vertex > parents(num_vertices(g));
  typedef graph_traits < Graph >::vertices_size_type size_type;
  for (size_type p = 0; p < num_vertices(g); ++p)
    parents[p] = p;
  
  dijkstra_shortest_paths(g, src, predecessor_map(&parents[0]));
  cerr << "dijkstra_shortest_paths: OK" << endl;
  //===========================================================================
  Vertex v = goal;
  Vertex child = v;
  
  if(parents[v] != v) 
  {
    int path_cost = 0;
  
    do 
    {
//      cerr << "v= " << get(vertex_name,g,v) << "; c= " << get(vertex_name,g,child) << endl;
    
      Edge e; 
      e = boost::edge(parents[v],v,g).first;
      
      path_cost += get(edge_weight,g,e);
      
      child = v;
      v = parents[v];
    } while (v != parents[v]);
    
    cout << path_cost << std::endl;
  }
  else
  {
    cout << "no path :(" << endl; 
  }
//===========================================================================
  return EXIT_SUCCESS;
}
