/*--------------------*/
// Sam Giezeman
// 1675978
// Jorn Bunk
// Week 2 opdracht 3 (header)
/*--------------------*/
#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>


/// @file vector.hpp
/// \brief
/// vector ADT
/// \details
/// This file contains code for an abstract data type representing a vector
///

/// \brief
///  class vector
/// \details
/// this is a class consisting of an X and Y coördinate
class vector{
private:
    int x;
    int y;

public:
    vector(int x,int y):
        x(x),
        y(y)
    {}
    
    /// \brief
    ///  output operator for a vector
    /// \details
    /// the opperator << prints a vector consisting of an x and y coördinate.
    friend std::ostream & operator<<( std::ostream & lhs, const vector & rhs ){
      return lhs 
        << "("
        << rhs.x
        << ", "
        << rhs.y
        << ")";
    }
    
    /// \brief   
    /// compare two vectors
    /// \details
    /// This operator tests for equality. It returns true
    /// if and only if the x and y of both
    /// operands are equal.
    bool operator==( const vector & rhs ) const {
        return ( x == rhs.x ) && ( y == rhs.y );
    }
    
    
    /// \brief
    ///  add two vectors to eachother 
    /// \details
    ///  this operator adds two vectors to eachother using the + operator
    vector operator+(const vector & rhs) const{
        return vector(x+rhs.x, y+rhs.y);
    }
    
    /// \brief
    ///  add two vectors to eachother
    /// \details
    ///  add two vectors to eachother using the += operator and returning itself
    vector & operator+=( const vector & rhs ){
        x = x + rhs.x;
        y = y + rhs.y;
        return *this;
    }
    
    //this is commented becouse I could not find a way to refference the left hand side integer
    //vector operator*( const vector & rhs) const{
    //    return vector(this * rhs.x, this * rhs.y);
    //}
    
    /// \brief
    ///  multiply a vector with an int
    /// \details
    ///  this operator multiplies two vectors to eachother using the + operator
    vector operator*( const int rhs) const{
        return vector(rhs* x, rhs* y);
    }
    
    /// \brief
    ///  multiply a vector with an int
    /// \details
    ///  multiply a vectors to an int using the += operator and returning itself
    vector operator*=(const int & rhs){
        x *= rhs;
        y *= rhs;
        return *this;
    }

};
#endif