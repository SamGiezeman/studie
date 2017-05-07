#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include "window.hpp"
#include "vector.hpp"

/// \brief
/// class drawable
/// \details
/// class drawable is now updated from the template provided for this assignment to: include the bool overlaps> (to check wether two objects are overlapping)
/// it also contains the (virtual) interact which makes a ball interact with other objects.
class drawable {
protected:
   window w;
   vector location;
   vector size;
public:
   drawable( window & w, const vector & location, const vector & size = vector(1,1) , const vector & bounce = vector(1,1));
   vector bounce;
   virtual void draw() = 0;
   virtual void update(){}
   
   bool overlaps( const drawable & other );
   virtual void interact( drawable & other ){}
};

#endif // DRAWABLE_HPP