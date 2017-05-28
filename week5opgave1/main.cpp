#include "hwlib.hpp"
#include "ledCounter.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   
   auto button1 = hwlib::target::pin_in( hwlib::target::pins::d3 );
   auto button2 = hwlib::target::pin_in( hwlib::target::pins::d2 );
   
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
    
    //creating a mixed port out via bus and direct pins
    auto portout = hwlib::port_out_from_pins(
    led0,
    led1,
    led2,
    led3,
    serialBus.p0,
    serialBus.p1,
    serialBus.p2,
    serialBus.p3);
    
    ledCounter(portout, button1, button2);
    
}
