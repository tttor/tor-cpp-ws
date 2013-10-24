#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/breadth_first_search.hpp>

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
                      property<vertex_name_t, std::string, property<vertex_color_t, default_color_type> >, 
                      property<edge_name_t, std::string > > Graph;
  
//  typedef 
//  adjacency_list<vecS, vecS, directedS, 
//                      property<vertex_name_t, std::string>, 
//                      property<edge_name_t, std::string > > Graph;
                      
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

  tie(edge, inserted) = add_edge(2,6,g);
  put(vertex_name, g, source(edge,g),"2");  
  put(vertex_name, g, target(edge,g),"6");   

  tie(edge, inserted) = add_edge(4,6,g);
  put(vertex_name, g, source(edge,g),"4");  
  put(vertex_name, g, target(edge,g),"6");
  
  tie(edge, inserted) = add_edge(1,7,g);
  put(vertex_name, g, source(edge,g),"1");  
  put(vertex_name, g, target(edge,g),"7");
  
  tie(edge, inserted) = add_edge(7,8,g);
  put(vertex_name, g, source(edge,g),"7");  
  put(vertex_name, g, target(edge,g),"8");
  
  tie(edge, inserted) = add_edge(8,5,g);
  put(vertex_name, g, source(edge,g),"8");  
  put(vertex_name, g, target(edge,g),"5");
  
//  graph_traits < Graph >::edge_iterator ei, ei_end;
//  for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei) 
//  {
//    int weight = 1;
//    put(edge_weight,g,*ei,weight);
//  }
  //===========================================================================
  Vertex src = 0;
    
  std::vector < Vertex > parent(num_vertices(g));
  // All vertices start out as there own parent
  typedef graph_traits < Graph >::vertices_size_type size_type;
  for (size_type p = 0; p < num_vertices(g); ++p)
    parent[p] = p;
    
    boost::breadth_first_search
    (g, src, 
     boost::visitor(
                     boost::make_bfs_visitor(
                                               boost::record_predecessors(&parent[0],boost::on_tree_edge()) 
                                             ) 
                   )
    );
    
  boost::graph_traits<Graph>::vertex_iterator vi, vi_end;
  for (boost::tie(vi,vi_end) = vertices(g); vi != vi_end; ++vi)
  {
    if( get(vertex_color,g,*vi)==color_traits<boost::default_color_type>::gray() )
      cerr << *vi << "= gray" << endl;
    else if( get(vertex_color,g,*vi)==color_traits<boost::default_color_type>::black() )
      cerr << *vi << "= black" << endl;
    else 
      cerr << *vi << "= white" << endl;
  }   
  //===========================================================================
  vector<Edge> path;

  Vertex v = 6;
  Vertex child;
  do 
  {
    typename graph_traits<Graph>::out_edge_iterator ei, ei_end;
    for (tie(ei, ei_end) = out_edges(parent[v], g); ei != ei_end; ++ei)
    {
      if(target(*ei,g)==v)
        path.push_back(*ei);
    }

    child = v;
    v = parent[v];
  } while (v != parent[v]);

  
////  graph_traits < Graph >::vertex_iterator vi, vi_end;
//  for (boost::tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi)
//  {
//    if(*vi==6)
//    {
//      Vertex v = *vi;
//      Vertex child;
//      
//      do 
//      {
//        typename graph_traits<Graph>::out_edge_iterator ei, ei_end;
//        for (tie(ei, ei_end) = out_edges(parent[v], g); ei != ei_end; ++ei)
//        {
//          if(target(*ei,g)==v)
//            path.push_back(*ei);
//        }

//        child = v;
//        v = parent[v];
//      } while (v != parent[v]);
//    }
//  }
  
  cout << "path.size()= " << path.size() << endl;
  for(vector<Edge>::iterator i=path.begin(); i!=path.end(); ++i)
  {
    cout << "e(" << source(*i,g) << "," << target(*i,g) << "), ";
  }
  cout << endl;
  //===========================================================================
  return 0;
}
