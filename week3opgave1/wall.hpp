/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 3 opdracht 1
/*--------------------*/

#ifndef WALL_HPP
#define WALL_HPP

/// @file wall.hpp
/// \brief
/// wall data type
/// \details
/// This file contains code to represent a two dimensional wall
///

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "rectangle.hpp"

/// \brief
/// class wall
/// \details
/// class wall is a class based on rectangle.
/// when a wall is defined it gets an interval where you can decide ater how many times update is called it will switch the bool filled
/// it has it's own "draw" function which uses "filled" to decide wether it is a filled wall or an empty one
/// it has it's own "update" function which checks wether or not to toggle between the values in bool filled
class wall : public rectangle{
    private:
    int update_interval;
    int update_count = 1;
    bool filled;
    public:
    wall( window & w, const vector & start, const vector & end, const int update_interval);
    void draw() override;
    void update();
};

#endif // WALL_HPP