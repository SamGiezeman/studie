/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 1 opdracht 3 (code)
/*--------------------*/

/**
 * @file steamship.ccp
 * @author Sam Giezeman
 * @brief The code for drawing a steamship
 * @date 23 - 04 - 2017
 * Jorn Bunk
 */


#include "steamship.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "circle.hpp"


/**
 * @brief giveMe a boat draws a steamship
 *  this function requires 2 starting coordinates (x and y) and a bool to decide wether it needs to print a version with or without clouds
 *  True is given for the version with clouds and a second chimney.
 */
void giveMeABoat::print(){
    line water(w,start_x,start_y+50, start_x+128, start_y+50);
    line boatDeck(w, start_x+10, start_y+40, start_x+100, start_y+40);
    line boatRear(w, start_x+100, start_y+40, start_x+80, start_y+50);
    line boatStern(w, start_x+30, start_y+50, start_x+10, start_y+40);
    rectangle firstChimney(w, start_x+60, start_y+30, start_x+65, start_y+40);
    rectangle secondChimney(w, start_x+70, start_y+33, start_x+75, start_y+40);
    circle cloud0(w, start_x+75, start_y+ 25, 3);
    circle cloud1(w, start_x+81, start_y+ 19, 3);
    circle cloud2(w, start_x+86, start_y+ 14, 2);
    circle cloud3(w, start_x+92, start_y+ 10, 2);
    circle cloud4(w, start_x+98, start_y+ 8, 2);
    
    boatStern.print();
    water.print();
    boatRear.print();
    boatDeck.print();
    secondChimney.print();
    if (clouds){
        firstChimney.print();
        cloud0.print();
        cloud1.print();
        cloud2.print();
        cloud3.print();
        cloud4.print();
    }
}