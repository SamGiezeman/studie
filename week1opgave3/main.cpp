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
 * @brief main die twee verschillende boten tekent
 * 
 */
int main(int argc, char **argv){
    window w( 256, 64, 2 );
    giveMeABoat steamship(w, 0, 0, false);
    giveMeABoat titanic(w, 128, 0, true);
    steamship.print();
    titanic.print();
    return 0;
}
