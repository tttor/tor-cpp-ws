/*
CONCLUSION
> all edges that TMM store are unique, even when theirs source and target and property are all same
> for a graph g and its copy g2, we cannot search for an edge in g1, its copy in g2 simply by equality check using std::find(), instead we should use std::find_if()
*/
#include <iostream>
#include <boost/graph/adjacency_list.hpp>

using namespace std;
using namespace boost;

enum edge_jspace_t { edge_jspace };
namespace boost 
{
  BOOST_INSTALL_PROPERTY(edge, jspace);
}

typedef boost::property< edge_name_t, std::string, boost::property<edge_weight_t, double, boost::property<edge_jspace_t, std::string > > > TMMEdgeProperty;
typedef boost::property<vertex_name_t, std::string> TMMVertexProperty;
typedef boost::adjacency_list<vecS, vecS, directedS, TMMVertexProperty, TMMEdgeProperty > TaskMotionMultigraph;// for task motion multigraph, allowing parallel edges.

typedef graph_traits<TaskMotionMultigraph> Traits;
typedef Traits::vertex_descriptor Vertex;
typedef Traits::edge_descriptor Edge;

//http://stackoverflow.com/questions/589985/vectors-structs-and-stdfind
struct find_equal_edge : std::unary_function<Edge, bool> 
{
  TaskMotionMultigraph g_;
  
  string base_source_name_;
  string base_target_name_;
  string base_name_;
  string base_jspace_;
  
  find_equal_edge(Edge base_e,TaskMotionMultigraph base_g,TaskMotionMultigraph g)
  :g_(g)
  { 
    base_source_name_ = get(vertex_name,base_g,source(base_e,base_g));
    base_target_name_ = get(vertex_name,base_g,target(base_e,base_g));
    base_name_ = get(edge_name,base_g,base_e);
    base_jspace_ = get(edge_jspace,base_g,base_e);
  }
  
  bool operator()(Edge const& e) const 
  {
    string source_name = get(vertex_name,g_,source(e,g_));
    string target_name = get(vertex_name,g_,target(e,g_));
    string name = get(edge_name,g_,e);
    string jspace = get(edge_jspace,g_,e);

//    cout << "source_name= " << source_name << endl;
//    cout << "target_name= " << target_name << endl;
//    cout << "name= " << name << endl;
//    cout << "jspace= " << jspace << endl;
    
//    cout << "base_source_name_= " << base_source_name_ << endl;
//    cout << "source_name= " << source_name << endl;
//    if( !strcmp(source_name.c_str(),base_source_name_.c_str()) )
//      cout << "SAME---------------" << endl;
//    else
//      cout << "NOT SAME---------------" << endl;
      
    return  (
            !strcmp(source_name.c_str(),base_source_name_.c_str())
            and
            !strcmp(target_name.c_str(),base_target_name_.c_str())
            and
            !strcmp(name.c_str(),base_name_.c_str())
            and
            !strcmp(jspace.c_str(),base_jspace_.c_str())
            );
  }
};

int
main()
{
  cout << "hi..." << endl;

  TaskMotionMultigraph g;
 
  Edge edge;
  bool inserted;      
  
  tie(edge, inserted) = add_edge(0,1,g);
  put(vertex_name, g, source(edge,g),"0");
  put(vertex_name, g, target(edge,g),"1");
  put(edge_name,g,edge,"e1a");
  put(edge_jspace,g,edge,"j1a");
  
  tie(edge, inserted) = add_edge(0,1,g);
  put(vertex_name, g, source(edge,g),"0");
  put(vertex_name, g, target(edge,g),"1");
  put(edge_name,g,edge,"e1b");
  put(edge_jspace,g,edge,"j1b");
  
  // CHECK 1
  cout << "num_vertices(g)= " << num_vertices(g) << endl;
  cout << "num_edges(g)= " << num_edges(g) << endl;  
  
  vector<Edge> edge_vec;
  
  graph_traits<TaskMotionMultigraph>::edge_iterator ei,ei_end;
  for(tie(ei,ei_end)=edges(g); ei!=ei_end; ++ei)
  {
    cout << "e(" << source(*ei,g) << "," << target(*ei,g) << ")" << endl;
    edge_vec.push_back(*ei);
  }

  if(edge_vec.at(0) == edge_vec.at(1))
  {
    cout << "equality does not consider property" << endl;
  }
  else
  {
    cout << "equality does _consider_ property" << endl;
  }
  
  vector<Vertex> vertex_vec;
  
  graph_traits<TaskMotionMultigraph>::vertex_iterator vi,vi_end;
  for(tie(vi,vi_end)=vertices(g); vi!=vi_end; ++vi)
  {
    vertex_vec.push_back(*vi);
  }
  
  // CHECK 2
  TaskMotionMultigraph g_2;
  g_2 = g;
  
  cout << "num_vertices(g_2)= " << num_vertices(g_2) << endl;
  cout << "num_edges(g_2)= " << num_edges(g_2) << endl;
    
//  graph_traits<TaskMotionMultigraph>::edge_iterator ei,ei_end;
  for(tie(ei,ei_end)=edges(g_2); ei!=ei_end; ++ei)
  {
    vector<Edge>::iterator it;
    it = find_if(edge_vec.begin(),edge_vec.end(),find_equal_edge(*ei,g_2,g));
    
    if(it != edge_vec.end())
    {
      cout << "same" << endl;
//      cout << "e(" << source(*ei,g_2) << "," << target(*ei,g_2) << ")" << endl;
    }
    else
    {
      cout << "not same" << endl;
    }
  }
  
//  //  graph_traits<TaskMotionMultigraph>::edge_iterator ei,ei_end;
//  for(tie(ei,ei_end)=edges(g_2); ei!=ei_end; ++ei)
//  {
//    graph_traits<TaskMotionMultigraph>::edge_iterator loc_ei,loc_ei_end;
//    for(tie(loc_ei,loc_ei_end)=edges(g); loc_ei!=loc_ei_end; ++loc_ei)
//    {
//      if(*loc_ei == *ei)
//      {
//        cout << "same" << endl;
//        break;
//      }
//    }
//  }
  
////  graph_traits<TaskMotionMultigraph>::vertex_iterator vi,vi_end;
//  for(tie(vi,vi_end)=vertices(g); vi!=vi_end; ++vi)
//  {
//    vector<Vertex>::iterator it;
//    it = find(vertex_vec.begin(),vertex_vec.end(),*vi);
//    
//    if(it != vertex_vec.end())
//    {
//      cout << "same" << endl;
////      cout << "e(" << source(*ei,g_2) << "," << target(*ei,g_2) << ")" << endl;
//    }
//    else
//    {
//      cout << "not same" << endl;
//    }
//  }
  
  return 0;
}
