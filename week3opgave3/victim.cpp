/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 3 opdracht 3
/*--------------------*/

#include "victim.hpp"

victim::victim( window & w, const vector & start, const vector & end, const vector & size):
    rectangle( w, start, end, size )
{}

void victim::interact( drawable & other ){
    if( this != & other){
        if( overlaps( other )){
            disappearing = true;
        }
    }
}

void victim::update() {
    if(disappearing){
        if (size.x > 0 && size.y >0){
            start += vector(1,1);
            end += vector(-1,-1);
            size += vector(-2, -2);
        }
    }
}

void victim::draw() {
    line left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) );
    line right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) );
    line top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) );
    line bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) );
    left.draw();
    right.draw();
    top.draw();
    bottom.draw();
}