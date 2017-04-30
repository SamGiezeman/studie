/**
 * @file main.cpp
 * @author Sam Giezeman
 * @brief De main van het huiswerk van week 1
 * @date 23 - 04 - 2017
 * Jorn Bunk
 */

#include <iostream>
#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "blackBox.hpp"
#include "steamship.hpp"


/**
 * @brief main that draws three rectangles
 * 
 */
int main(int argc, char **argv){
    window w( 100, 64, 2 );
    filledRectangle theVoid1(w, 5, 10, 20 ,23);
    filledRectangle theVoid2(w, 20, 30, 30 ,40);
    filledRectangle theVoid3(w, 40, 30, 60 ,50);
    theVoid1.print();
    theVoid2.print();
    theVoid3.print();
    return 0;
}
