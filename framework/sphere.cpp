#define _USE_MATH_DEFINES
#include <math.h>
#include "sphere.hpp"

Sphere::Sphere() :
    Shape(),
    center_{ glm::vec3{0.0, 0.0, 0.0} },
    radius_{ 0.0 }
{}

Sphere::Sphere(float radius) :
    Shape(),
    center_{ glm::vec3{0.0, 0.0, 0.0} },
    radius_{ radius }
{}

Sphere::Sphere(glm::vec3 center, float radius) :
    Shape(),
    center_{ center },
    radius_{ radius }
{}

Sphere::Sphere(glm::vec3 center, float radius, std::string name, Color farbe) :
    Shape(name, farbe),
    center_{ center },
    radius_{ radius }
{}

Sphere::~Sphere() {}

glm::vec3 Sphere::get_center() const {
    return center_;
}

float Sphere::get_radius() const {
    return radius_;
}

float Sphere::area() const {
    return (4*M_PI*pow(radius_,2));
}

float Sphere::volume() const {
    return ((area()*radius_)/3);
}

std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os) << center_.x << center_.y << center_.z << radius_;
    return os;
}
