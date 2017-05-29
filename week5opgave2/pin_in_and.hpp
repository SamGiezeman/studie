#include "hwlib.hpp"

/// @file pin_in_and.hpp
/// \brief
/// decorator  pin in get
/// \details
/// contains code for the decorator pin_in_and


/// \brief
/// decorator pin_in_get
/// \details
/// this decorator has code that takes two pin ins and returns true if both are true
class pin_in_and : public hwlib::pin_in{
private:
    hwlib::pin_in &pin1;
    hwlib::pin_in &pin2;
public:
    pin_in_and(
    hwlib::pin_in &pin1,
    hwlib::pin_in &pin2
    ):
    pin1(pin1),
    pin2(pin2)
    {}
    bool get() override{
        return (pin1.get() && pin2.get());
    }
};