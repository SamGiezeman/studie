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
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"

/**
 * @brief defines the class steamship
 * it contains lines, rectangles, circles and a window 
 */
class steamship{
    
    private:
    window & w;
    int start_x, start_y;
    bool clouds;
    line  water;
    line boatDeck;
    line boatRear;
    line boatStern;
    rectangle firstChimney;
    rectangle secondChimney;
    circle cloud0;
    circle cloud1;
    circle cloud2;
    circle cloud3;
    circle cloud4;
    public:
    steamship(window & w, int start_x,int start_y, bool clouds): //prints a steam boat with puffy clouds from the second chimney
        w(w),
        start_x(start_x),
        start_y(start_y),
        clouds(clouds),
        water(w,start_x,steamship::start_y+50, steamship::start_x+128, steamship::start_y+50),
        boatDeck(w, steamship::start_x+10, steamship::start_y+40, steamship::start_x+100, steamship::start_y+40),
        boatRear(w, steamship::start_x+100, steamship::start_y+40, steamship::start_x+80, steamship::start_y+50),
        boatStern(w, steamship::start_x+30, steamship::start_y+50, steamship::start_x+10, steamship::start_y+40),
        firstChimney(w, steamship::start_x+60, steamship::start_y+30, steamship::start_x+65, steamship::start_y+40),
        secondChimney(w, steamship::start_x+70, steamship::start_y+33, steamship::start_x+75, steamship::start_y+40),
        cloud0(w, steamship::start_x+75, steamship::start_y+ 25, 3),
        cloud1(w, steamship::start_x+81, steamship::start_y+ 19, 3),
        cloud2(w, steamship::start_x+86, steamship::start_y+ 14, 2),
        cloud3(w, steamship::start_x+92, steamship::start_y+ 10, 2),
        cloud4(w, steamship::start_x+98, steamship::start_y+ 8, 2)
        {}
    void print();
};

#endif //STEAMSHIP_HPP