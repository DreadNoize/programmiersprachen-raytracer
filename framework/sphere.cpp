#define _USE_MATH_DEFINES
#include <math.h>
#include "sphere.hpp"

Sphere::Sphere() :
    center_{ glm::vec3{0.0, 0.0, 0.0} },
    radius_{ 0.0 } 
{}

Sphere::Sphere(double radius) :
    center_{ glm::vec3{0.0, 0.0, 0.0} },
    radius_{ radius } 
{}

Sphere::Sphere(glm::vec3 center, double radius) :
    center_{ center },
    radius_{ radius } 
{}

Sphere::~Sphere() {}

glm::vec3 Sphere::get_center() const {
    return center_;
}

double Sphere::get_radius() const {
    return radius_;
}

double Sphere::area() const {
    return (4*M_PI*pow(radius_,2));
}

double Sphere::volume() const {
    return ((area()*radius_)/3);
}

