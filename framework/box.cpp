#define _USE_MATH_DEFINES
#include <math.h>
#include "box.hpp"


Box::Box() :
    Shape(),
    minimum_{glm::vec3{0.0, 0.0, 0.0}},
    maximum_{glm::vec3{0.0, 0.0, 0.0}}
{}

Box::Box(glm::vec3 min, glm::vec3 max) :
    Shape(),
    minimum_{min},
    maximum_{max}
{}

Box::Box(glm::vec3 min, glm::vec3 max, std::string name, Color farbe) :
    Shape(name, farbe),
    minimum_{min},
    maximum_{max}
{}

Box::~Box() {}


glm::vec3 Box::get_max() const {
    return maximum_;
}
glm::vec3 Box::get_min() const{
    return minimum_;
}


float Box::area() const {
    float a = maximum_.x - minimum_.x;
    float b = maximum_.y - minimum_.y;
    float c = maximum_.z - minimum_.z;
    return (2*(a*b + a*c + b*c));
}

float Box::volume() const {
    float a = maximum_.x - minimum_.x;
    float b = maximum_.y - minimum_.y;
    float c = maximum_.z - minimum_.z;
    return (a*b*c);
}