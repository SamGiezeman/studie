#include "hwlib.hpp"
#include "ledCounter.cpp"


int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   auto portout= hwlib::port_out_from_pins( led0, led1, led2, led3);
   
   auto button1 = hwlib::target::pin_in( hwlib::target::pins::d3 );
   auto button2 = hwlib::target::pin_in( hwlib::target::pins::d2 );
   
   ledCounter(portout, button1, button2);
}