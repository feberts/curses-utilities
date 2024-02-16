#include "pathfinder.h"

// #define NDEBUG // uncomment to disable asserts

#include <cassert>
#include <deque>

Pathfinder::Pathfinder(const Distance map_size_v, const Distance map_size_h)
    : m_map_size_v(map_size_v), m_map_size_h(map_size_h)
{
    assert(map_size_v > 0 && map_size_h > 0 && "map size must be > 0");
}

void Pathfinder::add_node(const Position & pos)
{
    assert(pos.v >= 0 && pos.h >= 0
        && pos.v < m_map_size_v && pos.h < m_map_size_h
        && "node cannot be placed outside map");

    Graph::add_node(to_id(pos));
}

void Pathfinder::add_edge(const Position & first, const Position & second, const Distance dist)
{
    Graph::add_edge(to_id(first), to_id(second), dist);
}

void Pathfinder::add_directed_edge(const Position & src, const Position & dest, const Distance dist)
{
    Graph::add_directed_edge(to_id(src), to_id(dest), dist);
}

Path Pathfinder::path(const Position & src, const Position & dest)
{
    graph::Path path = Graph::path(to_id(src), to_id(dest));

    std::deque<Position> steps;

    while(!path.empty())
    {
        steps.push_front(to_position(path.top()));
        path.pop();
    }

    return Path(steps);
}

Distance Pathfinder::path_length() const
{
    return Graph::path_length();
}

void Pathfinder::ignore_nodes(const Positions & positions)
{
    graph::Node_ids ids;

    for(const Position & pos : positions)
    {
        ids.push_back(to_id(pos));
    }

    Graph::ignore_nodes(ids);
}

Position Pathfinder::to_position(const graph::Node_id id) const
{
    return Position(id / m_map_size_h, id % m_map_size_h);
}

graph::Node_id Pathfinder::to_id(const Position & pos) const
{
    return pos.v * m_map_size_h + pos.h;
}
