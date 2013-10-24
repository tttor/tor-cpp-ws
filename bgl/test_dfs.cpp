//=======================================================================
// Copyright 2001 Jeremy G. Siek, Andrew Lumsdaine, Lie-Quan Lee, 
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/range/irange.hpp>
#include <boost/pending/indirect_cmp.hpp>

#include <iostream>

using namespace boost;

template < typename TimeMap > 
class dfs_time_visitor:public default_dfs_visitor 
{
  typedef typename property_traits < TimeMap >::value_type T;

public:
dfs_time_visitor(TimeMap dmap, TimeMap fmap, T & t)
:  m_dtimemap(dmap), m_ftimemap(fmap), m_time(t) 
{}

  template < typename Vertex, typename Graph >
    void discover_vertex(Vertex u, const Graph & g) const
  {
    
    put(m_dtimemap, u, m_time++);
  }
  
  template < typename Vertex, typename Graph >
    void finish_vertex(Vertex u, const Graph & g) const
  {
    put(m_ftimemap, u, m_time++);
  }
  
  TimeMap m_dtimemap;
  TimeMap m_ftimemap;
  T & m_time;
};


int
main()
{
  using namespace boost;
  //===========================================================================
  // Declare the graph type and object, and some property maps.

  typedef adjacency_list<vecS, vecS, directedS, property<vertex_name_t, std::string, property<vertex_color_t, default_color_type> >, property<edge_name_t, std::string, property<edge_weight_t, int> > > Graph;

  typedef graph_traits<Graph> Traits;
  typedef Traits::vertex_descriptor Vertex;
  typedef Traits::edge_descriptor Edge;
  typedef Traits::vertices_size_type size_type;
  typedef std::map<std::string, Vertex> NameVertexMap;

  NameVertexMap name2vertex;
  Graph g;

  typedef property_map<Graph, vertex_name_t>::type NameMap;
  property_map<Graph, edge_name_t>::type link_name = get(edge_name, g);

  //===========================================================================
  // Read the data file and construct the graph.
  
  Edge edge;
  bool inserted;      
  
  tie(edge, inserted) = add_edge(0,1,g);
  put(vertex_name, g, source(edge,g),"0");
  put(vertex_name, g, target(edge,g),"1");
    
  tie(edge, inserted) = add_edge(1,2,g);
  put(vertex_name, g, source(edge,g),"1");
  put(vertex_name, g, target(edge,g),"2");
    
  tie(edge, inserted) = add_edge(2,3,g);
  put(vertex_name, g, source(edge,g),"2");  
  put(vertex_name, g, target(edge,g),"3");
    
  tie(edge, inserted) = add_edge(1,4,g);
  put(vertex_name, g, source(edge,g),"1");  
  put(vertex_name, g, target(edge,g),"4");
  
  tie(edge, inserted) = add_edge(4,5,g);
  put(vertex_name, g, source(edge,g),"4");  
  put(vertex_name, g, target(edge,g),"5");

  tie(edge, inserted) = add_edge(4,6,g);
  put(vertex_name, g, source(edge,g),"4");  
  put(vertex_name, g, target(edge,g),"6");
      
  //===========================================================================
  // discover time and finish time properties
  std::vector < size_type > dtime(num_vertices(g));
  std::vector < size_type > ftime(num_vertices(g));
  size_type t = 0;
  dfs_time_visitor < size_type * >vis(&dtime[0], &ftime[0], t);

  depth_first_search(g, visitor(vis));

  return EXIT_SUCCESS;
}
