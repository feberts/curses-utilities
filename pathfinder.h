#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "graph.h"
#include "position.h"

typedef std::stack<Position> Path;

class Pathfinder : private graph::Graph
{
public:

    Pathfinder(const Distance map_size_v, const Distance map_size_h);
    Pathfinder() = delete;

    void add_node(const Position & pos);
    void add_edge(const Position & first, const Position & second, const Distance dist = 1);
    void add_directed_edge(const Position & src, const Position & dest, const Distance dist = 1);

    Path path(const Position & src, const Position & dest);
    Distance path_length() const;

    typedef std::vector<Position> Positions;
    void ignore_nodes(const Positions & positions);

private:

    const Distance m_map_size_v;
    const Distance m_map_size_h;

    Position to_position(const graph::Node_id id) const;
    graph::Node_id to_id(const Position & pos) const;
};

#endif // PATHFINDER_H
