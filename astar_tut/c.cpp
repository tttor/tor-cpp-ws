#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/copy.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/grid_graph.hpp>
#include <boost/property_map/property_map.hpp>

struct vertex_position_t {
    typedef boost::vertex_property_tag kind;
};

struct Position {
    std::size_t x, y;

    Position()
        : x(0), y(0)
    {
    }
};

typedef boost::property<boost::vertex_index_t, std::size_t, boost::property<vertex_position_t, Position> > VertexProperties;
typedef boost::adjacency_list<boost::vecS, boost::listS, boost::undirectedS, VertexProperties> Graph;
typedef boost::graph_traits<Graph> GraphTraits;

namespace detail {
typedef boost::grid_graph<2> Grid;
typedef boost::graph_traits<Grid> GridTraits;

struct grid_to_graph_vertex_copier {
    typedef boost::property_map< Grid, boost::vertex_index_t>::type grid_vertex_index_map;
    typedef boost::property_map< ::Graph, boost::vertex_index_t>::type graph_vertex_index_map;
    typedef boost::property_map< ::Graph, ::vertex_position_t>::type graph_vertex_position_map;

    const Grid& grid;
    grid_vertex_index_map grid_vertex_index;
    graph_vertex_index_map graph_vertex_index;
    graph_vertex_position_map graph_vertex_position;

    grid_to_graph_vertex_copier(const Grid& grid_, Graph& graph)
        : grid(grid_), grid_vertex_index(get(boost::vertex_index_t(), grid_)),
        graph_vertex_index(get(boost::vertex_index_t(), graph)),
        graph_vertex_position(get(::vertex_position_t(), graph))
    {
    }

private:
    Position grid_vertex_index_to_position(std::size_t idx) const {
        unsigned num_dims = grid.dimensions();
        assert(grid.dimensions() == 2);

        idx %= grid.length(0) * grid.length(1);

        Position ret;
        ret.x = idx % grid.length(0);
        ret.y = idx / grid.length(0);

        return ret;
    }

public:
    void operator()(GridTraits::vertex_descriptor grid_vertex, ::GraphTraits::vertex_descriptor graph_vertex) const {
        std::size_t idx = get(grid_vertex_index, grid_vertex);
        put(graph_vertex_index, graph_vertex, idx);
        Position pos = grid_vertex_index_to_position(idx);
        std::cout << "grid_vertex = " << idx << ", pos.x = " << pos.x << ", pos.y = " << pos.y << std::endl;
        put(graph_vertex_position, graph_vertex, pos);
    }
};

struct grid_to_graph_edge_copier {
    void operator()(GridTraits::edge_descriptor grid_edge, ::GraphTraits::edge_descriptor graph_edge) const {
    }
};
}

int main()
{
    boost::array<std::size_t, 2> lengths = { { 3, 5 } };
    detail::Grid grid(lengths);

    Graph graph;

    boost::copy_graph(grid, graph, boost::vertex_copy(detail::grid_to_graph_vertex_copier(grid, graph))
            .edge_copy(detail::grid_to_graph_edge_copier()));

    std::cout << std::endl;
    boost::write_graphviz(std::cout, graph);

    return EXIT_SUCCESS;
}
