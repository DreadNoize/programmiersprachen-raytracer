#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("test all the spheres!", "[sphere]"){
    Sphere testsphere;
    REQUIRE(Approx(0.0) == testsphere.get_radius());
    Sphere testsphere2{4.2};
    REQUIRE(Approx(4.2) == testsphere2.get_radius());
    Sphere testsphere3{glm::vec3{1.0,1.0,1.0}, 2.5};
    auto pt = testsphere3.get_center();
    glm::vec3 vrglpt{1.0,1.0,1.0};
    REQUIRE(vrglpt == pt);
    REQUIRE(Approx(2.5) == testsphere3.get_radius());
    REQUIRE(Approx(78.54) == testsphere3.area());
    REQUIRE(Approx(65.45) == testsphere3.volume());
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
