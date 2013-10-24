#include <boost/graph/astar_search.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/random.hpp>
#include <boost/random.hpp>
#include <boost/graph/graphviz.hpp>
#include <sys/time.h>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <math.h>    // for sqrt

#include <boost/config.hpp>

#if defined(BOOST_MSVC) && BOOST_MSVC <= 1300
#error adjacency_list_io.hpp has not been ported to work with VC++
#endif

#include <boost/graph/adjacency_list_io.hpp>

#include <boost/graph/property_iter_range.hpp>

using namespace boost;
using namespace std;

typedef float cost;

template<class Name>
class state_writer
{
public:
  state_writer(Name n)
    : name_(n)
  {}
  
  template <class Vertex>
  void operator()(ostream& out, const Vertex& v) const
  {
    out << "[label=\"" << name_[v]
        << "\", fontsize=\"11\"]";
  }
private:
  Name name_;
};

template <class WeightMap>
class geo_cost_writer {
public:
  geo_cost_writer(WeightMap w) : wm_(w) {}
  template <class Edge>
  void operator()(ostream &out, const Edge& e) const {
    out << "[label=\"" << wm_[e] << "\", fontsize=\"11\"]";
  }
private:
  WeightMap wm_;
};

template <class Graph, class CostType>
class geo_cost_heuristic:public astar_heuristic<Graph, CostType>
{
public:
  typedef typename graph_traits<Graph>::vertex_descriptor Vertex;
  geo_cost_heuristic(Vertex goal)
    :goal_(goal)
  {}
  
  CostType operator()(Vertex u)
  {
    return 0;
  }
private:
  Vertex goal_;
};

struct found_goal {}; // exception for termination

// visitor that terminates when we find the goal
template <class Vertex>
class astar_goal_visitor : public boost::default_astar_visitor
{
public:
  astar_goal_visitor(Vertex goal) : m_goal(goal) {}
  template <class Graph>
  void examine_vertex(Vertex u, Graph& g) {
    if(u == m_goal)
      throw found_goal();
  }
private:
  Vertex m_goal;
};

int 
main(int argc, char* argv[])
{
  // specify some types
  typedef adjacency_list<listS, vecS, directedS, no_property,property<edge_weight_t, cost> > mygraph_t;
  typedef property_map<mygraph_t, edge_weight_t>::type WeightMap;
  typedef mygraph_t::vertex_descriptor vertex;
  typedef mygraph_t::edge_descriptor edge_descriptor;
  typedef mygraph_t::vertex_iterator vertex_iterator;
  typedef std::pair<int, int> edge;
  
  typedef adjacency_list<listS, vecS, directedS, property<vertex_name_t, std::string>, property<edge_weight_t, cost> > mygraph_t2;  
  typedef mygraph_t2::vertex_descriptor vertex2;
    
  // specify data
  enum nodes {
    MessyHome, CanGraspCan1, GraspedCan1, CanReleaseCan1, ReleasedCan1, TidyHome, N
  };
  
  const char *name[] = {
    "MessyHome", "CanGraspCan1", "GraspedCan1", "CanReleaseCan1", "ReleasedCan1", "TidyHome"
  };
  
  edge edge_array[] = {
    edge(MessyHome,CanGraspCan1),
    edge(CanGraspCan1,GraspedCan1),
    edge(GraspedCan1,CanReleaseCan1),
    edge(CanReleaseCan1,ReleasedCan1),
    edge(ReleasedCan1,TidyHome)
  };
  
  unsigned int num_edges = sizeof(edge_array) / sizeof(edge);
  
  cost weights[] = { // estimated travel time (mins)
    96, 134, 143, 65, 115
  };
 
   // create graph
  mygraph_t g(N);
  WeightMap weightmap = get(edge_weight, g);
  
  mygraph_t2 g2; 
  std::ifstream readFile2("dat3"); cout << "found!" << endl;
  readFile2 >> read( g2 ); cout << "read!" << endl;
  std::cout << "graph g2 from file dat:\n"  << write( g2 ) << std::endl;
  
//  typedef property_map < mygraph_t2, vertex_name_t >::type name_map_t;
//  name_map_t name_map = get(vertex_name, g);
//  cout << name_map.second << endl;
  graph_property_iter_range<mygraph_t2, vertex_name_t>::iterator ci2, ci_end2;
  tie(ci2, ci_end2) = get_property_iter_range(g2, vertex_name);
  for(;ci2!=ci_end2;++ci2)
    std::cout << "name: " << *ci2 << std::endl;

  for(std::size_t j = 0; j < num_edges; ++j) {
    edge_descriptor e; 
    bool inserted;
    
    tie(e, inserted) = add_edge(edge_array[j].first,
                                edge_array[j].second, g);
    
    weightmap[e] = weights[j];
  }
  
  // determine start/goal nodes
  vertex start = MessyHome;
  vertex goal = TidyHome;
  
  cout << "Start vertex: " << name[start] << endl;
  cout << "Goal vertex: " << name[goal] << endl;
  
  ofstream dotfile;
  dotfile.open("astar_tut.dot");
  write_graphviz(dotfile, g,
                 state_writer<const char **>(name),
                 geo_cost_writer<WeightMap>(weightmap));

//  ofstream dotfile2;
//  dotfile2.open("astar_tut2.dot");
//  write_graphviz(dotfile2, g2,
//                 state_writer<const char **>(name),
//                 geo_cost_writer<WeightMap>(weightmap));
                   
  vector<mygraph_t::vertex_descriptor> p(num_vertices(g));
  vector<cost> d(num_vertices(g));
  
  vector<mygraph_t::vertex_descriptor> p2(num_vertices(g2));
  vector<cost> d2(num_vertices(g2));
  
  try 
  {
    // call astar named parameter interface
    /*
    astar_search(g, start,
       geo_cost_heuristic<mygraph_t, cost>(goal),
       predecessor_map(&p[0]).distance_map(&d[0]).
       visitor(astar_goal_visitor<vertex>(goal)));
*/
    astar_search(g2, start,
       geo_cost_heuristic<mygraph_t2, cost>(goal),
       predecessor_map(&p2[0]).distance_map(&d2[0]).
       visitor(astar_goal_visitor<vertex2>(goal)));
              
  }
  catch(found_goal fg) 
  { // found a path to the goal
//    list<vertex> shortest_path;
//    for(vertex v = goal;; v = p[v]) 
//    {
//      shortest_path.push_front(v);
//      if(p[v] == v)
//        break;
//    }
//    cout << "Shortest path from " << name[start] << " to "
//         << name[goal] << ": ";
//    list<vertex>::iterator spi = shortest_path.begin();
//    cout << name[start];
//    for(++spi; spi != shortest_path.end(); ++spi)
//      cout << " -> " << name[*spi];
//    cout << endl << "Total travel time: " << d[goal] << endl;
    cout << "Find a path" << endl;
    return 0;
  }
  
  cout << "Didn't find a path from " << name[start] << "to" << name[goal] << "!" << endl;
  return 0;
}// end of: main()
