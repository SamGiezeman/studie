#include "vector.hpp"
#include "ostream"

// needed to get Catch working with MinGW
#define TWOBLUECUBES_CATCH_REPORTER_JUNIT_HPP_INCLUDED
namespace Catch{ class JunitReporter{ ~JunitReporter(); }; };

#include "catch_with_main.hpp"


TEST_CASE( "Print a vector" ){
    vector v(3, 4);
    std::stringstream s;
    s << v;
    REQUIRE( s.str() == "(3, 4)" );   
}

TEST_CASE( "add a vector to another vector" ){
    vector v(3, 4);
    vector e(10, 5);
    vector c = v+e;
    REQUIRE( c == vector(13, 9) );   
}

TEST_CASE( "add a vector to another vector with operand +=" ){
    vector v(4, 4);
    vector e(10, 5);
    v+=e;
    REQUIRE( v == vector(14, 9) );
}

TEST_CASE( "multiply a vector with right hand side integer" ){
    vector v(4, 4);
    vector c = v*5;
    REQUIRE( c == vector(20, 20) );
}

TEST_CASE( "multiply a vector with left hand side integer" ){
    vector v(4, 4);
    vector c = 5*v;
    REQUIRE( c == vector(20, 20) );
}

TEST_CASE( "multiply a vector with *= operator" ){
    vector v(4, 4);
    v*=3;
    REQUIRE( v == vector(12, 12) );
}

// Jaspers test cases----------------------------------------------------

TEST_CASE( "Print vector" ){
   vector v( 1, 15 );
   std::stringstream s;
   s << v;
   REQUIRE( s.str() == "(1, 15)" );   
}

TEST_CASE( "Vector + vector" ){
   vector v1( 1, 4 );
   vector v2( 3, 5 );
   vector v3 = v1 + v2;
   REQUIRE( v3 == vector( 4, 9 ) );   
}

TEST_CASE( "Vector += vector" ){
   vector v1( 1, 4 );
   vector v2( 3, 5 );
   v1 += v2;
   REQUIRE( v1 == vector( 4, 9 ) );   
}

TEST_CASE( "Vector * int" ){
   vector v1( 1, 4 );
   vector v2 = v1 * 5;
   REQUIRE( v2 == vector( 5, 20 ) );   
}

TEST_CASE( "int * vector" ){
   vector v1( 1, 4 );
   vector v2 = 5 * v1;
   REQUIRE( v2 == vector( 5, 20 ) );   
}

TEST_CASE( "Vector *= int" ){
   vector v1( 4, 3 );
   v1 *= 2;
   REQUIRE( v1 == vector( 8, 6 ) );   
}