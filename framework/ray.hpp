#ifndef BUW_RAY_HPP
#define BUW_RAY_HPP
#include <glm/vec3.hpp>

struct Ray{
    Ray() : 
        origin_{ glm::vec3{0.0, 0.0, 0.0} },
        direction_{ glm::vec3{0.0, 0.0, 0.0} }
    {}

    Ray(glm::vec3 from, glm::vec3 there) :
        origin_{ from },
        direction_{ there }
    {}

    ~Ray() {}

    glm::vec3 origin_ ;
    glm::vec3 direction_ ;
};


#endif
