/// @file ledCounter.cpp
/// \brief
/// function ledCounter
/// \details
/// This file contains a function that counts with for LED
///
#include "hwlib.hpp"

/// \brief
/// ledCounter
/// \details
/// this is a functions which takes a port and two inputs and uses this to count from 0 to 4 and back at button presses
/// the number of leds that are on representing the number
void ledCounter(hwlib::port_out& portout, hwlib::pin_in& button1, hwlib::pin_in& button2){
    int x =0;
    portout.set( x );
    while(1){
        if (button1.get() == 1){
            if(x < 15){
                if( x == 7){x = 15;}
                else if( x == 3){x =  7;}
                else if( x == 1){x =  3;}
                else if( x == 0){x =  1;}

                while(button1.get() != 0){
                    hwlib::wait_ms( 500 );
                }
                portout.set(x);

            }
        }
        if (button2.get() == 1){
            if(x > 0){
                if( x == 1){x =  0;}
                else if( x == 3){x =  1;}
                else if( x == 7){x =  3;}
                else if( x == 15){x = 7;}
                while(button2.get() != 0){
                    hwlib::wait_ms( 500 );
                }
                portout.set(x);
            }
        }
        hwlib::wait_ms( 500 );
    }
}