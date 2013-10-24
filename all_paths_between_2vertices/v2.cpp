#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>

using namespace boost;
using namespace std;

template < typename GlobalGraph >
class tor_bfs_visitor:public default_bfs_visitor 
{

public:
  tor_bfs_visitor(vector< vector<typename graph_traits<GlobalGraph>::vertex_descriptor> >* predecessors_map)
  :predecessors_map_(predecessors_map)
  { }
  
  template < typename Vertex, typename Graph >
  void discover_vertex(Vertex v, const Graph & g) const
  {
    cout << "discover v= " << get(vertex_name,g,v) << endl;
  }
  
  template < typename Vertex, typename Graph >
  void finish_vertex(Vertex v, const Graph & g) const
  {
    cout << "finish v= " << get(vertex_name,g,v) << endl;
  }
  
  template < typename Edge, typename Graph >
  void examine_edge(Edge e, const Graph & g) const
  {
    cout << "examine e=(" << get(vertex_name,g,source(e,g)) << "," << get(vertex_name,g,target(e,g)) << ")" << endl;
    
    predecessors_map_->at(target(e,g)).push_back(source(e,g));
  }
  
  template < typename Edge, typename Graph >
  void tree_edge(Edge e, const Graph & g) const
  {
    cout << "tree_edge e=(" << get(vertex_name,g,source(e,g)) << "," << get(vertex_name,g,target(e,g)) << ")" << endl;
  }

private:
vector< vector<typename graph_traits<GlobalGraph>::vertex_descriptor> >* predecessors_map_;
};

//void
//backtrack(const p_map, graph g,ptr to path_set, vertex v)
//{
//  if(p_map is empty)
//  {
//    return;
//  }
//  else
//  {
//    for_each predessor p
//    {
//      edge = p to v;
//      
//      find paths in path_set whose last edge has the source v
//      if found
//      {
//        add edge to every found path
//      }
//      else
//      {
//        create new path of edge 
//        then push to path set
//      }
//      
//      backtrack(predecessor_map,path_set,p)
//    }
//  }
//}

template<typename Graph>
void
backtrack(const Graph& g
         ,const std::vector< std::vector<typename graph_traits<Graph>::vertex_descriptor> >& predecessors_map
         ,const typename graph_traits<Graph>::vertex_descriptor& v
         ,std::vector< std::vector<typename graph_traits<Graph>::edge_descriptor> >* paths
         )
{
//  cout << "v= " << get(vertex_name,g,v) << endl;
//  
//  cout << "paths.size()= " << paths->size() << endl;
//  for(size_t i=0; i<paths->size(); ++i)
//  {
//    cout << "path th= " << i << ": " << endl;
//    for(size_t j=0; j<paths->at(i).size(); ++j)
//    {
//      typename graph_traits<Graph>::edge_descriptor e = paths->at(i).at(j);
//      cout << "e(" << get(vertex_name,g,source(e,g)) << "," << get(vertex_name,g,target(e,g)) << "),";
//    }
//    cout << endl;
//  }
  
  if( predecessors_map.at(v).empty() )
  {
    return;
  }
  
  size_t n_predecessors;
  n_predecessors = predecessors_map.at(v).size();
  
  // find paths in path_set whose last edge has the source v
  // Assume that all matched_paths are unique
  std::vector< std::vector<typename graph_traits<Graph>::edge_descriptor> > matched_paths;

  for(size_t j=0; j<paths->size(); ++j)
  {
    typename graph_traits<Graph>::edge_descriptor last_e;
    last_e = paths->at(j).back();
    
    if(source(last_e,g) == v)
    {
      matched_paths.push_back( paths->at(j) );
    }
  }
    
  // Duplicate matched_paths as many as (n_predecessors-1)
//  cout << "matched_paths.size()= " << matched_paths.size() << endl;
  for(size_t i=0; i<matched_paths.size(); ++i)
  {
    for(size_t j=0; j<(n_predecessors-1); ++j)
    {
      paths->push_back(matched_paths.at(i));
    }
  }

  for(size_t i=0; i< predecessors_map.at(v).size(); ++i)
  {
    typename graph_traits<Graph>::vertex_descriptor p;
    p = predecessors_map.at(v).at(i);
    
    typename graph_traits<Graph>::edge_descriptor e;
    e = boost::edge(p,v,g).first;
    
    // find _one_ (first found) path in path_set whose last edge has the source v,
    // then add e to that path
    // TODO is it possible that there exist multiple unique path that end with (v,any) ?
    bool found = false;
    for(size_t j=0; j<paths->size(); ++j)
    {
      typename graph_traits<Graph>::edge_descriptor last_e;
      last_e = paths->at(j).back();
      
      if(source(last_e,g) == v)
      {
        paths->at(j).push_back(e);
        found = true;
        break;
      }
    }

    if(!found)
    {
      // Create a new path with e, then push to paths
      std::vector<typename graph_traits<Graph>::edge_descriptor> path;
      path.push_back(e);
      
      paths->push_back(path);
    }
    
    backtrack<Graph>(g,predecessors_map,p,paths);
  }// for each predecessor
}

int
main()
{
  //===========================================================================
  // Declare the graph type and object, and some property maps.

  typedef 
  adjacency_list< vecS, vecS, directedS, 
                  property<vertex_name_t, std::string, property<vertex_color_t, default_color_type> >, 
                  property<edge_name_t, std::string, property<edge_weight_t, int> > > 
  Graph;
  
  typedef graph_traits<Graph> Traits;
  typedef Traits::vertex_descriptor Vertex;
  typedef Traits::edge_descriptor Edge;
  //===========================================================================
  // Construct the graph.
  Graph g;
 
  Edge edge;
  bool inserted;      
  
  tie(edge, inserted) = add_edge(0,1,g);
  put(vertex_name, g, source(edge,g),"0");
  put(vertex_name, g, target(edge,g),"1");
    
  tie(edge, inserted) = add_edge(0,2,g);
  put(vertex_name, g, source(edge,g),"0");
  put(vertex_name, g, target(edge,g),"2");
    
  tie(edge, inserted) = add_edge(1,3,g);
  put(vertex_name, g, source(edge,g),"1");  
  put(vertex_name, g, target(edge,g),"3");
  
  tie(edge, inserted) = add_edge(2,3,g);
  put(vertex_name, g, source(edge,g),"2");  
  put(vertex_name, g, target(edge,g),"3");
  
  tie(edge, inserted) = add_edge(3,4,g);
  put(vertex_name, g, source(edge,g),"3");  
  put(vertex_name, g, target(edge,g),"4");
  
  tie(edge, inserted) = add_edge(3,5,g);
  put(vertex_name, g, source(edge,g),"3");  
  put(vertex_name, g, target(edge,g),"5");
  
  tie(edge, inserted) = add_edge(4,6,g);
  put(vertex_name, g, source(edge,g),"4");  
  put(vertex_name, g, target(edge,g),"6");
  
  tie(edge, inserted) = add_edge(5,6,g);
  put(vertex_name, g, source(edge,g),"5");  
  put(vertex_name, g, target(edge,g),"6");
  
//  tie(edge, inserted) = add_edge(3,7,g);
//  put(vertex_name, g, source(edge,g),"3");  
//  put(vertex_name, g, target(edge,g),"7");
//  
//  tie(edge, inserted) = add_edge(7,4,g);
//  put(vertex_name, g, source(edge,g),"7");  
//  put(vertex_name, g, target(edge,g),"4");
  //============================================================================
  Vertex root = 0;
  
  std::vector< std::vector<Vertex> > predecessors_map(num_vertices(g));
  
  tor_bfs_visitor<Graph> vis(&predecessors_map);
  breadth_first_search(g,root,visitor(vis));
  
  for(size_t i=0; i<predecessors_map.size(); ++i) 
  {
    cout << "predecessors of v=" << i << " are ";
    
    for(size_t j=0; j<predecessors_map.at(i).size(); ++j) 
    {
      cout << predecessors_map.at(i).at(j) << ", ";
    }
    cout << endl;
  }

  //Backtrack
  Vertex goal = 6;
  std::vector< std::vector<Edge> > paths;
  
  backtrack<Graph>(g,predecessors_map,goal,&paths);
  
  cout << "----------------------------------------------------" << endl;
  cout << "paths.size()= " << paths.size() << endl;
  for(size_t i=0; i<paths.size(); ++i)
  {
    std::reverse(paths.at(i).begin(),paths.at(i).end());
    
    cout << "path th= " << i << ": " << endl;
    for(size_t j=0; j<paths.at(i).size(); ++j)
    {
      Edge e = paths.at(i).at(j);
      cout << "e(" << get(vertex_name,g,source(e,g)) << "," << get(vertex_name,g,target(e,g)) << "),";
    }
    cout << endl;
  }

  
}
