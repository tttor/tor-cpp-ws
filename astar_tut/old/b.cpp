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
    cout << "in h()" << endl;
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
  typedef adjacency_list<listS, vecS, directedS, property<vertex_name_t, std::string>, property<edge_weight_t, cost> > graph_t;  
  typedef graph_t::vertex_descriptor vertex;
  
  graph_t g; 
  std::ifstream readFile2("dat3"); 
  readFile2 >> read( g );
//  std::cout << "graph g from file dat:\n"  << write( g ) << std::endl;
  
  graph_property_iter_range<graph_t, vertex_name_t>::iterator ci2, ci_end;
  tie(ci2, ci_end) = get_property_iter_range(g, vertex_name);
  std::vector<std::string> name;
  
  for(size_t i=0; ci2!=ci_end; ++ci2,++i)
  {
    std::cout << "name: " << *ci2 << std::endl;
    name.push_back(*ci2);
  }
  
  graph_property_iter_range<graph_t, edge_weight_t>::iterator ep_it,ep_it_end;
  tie(ep_it, ep_it_end) = get_property_iter_range(g, edge_weight);

  typedef property_map<graph_t, edge_weight_t>::type WeightMap;
  WeightMap weightmap = get(edge_weight, g);
  
  for(size_t i=0; ep_it!=ep_it_end; ++ep_it,++i)
  {
    std::cout << "edge_weight: " << *ep_it << std::endl;
    weightmap[edge(i,i+1,g).first] = *ep_it;
  }
  
  // determine start/goal nodes
  vertex start = 0;// Cannot be: MessyHome, unless it is defined.
  vertex goal = 5;
  
  ofstream dotfile;
  dotfile.open("b.dot");
  write_graphviz(dotfile, g,
               state_writer< std::vector<std::string> >(name),
               geo_cost_writer< WeightMap >(weightmap)
               );  
                   
  vector<graph_t::vertex_descriptor> p(num_vertices(g));
  vector<cost> d(num_vertices(g));
  
  try 
  {
    astar_search(g, start,
       geo_cost_heuristic<graph_t, cost>(goal),
       predecessor_map(&p[0]).distance_map(&d[0]).
       visitor(astar_goal_visitor<vertex>(goal)));
  }
  catch(found_goal fg) 
  { // found a path to the goal
    list<vertex> shortest_path;
    for(vertex v = goal;; v = p[v]) 
    {
      shortest_path.push_front(v);
      if(p[v] == v)
        break;
    }
    cout << "Shortest path from " << name[start] << " to "
         << name[goal] << ": ";
    list<vertex>::iterator spi = shortest_path.begin();
    cout << name[start];
    for(++spi; spi != shortest_path.end(); ++spi)
      cout << " -> " << name[*spi];
    cout << endl << "Total travel time: " << d[goal] << endl;
    cout << "Found a path" << endl;
    return 0;
  }
  
  cout << "Didn't find a path from " << endl;
  return 0;
}// end of: main()
