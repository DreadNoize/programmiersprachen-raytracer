#define _USE_MATH_DEFINES
#include <math.h>
#include "sphere.hpp"

Sphere::Sphere() :
    Shape(),
    center_{ glm::vec3{0.0, 0.0, 0.0} },
    radius_{ 0.0 }
{
    std::cout << "Sphere class constructor \n";
}

Sphere::Sphere(float radius) :
    Shape(),
    center_{ glm::vec3{0.0, 0.0, 0.0} },
    radius_{ radius }
{
    std::cout << "Sphere class constructor \n";
}

Sphere::Sphere(glm::vec3 center, float radius) :
    Shape(),
    center_{ center },
    radius_{ radius }
{
	std::cout << "Sphere class constructor  \n";
}

Sphere::Sphere(glm::vec3 center, float radius, std::string name, Color farbe) :
    Shape(name, farbe),
    center_{ center },
    radius_{ radius }
{
	std::cout << "Sphere class constructor  \n";
}

Sphere::~Sphere() {
	std::cout << "Sphere class destructor \n";
}

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
    Shape::print(os) << "Center: (" << center_.x << ", " << center_.y << ", " << center_.z << ")" << '\n' << "Radius: " << radius_ << '\n' << "Area: " << area() << '\n' << "Volume: " << volume() << '\n' << '\n';
    return os;
}

bool Sphere::intersect(Ray const& r, float& distance) const {
    return glm::intersectRaySphere(r.origin_, glm::normalize(r.direction_), center_, radius_, distance);
}
