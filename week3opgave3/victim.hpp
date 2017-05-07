/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 3 opdracht 3
/*--------------------*/

#ifndef VICTIM_HPP
#define VICTIM_HPP

/// @file victim.hpp
/// \brief
/// victim data type
/// \details
/// This file contains code to represent a two dimensional wall
///

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "rectangle.hpp"
#include "line.hpp"

/// \brief
/// class victim
/// \details
/// class victim is a variation on rectangle it contains a bool "dissapearing" to mark wether it has overlapped with another object
/// when the bool disappearing is set to true it starts to reduce itself every update cycle
/// it also contains it's own draw function which was included becouse the variables belonging to class "line" are private
class victim : public rectangle{
    private:
    bool disappearing = false;
    public:
    victim( window & w, const vector & start, const vector & end, const vector & size);
    
    /// \brief
    /// interact function
    /// \details
    /// checks for overlapping objects
    void interact( drawable & other ) override;
    
    /// \brief
    /// update function
    /// \details
    /// updates victim (this only happens when "disappearing" is true)
    void update();
    
    /// \brief
    /// draw function
    /// \details
    /// draws victim
    void draw();
};

#endif // VICTIM_HPP