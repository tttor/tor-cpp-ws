//=======================================================================
// Copyright 2001 Jeremy G. Siek, Andrew Lumsdaine, Lie-Quan Lee, 
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <fstream>              // for file I/O
#include <boost/graph/graphviz.hpp>     // for read/write_graphviz()
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/lexical_cast.hpp>

namespace boost {
  enum graph_color_t { graph_color = 5556 };
  BOOST_INSTALL_PROPERTY(graph, color);
}

int
main()
{
  using namespace boost;
//  typedef 
//    adjacency_list<vecS, vecS, directedS,
//                   property<vertex_name_t, std::string>, 
//                   property<edge_color_t, std::string,
//                            property<edge_weight_t, int> >,
//                   property<graph_color_t, std::string> >
//    Graph;
    
  typedef 
    adjacency_list < vecS, vecS, directedS, 
                   no_property,
                   property < edge_weight_t, int > > 
  Graph;
    
  typedef graph_traits<Graph> Traits;
  typedef Traits::vertex_descriptor Vertex;
  typedef Traits::edge_descriptor Edge;
  
  Graph g;

  Edge edge;
  bool inserted;      
  
  tie(edge, inserted) = add_edge(0,1,g);
//  put(vertex_name, g, source(edge,g),"0");
//  put(vertex_name, g, target(edge,g),"1");
//    
//  tie(edge, inserted) = add_edge(1,2,g);
//  put(vertex_name, g, source(edge,g),"1");
//  put(vertex_name, g, target(edge,g),"2");
//    
//  tie(edge, inserted) = add_edge(1,3,g);
//  put(vertex_name, g, source(edge,g),"1");  
//  put(vertex_name, g, target(edge,g),"3");

//  tie(edge, inserted) = add_edge(3,4,g);
//  put(vertex_name, g, source(edge,g),"3");  
//  put(vertex_name, g, target(edge,g),"4");  
//  
//  tie(edge, inserted) = add_edge(3,5,g);
//  put(vertex_name, g, source(edge,g),"3");  
//  put(vertex_name, g, target(edge,g),"5"); 
//  
//  tie(edge, inserted) = add_edge(2,4,g);
//  put(vertex_name, g, source(edge,g),"2");  
//  put(vertex_name, g, target(edge,g),"4");   

//  tie(edge, inserted) = add_edge(4,6,g);
//  put(vertex_name, g, source(edge,g),"4");  
//  put(vertex_name, g, target(edge,g),"6");
  
  graph_traits < Graph >::edge_iterator ei, ei_end;
  for (boost::tie(ei, ei_end) = edges(g); ei != ei_end; ++ei) 
  {
    int weight = 1;
    put(edge_weight,g,*ei,weight);
  }

  
  
//    graph_traits < Graph >::vertex_iterator vi, vi_end;
//  for (boost::tie(vi, vi_end) = vertices(g); vi != vi_end-1; ++vi)
//  {
//    Edge e2 = edge(*vi, *(vi+1), g).first;
//  }

//  Vertex router_six = 0;
////  graph_traits < Graph >::vertex_iterator vi, vi_end;
////  for (boost::tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi)
////    if ("RT6" == get(vertex_name, g, *vi)) {
////      router_six = *vi;
////      break;
////    }

//  std::vector < Vertex > parent(num_vertices(g));
//  // All vertices start out as there own parent
//  typedef graph_traits < Graph >::vertices_size_type size_type;
//  for (size_type p = 0; p < num_vertices(g); ++p)
//    parent[p] = p;


//  dijkstra_shortest_paths(g, router_six, predecessor_map(&parent[0]));

////  graph_traits < Graph >::edge_descriptor e;
////  for (size_type i = 0; i < num_vertices(g); ++i)
////    if (parent[i] != i) {
////      e = edge(parent[i], i, g).first;
////      put(edge_color, g, e, "black");
////    }

////  get_property(g, graph_color) = "grey";
////  {
////    std::ofstream outfile("figs/ospf-sptree.dot");
////    write_graphviz_dp(outfile, g, dp);
////  }

////  std::ofstream rtable("routing-table.dat");
////  rtable << "Dest    Next Hop    Total Cost" << std::endl;
////  graph_traits < Graph >::vertex_iterator vi, vi_end;
////  for (boost::tie(vi, vi_end) = vertices(g); vi != vi_end; ++vi)
////    if (parent[*vi] != *vi) {
////      rtable << get(vertex_name, g, *vi) << "    ";
////      Vertex v = *vi, child;
////      int path_cost = 0;
////      property_map < Graph, edge_weight_t >::type
////        weight_map = get(edge_weight, g);
////      do {
////        path_cost += get(weight_map, edge(parent[v], v, g).first);
////        child = v;
////        v = parent[v];
////      } while (v != parent[v]);
////      rtable << get(vertex_name, g, child) << "     ";
////      rtable << path_cost << std::endl;

////    }

  return EXIT_SUCCESS;
}
