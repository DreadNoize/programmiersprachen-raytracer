#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include <string>
#include "color.hpp"


class Shape {
    public:
        virtual float area() const = 0;
        virtual float volume() const = 0;

    protected:
        Shape();
        Shape(std::string name, Color farbe);

        std::string get_name() const;
        Color get_color() const;

    private:
        std::string name_;
        Color color_;
};


#endif
