#include "hwlib.hpp"

/// \brief
/// main
/// \details
/// this main contains code that lets 2 LED's light up and go on and of again between 4 LED's
/// 
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   
    led0.set( 1 );
    led1.set( 1 );
    hwlib::wait_ms( 300 );
    while(1){
        led0.set( 0 ); led2.set ( 1 ); hwlib::wait_ms( 300 );
        led1.set( 0 ); led3.set ( 1 ); hwlib::wait_ms( 300 );
        led1.set( 1 ); led3.set ( 0 ); hwlib::wait_ms( 300 );
        led0.set( 1 ); led2.set ( 0 ); hwlib::wait_ms( 300 );
    }
}