#include "aStarSearch.h"

AStarSearch::AStarSearch(MyGraph * _myGraph):
m_myGraph(_myGraph)
{

}

AStarSearch::~AStarSearch()
{

}

bool AStarSearch::findPath(MyGraph::VertexId _startMyGraphVertextId, 
double _startX, double _startZ, double _goalX, double _goalZ, double 
_epsilon)
{
    m_SearchGraph searchGraph;

    m_Heuristic heuristic(searchGraph, _goalX, _goalZ);

    m_Visitor visitor(m_myGraph, searchGraph, _goalX, _goalZ, _epsilon);

    //typedef property maps
    typedef property_map<m_SearchGraph, vertex_index_t>::type IndexMap;
    typedef property_map<m_SearchGraph, double m_Edge::*>::type WeightMap;
    typedef property_map<m_SearchGraph, int m_Vertex::*>::type 
PredecessorMap;
    typedef property_map<m_SearchGraph, double m_Vertex::*>::type 
DistanceMap;
    typedef property_map<m_SearchGraph, double m_Vertex::*>::type CostMap;
    typedef property_map<m_SearchGraph, default_color_type 
m_Vertex::*>::type ColorMap;

    //create property maps
    IndexMap indexMap = get(vertex_index, searchGraph);
    WeightMap weightMap = get(&m_Edge::weight, searchGraph);
    PredecessorMap predecessorMap = get(&m_Vertex::prevVertexId, 
searchGraph);
    DistanceMap distanceMap = get(&m_Vertex::distance, searchGraph);
    CostMap costMap = get(&m_Vertex::cost, searchGraph);
    ColorMap colorMap = get(&m_Vertex::color, searchGraph);

    double inf = numeric_limits<double>::max 
BOOST_PREVENT_MACRO_SUBSTITUTION ();
    double zero = double();

    //add & init first vertex
    m_VertexId startVertexId = add_vertex(searchGraph);
    m_Vertex & startVertex = searchGraph[startVertexId];
    startVertex.currX = _startX;
    startVertex.currZ = _startZ;
    startVertex.refMyGraphVertexId = _startMyGraphVertextId;
    startVertex.prevVertexId = startVertexId;
    startVertex.distance = zero;
    startVertex.cost = heuristic(startVertexId);

    try
    {
        astar_search_no_init(searchGraph,
                             startVertexId,
                             heuristic,
                             visitor,
                             predecessorMap,
                             costMap,
                             distanceMap,
                             weightMap,
                             colorMap,
                             indexMap,
                             std::less<double>(),
                             std::plus<double>(),
                             inf,
                             zero);
    }
    catch(m_endSearch end)
    {
        m_printSearchGraph(searchGraph);
        m_printShortestPath(searchGraph);
        m_printAllPaths(searchGraph);
        return true;
    }

    return false;
}

AStarSearch::m_Heuristic::m_Heuristic(m_SearchGraph & _searchGraph, 
double _goalX, double _goalZ):
m_searchGraph(_searchGraph),
m_goalX(_goalX),
m_goalZ(_goalZ)
{

}

AStarSearch::m_Heuristic::~m_Heuristic()
{

}

double AStarSearch::m_Heuristic::operator()(m_VertexId _currVertexId)
{
    m_Vertex currVertex = m_searchGraph[_currVertexId];

    return sqrt(pow(m_goalX - currVertex.currX, 2) + pow(m_goalZ - 
currVertex.currZ, 2)); //for A* search
    //return 0; //for BFS search
}

AStarSearch::m_Visitor::m_Visitor(MyGraph * _myGraph, m_SearchGraph & 
_searchGraph, double _goalX, double _goalZ, double _epsilon):
m_myGraph(_myGraph),
m_searchGraph(_searchGraph),
m_goalX(_goalX),
m_goalZ(_goalZ),
m_epsilon(_epsilon)
{

}

AStarSearch::m_Visitor::~m_Visitor()
{

}

void AStarSearch::m_Visitor::examine_vertex(m_VertexId _currVertexId, 
const m_SearchGraph & _graph)
{
    //get currVertex / currX / currZ
    m_Vertex currVertex = m_searchGraph[_currVertexId];
    double currX = currVertex.currX;
    double currZ = currVertex.currZ;

    //check if goal is reached
    if(sqrt(pow(m_goalX - currX, 2) + pow(m_goalZ - currZ, 2)) < m_epsilon)
    {
        set_property(m_searchGraph, graph_name, _currVertexId); 
//_currVertexId == goal vertex id
        throw m_endSearch();
    }

    //declare currMyGraphVertexId / nextMyGraphVertexId / 
currMyGraphEdgeId / currMyGraphEdge
    MyGraph::VertexId currMyGraphVertexId = currVertex.refMyGraphVertexId;
    MyGraph::VertexId nextMyGraphVertexId;
    MyGraph::EdgeId currMyGraphEdgeId;
    bool currMyGraphEdgeExists;
    MyGraph::Edge currMyGraphEdge;

    //declare newVertexId / newEdgeId / newEdge
    m_VertexId newVertexId;
    m_EdgeId newEdgeId;
    bool newEdgeCreated;

    //generate neighbors to currVertex
    MyGraph::OutEdgeIt outMyGraph_i, outMyGraph_end;
    for(tie(outMyGraph_i, outMyGraph_end) = 
out_edges(currMyGraphVertexId, *m_myGraph); outMyGraph_i != 
outMyGraph_end ; ++outMyGraph_i)
    {
        //get nexMyGraphVertexId / currMyGraphEdgeId / currMyGraphEdge
        nextMyGraphVertexId = target(*outMyGraph_i, *m_myGraph);
        tie(currMyGraphEdgeId, currMyGraphEdgeExists) = 
edge(currMyGraphVertexId, nextMyGraphVertexId, *m_myGraph);
        if(currMyGraphEdgeExists) currMyGraphEdge = 
(*m_myGraph)[currMyGraphEdgeId];
        else exit(1);

        //add/set newVertex
        newVertexId = add_vertex(m_searchGraph);
        m_Vertex & newVertex = m_searchGraph[newVertexId];
        newVertex.currX = currX + 1; //to change
        newVertex.currZ = currZ + 1; //to change

        newVertex.refMyGraphVertexId = nextMyGraphVertexId;
        newVertex.prevVertexId = newVertexId;

        //add/set newEdge
        tie(newEdgeId, newEdgeCreated) = add_edge(_currVertexId, 
newVertexId, m_searchGraph);
        if(newEdgeCreated)
        {
            m_Edge & newEdge = m_searchGraph[newEdgeId];
            newEdge.weight = sqrt(2); //to change
        }
        else exit(1);
    }
}

void AStarSearch::m_printSearchGraph(m_SearchGraph & _searchGraph)
{
    m_Vertex currVertex;
    m_VertexIt v_i, v_end;

    printf("id\t");
    printf("id prev\t");
    printf("id ref\t");
    printf("dist\t");
    printf("cost\t\t");
    printf("color\t");
    printf("\n");

    for(tie(v_i, v_end) = vertices(_searchGraph); v_i != v_end; ++v_i)
    {
        currVertex = _searchGraph[*v_i];
        printf("%i\t", *v_i);
        printf("%i\t", currVertex.prevVertexId);
        printf("%i\t", currVertex.refMyGraphVertexId);
        printf("%f\t", currVertex.distance);
        printf("%f\t", currVertex.cost);
        printf("%i\t", currVertex.color);
        printf("\n");
    }
    printf("\n");
}

list<int> AStarSearch::m_getPath(m_SearchGraph & _searchGraph, 
m_VertexId _vertexId)
{
    list<int> path;

    for(m_VertexId currVertexId = _vertexId;
        ; //cf if()... break; below for stopping condition
        currVertexId = _searchGraph[currVertexId].prevVertexId)
    {
        path.push_front(currVertexId);
        if(_searchGraph[currVertexId].prevVertexId == int(currVertexId))
            break;
    }

    return path;
}

vector< list<int> > AStarSearch::m_getAllPaths(m_SearchGraph & _searchGraph)
{
    m_VertexIt v_i, v_begin, v_end;

    for(tie(v_i, v_end) = vertices(_searchGraph); v_i != v_end; ++v_i)
    {
        _searchGraph[*v_i].color = white_color;
    }

    vector< list<int> > allPaths;
    tie(v_begin, v_i) = vertices(_searchGraph);
    for(--v_i;; --v_i)
    {
        //printf("curr vertex %i\tcolor:%i\n", *v_i, 
_searchGraph[*v_i].color);
        if(_searchGraph[*v_i].color == white_color)
        {
            list<int> newPath = m_getPath(_searchGraph, *v_i);

            list<int>::iterator currVertex;
            for(currVertex = newPath.begin(); currVertex != 
newPath.end(); ++currVertex)
            {
                _searchGraph[*currVertex].color = black_color;
            }

            allPaths.push_back(newPath);
        }

        if(v_i == v_begin)
            break;
    }

    return allPaths;
}

void AStarSearch::m_printPath(list<int> _path)
{
    list<int>::iterator pathIt;
    for(pathIt = _path.begin(); pathIt != _path.end(); ++pathIt)
    {
        printf("%i\t", *pathIt);
    }
    printf("\n");
}

void AStarSearch::m_printShortestPath(m_SearchGraph & _searchGraph)
{
    printf("shortest path:\n");
    m_printPath(m_getPath(_searchGraph, get_property(_searchGraph, 
graph_name)));
}

void AStarSearch::m_printAllPaths(m_SearchGraph & _searchGraph)
{
    vector< list<int> > allPaths = m_getAllPaths(_searchGraph);

    printf("all paths:\n");
    vector< list<int> >::iterator currPath;
    for(currPath = allPaths.begin(); currPath != allPaths.end(); ++currPath)
    {
        m_printPath(*currPath);
    }
}
