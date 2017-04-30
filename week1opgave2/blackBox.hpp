/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 1 opdracht 2 (header)
/*--------------------*/

/**
 * @file blackBox.hpp
 * @author Sam Giezeman
 * @brief the header for blackBox.cpp
 * @date 23 - 04 - 2017
 * Jorn Bunk
 */

#ifndef BLACKBOX_HPP
#define BLACKBOX_HPP

#include "window.hpp"

/**
 * @brief this class requires for coordinates to make a square and can print a filled version of it
 * 
 */
class filledRectangle{
    
    private:
    window & w;
    int start_x, start_y, end_x, end_y;
    
    public:
    filledRectangle(window & w, int start_x, int start_y, int end_x, int end_y):
        w(w),
        start_x(start_x),
        start_y(start_y),
        end_x(end_x),
        end_y(end_y)
        {}
    void print();
};

#endif //BLACKBOX_hPP