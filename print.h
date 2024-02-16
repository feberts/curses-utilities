#ifndef PRINT_H
#define PRINT_H

#include "position.h"
#include <string>

void print(const Distance v, const Distance h, const char c);
void print(const Distance v, const Distance h, const std::string & str);
void print(const Position & pos, const char c);
void print(const Position & pos, const std::string & str);

void print2d(const Distance v, const Distance h, const std::string & str);
void print2d(const Position & pos, const std::string & str);

std::string stretch(const std::string & str);

Position click_position(const Distance clicked_v, const Distance clicked_h);
void get_window_size(Distance & size_v, Distance & size_h);

#endif // PRINT_H
