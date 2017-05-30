#include "hwlib.hpp"
#include "hwlib-graphics.hpp"

int main( void ){	
    
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   
   namespace target = hwlib::target;
   
   auto scl = target::pin_oc( target::pins::scl );
   auto sda = target::pin_oc( target::pins::sda );
   
   auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   
   auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  
   (void)display;
     
   display.clear();
   
   //------------------------------
   //code tekent een waterput
   
   for(int x = 50; x < 80; x++){
       display.write( hwlib::location( x, 40 ), hwlib::black );
    }
    for(int x = 0; x < 128; x++){
       display.write( hwlib::location( x, 50 ), hwlib::black );
    }
    for(int y = 30; y < 50; y++){
       display.write( hwlib::location( 50, y ), hwlib::black );
    }
    for(int y = 30; y < 50; y++){
       display.write( hwlib::location( 80, y ), hwlib::black );
    }
    for(int y = 30; y < 40; y++){
       display.write( hwlib::location( 66, y ), hwlib::black );
    }
    for(int x = 0; x < 128; x++){
       display.write( hwlib::location( x, 50 ), hwlib::black );
    }
        for(int y = 0; y < 30; y++){
    for(int x = 45; x <66; x++){
                if( ((x-45) + y) > 20 ){
                    display.write( hwlib::location( x, y ), hwlib::black );
            }
        }
    }

    for(int x = 85; x >65; x--){
        for(int y = 0; y < 30; y++){
            if(( x - y) < 65 ){
                display.write( hwlib::location( x, y ), hwlib::black );
            }
        }
    }
}