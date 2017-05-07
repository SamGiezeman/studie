#include "wall.hpp"

wall::wall( window & w, const vector & start, const vector & end, int update_interval):
    rectangle( w, start, end),
    update_interval(update_interval),
    filled (true)
{}

void wall::draw(){
    if(filled == true){
        for (int a = start.x; a <= end.x; a++){
            for(int b = start.y; b <= end.y; b++){
                w.draw(vector(a,b));
            }
        }
    }
    else{
        left.draw();
        right.draw();
        top.draw();
        bottom.draw();
    }
}

void wall::update(){
if ( update_count >= update_interval) {
    update_count = 1;
    if ( filled ) {
        filled = false;
    }
    else{
        filled = true;
    }
    }
    else update_count++;
}