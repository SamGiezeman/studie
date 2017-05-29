#include "hwlib.hpp"
#include "pin_in_and.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   auto button1 = hwlib::target::pin_in( hwlib::target::pins::d3 );
   auto button2 = hwlib::target::pin_in( hwlib::target::pins::d2 );
   
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   auto portout= hwlib::port_out_from_pins( led0, led1, led2, led3);
   
   auto andPins= pin_in_and( button1, button2 );
   
   while(1){
       if(andPins.get()){
           portout.set(15);
       }
       else{
           portout.set(0);
       }
       hwlib::wait_ms(100);
   }

}
