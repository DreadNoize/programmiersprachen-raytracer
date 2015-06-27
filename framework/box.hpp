#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include <glm/vec3.hpp>
#include "shape.hpp"
#include "ray.hpp"


class Box : public Shape {
    public:
        Box();
        Box(glm::vec3 min, glm::vec3 max);
        Box(glm::vec3 min, glm::vec3 max, std::string name, Color farbe);
        ~Box();

        glm::vec3 get_max() const;
        glm::vec3 get_min() const;

        /*virtual*/ float area() const override;
        /*virtual*/ float volume() const override;

        std::ostream& print(std::ostream& os) const override;
        

    private:
        glm::vec3 minimum_;
        glm::vec3 maximum_;

};


#endif
