#define _USE_MATH_DEFINES
#include <math.h>
#include "shape.hpp"

Shape::Shape() : 
    name_( "Shape" ),
	color_{ Color{} }
{}

Shape::Shape(std::string name, Color farbe) :
    name_( name ),
    color_( farbe )
{}

std::string Shape::get_name() const {
    return name_;
}

Color Shape::get_color() const {
    return color_;
}
