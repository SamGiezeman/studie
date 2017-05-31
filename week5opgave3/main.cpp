#include "hwlib.hpp"
#include "pin_out_invert.hpp"

//------------------------------------------------------------------------------
//deze code is gekopieerd omdat het niet in hwlib stond maar wel nodig is
class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 4 ];     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( 
      bool v, 
      hwlib::buffering buf = hwlib::buffering::unbuffered  
   ){
      for( auto p  : list ){
          p->set( v );
      }
   }
};
//
//----------------------------------------------------------------------

int main( void ){	
    // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
    auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
    auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
    auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
    
    auto data = hwlib::target::pin_out( hwlib::target::pins::d8 );
    auto latch = hwlib::target::pin_out( hwlib::target::pins::d9 );
    auto clock = hwlib::target::pin_out( hwlib::target::pins::d10 );
    
    //makes a serial bus using hwlib
    auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(
        clock,
        data,
        hwlib::pin_in_dummy
    );
    auto serialBus = hwlib::hc595(
        spi,
        latch);


    auto led0Inverted = pin_out_invert( led0 );
    auto led1Inverted = pin_out_invert( led1 );
    auto led2Inverted = pin_out_invert( led2 );
    auto led3Inverted = pin_out_invert( led3 );
    
    auto invertedLeds = pin_out_all( led0Inverted, led1Inverted, led2Inverted, led3Inverted );
    auto serialBusses = pin_out_all( serialBus.p0, serialBus.p1, serialBus.p2, serialBus.p3 );
    
    auto leds = pin_out_all( serialBusses, invertedLeds );
    
    hwlib::blink( leds );
}