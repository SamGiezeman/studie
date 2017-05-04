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
void steamship::print(){
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