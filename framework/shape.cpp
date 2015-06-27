#define _USE_MATH_DEFINES
#include <math.h>
#include "shape.hpp"

Shape::Shape() : 
    name_( "Shape" ),
	color_{ Color{} }
{
    std::cout << "Shape class constructor \n";
}

Shape::Shape(std::string name, Color farbe) :
    name_( name ),
    color_( farbe )
{
	std::cout << "Shape class constructor \n";
}

Shape::~Shape(){
	std::cout << "Shape class destructor \n";
}

std::string Shape::get_name() const {
    return name_;
}

Color Shape::get_color() const {
    return color_;
}

std::ostream& Shape::print(std::ostream& os) const {
    os << "Name: " << name_ << '\n';
    os << "Color: " << color_ << '\n';
    return os;
}

std::ostream& operator<<(std::ostream& os , Shape const& s)
{
    return s.print(os);
}

