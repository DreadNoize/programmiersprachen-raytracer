#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


class Shape {
    public:
        virtual ~Shape();

        virtual float area() const = 0;
        virtual float volume() const = 0;

        std::string get_name() const;
        Color get_color() const;

        virtual std::ostream& print(std::ostream& os) const ;

    protected:
        Shape();
        Shape(std::string name, Color farbe);

    private:
        std::string name_;
        Color color_;
};

std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif
