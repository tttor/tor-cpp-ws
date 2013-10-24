//=======================================================================
// Copyright 1997, 1998, 1999, 2000 University of Notre Dame.
// Authors: Andrew Lumsdaine, Lie-Quan Lee, Jeremy G. Siek
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================
#include <boost/config.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <boost/pending/stringtok.hpp>
#include <boost/utility.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/depth_first_search.hpp>

using namespace std;
using namespace boost;

struct FoundGoalSignal {}; // exception for termination

template<typename GlobalGraph>
class OptSolPathEstimator: public boost::dfs_visitor<>
{
public:
OptSolPathEstimator(typename boost::graph_traits<GlobalGraph>::vertex_descriptor& goal,std::vector<typename boost::graph_traits<GlobalGraph>::edge_descriptor>* goal_reached_path)
: goal_(goal), goal_reached_path_(goal_reached_path)
{ }

template <class Graph>
void 
discover_vertex(typename boost::graph_traits<Graph>::vertex_descriptor v,Graph&)
{
  std::cout << "discover " << v << std::endl;
}

template <class Graph>
void 
finish_vertex(typename boost::graph_traits<Graph>::vertex_descriptor v,Graph& g)
{
  std::cout << "finish " << v << std::endl;
  
  if(v == goal_)
  {
    *goal_reached_path_ = hot_path_;
    throw FoundGoalSignal();
  }
  else
  {
    hot_path_.erase(hot_path_.end()-1);
  }
}

template <class Graph>
void tree_edge(typename boost::graph_traits<Graph>::edge_descriptor e,Graph& g)
{
  hot_path_.push_back(e);
  
  for(typename std::vector< typename boost::graph_traits<GlobalGraph>::edge_descriptor >::iterator i=hot_path_.begin(); i!=hot_path_.end(); ++i)
    cout << "e(" << source(*i,g) << "," << target(*i,g) << "), ";
  cout << endl;
}

private:
typename boost::graph_traits<GlobalGraph>::vertex_descriptor goal_;
std::vector<typename boost::graph_traits<GlobalGraph>::edge_descriptor>* goal_reached_path_;
std::vector<typename boost::graph_traits<GlobalGraph>::edge_descriptor> hot_path_;
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
  //===========================================================================

  std::vector< std::vector<Edge> > paths; 
  
  Graph tmp_g = g;
  Vertex src = 0;  
  Vertex goal = 6;
  bool more = true;

  do
  {
    std::vector<Edge> path;
    OptSolPathEstimator<Graph> ospe(goal,&path);  
    
    try
    {
      depth_first_visit(tmp_g,src,ospe,get(vertex_color,tmp_g));
    }
    catch(FoundGoalSignal fgs)
    { };
    
    if( !path.empty() )
    {
      more = true;// possible there are more goal-reached paths
      paths.push_back(path);
      
      // Delete the last edge of path in the tmp_g
      remove_edge(path.back(),tmp_g);
      
      // Reset all vertex_color in tmp_g to white
      boost::graph_traits<Graph>::vertex_iterator vi, vi_end;
      for (boost::tie(vi,vi_end) = vertices(tmp_g); vi != vi_end; ++vi)
        put(vertex_color,tmp_g,*vi,color_traits<boost::default_color_type>::white());
    }
    else
    {
      more = false;
    }
  }
  while(more);

  cerr << "paths.size()= "  << paths.size() << endl;
  for(typename std::vector< std::vector<Edge> >::const_iterator i=paths.begin(); i!=paths.end(); ++i)
  {
    cerr << "Path " << i-paths.begin() << endl;
    for(std::vector<Edge>::const_iterator j=i->begin(); j!=i->end(); ++j)
    {
      cout << "e(" << source(*j,g) << "," << target(*j,g) << "), ";
    }
    cout << endl;
  } 

//  boost::graph_traits<Graph>::vertex_iterator vi, vi_end;
//  for (boost::tie(vi,vi_end) = vertices(g); vi != vi_end; ++vi)
//  {
//    if( get(vertex_color,g,*vi)==color_traits<boost::default_color_type>::gray() )
//      cerr << *vi << "= gray" << endl;
//    else if( get(vertex_color,g,*vi)==color_traits<boost::default_color_type>::black() )
//      cerr << *vi << "= black" << endl;
//    else 
//      cerr << *vi << "= white" << endl;
//  }   
  
//  cerr << "============================================================================================" << endl;
//  for (boost::tie(vi,vi_end) = vertices(tmp_g); vi != vi_end; ++vi)
//  {
//    if( get(vertex_color,tmp_g,*vi)==color_traits<boost::default_color_type>::gray() )
//      cerr << *vi << "= gray" << endl;
//    else if( get(vertex_color,tmp_g,*vi)==color_traits<boost::default_color_type>::black() )
//      cerr << *vi << "= black" << endl;
//    else 
//      cerr << *vi << "= white" << endl;
//  }   
//    
//     
//  cerr << "============================================================================================" << endl;
//    
//  src = 1;
//  paths.clear();
//  
//  depth_first_visit(g,src,ospe,get(vertex_color, g));
// 
//  cerr << "paths.size()= "  << paths.size() << endl;
//  for(typename std::vector< std::vector<Edge> >::const_iterator i=paths.begin(); i!=paths.end(); ++i)
//  {
//    cerr << "Path " << i-paths.begin() << endl;
//    for(std::vector<Edge>::const_iterator j=i->begin(); j!=i->end(); ++j)
//    {
//      cout << "e(" << source(*j,g) << "," << target(*j,g) << "), ";
//    }
//    cout << endl;
//  } 
  
  return EXIT_SUCCESS;
}
