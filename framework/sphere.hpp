#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"


class Sphere : public Shape {
    public:
        Sphere();
        Sphere(double radius);
        Sphere(glm::vec3 center, double radius);
        ~Sphere();

        glm::vec3 get_center() const;
        double get_radius() const;

		double area() const override;
        double volume() const override;

    private:
        glm::vec3 center_;
        double radius_;

};


#endif
