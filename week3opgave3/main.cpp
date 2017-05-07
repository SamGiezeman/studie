#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"

int main(){
   window w( vector( 128, 64 ), 2 );
   wall top( w, vector(   0,  0 ), vector( 127,  3 ), 1, vector (128, 4), vector (1, -1) );
   wall right( w, vector( 124,  0 ), vector( 127, 63 ), 4, vector (4, 64), vector (-1, 1) );
   wall bottom( w, vector( 0, 60 ), vector(   127, 64 ), 12, vector(128, 4) , vector (1, -1) );
   wall left( w, vector(   0, 0 ), vector(   3,  64 ), 8, vector(4, 64), vector (-1, 1) );
   ball b( w, vector( 15, 15 ), 8, vector( 5, 5 ) );
   victim victim_1(w, vector(30, 30), vector(40, 40), vector (10, 10));
   drawable * objects[] = { &b, &top, &left, &right, &bottom, &victim_1};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 100 );
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         }
      }
    }
}


