#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"


class Sphere : public Shape {
    public:
        Sphere();
        Sphere(float radius);
        Sphere(glm::vec3 center, float radius);
        Sphere(glm::vec3 center, float radius, std::string name, Color farbe);
        ~Sphere();

        glm::vec3 get_center() const;
        float get_radius() const;

		float area() const override;
        float volume() const override;

        std::ostream& print(std::ostream& os) const override;

    private:
        glm::vec3 center_;
        float radius_;

};


#endif
