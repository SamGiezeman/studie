
/// @file pin_out_invert.hpp
/// \brief
/// decorator pin_out_inverted
/// \details
/// contains  code for the decorator pin_out_invert


/// \brief
/// decorator pin_out_invert
/// \details
/// this decorator has code that inverts the value that normally would be inserted into pin_out
class pin_out_invert : public hwlib::pin_out {
private:
    hwlib::pin_out & slave;
public:
    pin_out_invert( hwlib::pin_out & slave ): 
      slave( slave ){}
    void set(
        bool x,
        hwlib::buffering buf = hwlib::buffering::unbuffered
    )
    override {
        slave.set( ! x );
    }
};