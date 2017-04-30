/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 1 opdracht 3 (header)
/*--------------------*/

/**
 * @file steamschip.hpp
 * @author Sam Giezeman
 * @brief De main van het huiswerk van week 1
 * @date 23 - 04 - 2017
 * Jorn Bunk
 */

#ifndef STEAMSHIP_HPP
#define STEAMSHIP_HPP

#include "window.hpp"

/**
 * @brief defines the class giveMeABoat
 * (wether it is a ship or a boat i actually don't know.)
 */
class giveMeABoat{
    
    private:
    window & w;
    int start_x, start_y;
    bool clouds;
    public:
    giveMeABoat(window & w, int start_x,int start_y, bool clouds): //prints a steam boat with puffy clouds from the second chimney
        w(w),
        start_x(start_x),
        start_y(start_y),
        clouds(clouds)
        {}
    void print();
};

#endif //STEAMSHIP_HPP