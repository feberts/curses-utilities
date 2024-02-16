#ifndef POSITION_H
#define POSITION_H

typedef int Distance;

struct Position
{
    Distance v;
    Distance h;

    Position(const Distance v, const Distance h) : v(v), h(h) { }
    Position() = delete;

    bool operator==(const Position & other) const;
    bool operator!=(const Position & other) const;
};

#endif // POSITION_H
