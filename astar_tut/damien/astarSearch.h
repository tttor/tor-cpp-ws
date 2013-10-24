#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H

#include <boost/graph/astar_search.hpp>

#include "myGraph.h"

class AStarSearch
{
public:

    AStarSearch(MyGraph * _myGraph);
    virtual ~AStarSearch();

    bool findPath(MyGraph::VertexId _startMyGraphVertextId, double 
_startX, double _startZ, double _goalX, double _goalZ, double _epsilon);

private:

    //search graph
    struct m_Vertex
    {
        m_Vertex()
        {
            currX = 0.0;
            currZ = 0.0;
            refMyGraphVertexId = -1;
            prevVertexId = -1;
            double inf = numeric_limits<double>::max 
BOOST_PREVENT_MACRO_SUBSTITUTION ();
            distance = inf;
            cost = inf;
            color = white_color;
        }

        //properties for heuristic / visitor
        double currX;
        double currZ;
        int refMyGraphVertexId; //reference to correspondant vertex in 
myGraph

        //properties required by astar_search_no_init(...)
        int prevVertexId; // == predecessor
        double distance;
        double cost;
        default_color_type color;
    };

    struct m_Edge
    {
        m_Edge()
        {
            weight = 0.0;
        }

        double weight;
    };

    //graph property = save the vertex id when goal is reached
    //saving goal vertex could be also saved by a reference to an int 
passed to the visitor class
    typedef property<graph_name_t, int> m_GraphProperty;

    typedef adjacency_list<vecS, vecS, directedS, m_Vertex, m_Edge, 
m_GraphProperty> m_SearchGraph;

    typedef graph_traits<m_SearchGraph>::vertex_descriptor    m_VertexId;
    typedef graph_traits<m_SearchGraph>::edge_descriptor    m_EdgeId;

    typedef graph_traits<m_SearchGraph>::vertex_iterator    m_VertexIt;
    typedef graph_traits<m_SearchGraph>::adjacency_iterator    
m_AdjacencyIt;
    typedef graph_traits<m_SearchGraph>::edge_iterator        m_EdgeIt;
    typedef graph_traits<m_SearchGraph>::out_edge_iterator    m_OutEdgeIt;

    //heuristic
    class m_Heuristic : public astar_heuristic<m_SearchGraph, double>
    {
    public:

        m_Heuristic(m_SearchGraph & _searchGraph, double _goalX, double 
_goalZ);
        virtual ~m_Heuristic();

        double operator()(m_VertexId _currVertexId);

    private:

        m_SearchGraph & m_searchGraph;
        double m_goalX;
        double m_goalZ;
    };

    //exception to end search
    struct m_endSearch{};

    //visitor
    class m_Visitor : public default_astar_visitor
    {
        public:

            m_Visitor(MyGraph * _myGraph,
                      m_SearchGraph & _searchGraph,
                      double _goalX, double _goalZ,
                      double _epsilon);
            virtual ~m_Visitor();

            void examine_vertex(m_VertexId _currVertexId, const 
m_SearchGraph & _graph);

        private:

            MyGraph * m_myGraph;
            m_SearchGraph & m_searchGraph;
            double m_goalX;
            double m_goalZ;
            double m_epsilon;
    };

    void m_printSearchGraph(m_SearchGraph & _searchGraph);

    list<int> m_getPath(m_SearchGraph & _searchGraph, m_VertexId _vertexId);
    vector< list<int> > m_getAllPaths(m_SearchGraph & _searchGraph);
    void m_printPath(list<int> _path);

    void m_printShortestPath(m_SearchGraph & _searchGraph);
    void m_printAllPaths(m_SearchGraph & _searchGraph);

    MyGraph * m_myGraph;
};

#endif
