#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"

int main(){
   window w( vector( 128, 64 ), 2 );
   wall top( w, vector(   0,  0 ), vector( 127,  3 ), 2 );
   wall right( w, vector( 124,  0 ), vector( 127, 63 ), 4 );
   wall bottom( w, vector( 0, 60 ), vector(   127, 64 ), 12 );
   wall left( w, vector(   0, 0 ), vector(   3,  64 ), 8 );
   ball b( w, vector( 10, 10 ), 8, vector( 2, 2 ) );
   drawable * objects[] = { &b, &top, &left, &right, &bottom };

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 100 );
      for( auto & p : objects ){
          p->update();
      }
   }
}

