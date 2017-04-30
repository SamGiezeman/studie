/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 1 opdracht 2 (code)
/*--------------------*/

/**
 * @file blackBox.cpp
 * @author Sam Giezeman
 * @brief the  code for a filled in square
 * @date 23 - 04 - 2017
 * Jorn Bunk
 */

#include "blackBox.hpp"

/**
 * @brief prints a filled in rectangle
 * 
 */
void filledRectangle::print(){
    for (int a = start_x; a <= end_x; a++){
        for(int b = start_y; b <= end_y; b++){
            w.draw(a, b);
        }
    }
}