// example:
// declaration of a rectangle object that is contains four line objects
/// @file rectangle.hpp
/// \brief
/// rectangle data type
/// \details
/// This file contains code to represent a rectangle
/// it is part of the code provided by school but was edited 


#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include  "line.hpp"

class rectangle : public drawable {
protected:
   vector start;
   vector end;
   line left;
   line right;
   line top;
   line bottom;
public:
   rectangle( window & w, const vector & start, const vector & end );   
   void draw() override;
};


#endif // RECTANGLE_HPP
