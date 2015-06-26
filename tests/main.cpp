#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE("test all the spheres!", "[sphere]"){
    Sphere testsphere;
    REQUIRE(Approx(0.0f) == testsphere.get_radius());

    Sphere testsphere2{4.2f};
    REQUIRE(Approx(4.2f) == testsphere2.get_radius());

    Sphere testsphere3{glm::vec3{1.0,1.0,1.0}, 2.5f};
    auto pt = testsphere3.get_center();
    glm::vec3 vrglpt{1.0,1.0,1.0};
	Color black{ 0.0f, 0.0f, 0.0f };
    REQUIRE(vrglpt == pt);
    REQUIRE(Approx(2.5f) == testsphere3.get_radius());
    REQUIRE(Approx(78.54f) == testsphere3.area());
    REQUIRE(Approx(65.45f) == testsphere3.volume());
    REQUIRE(black == testsphere3.get_color());
    REQUIRE("Shape" == testsphere3.get_name());

    Color red{1.0,0.0,0.0};
    std::string name = "Kugel";
    Sphere testsphere4{glm::vec3{1.0,1.0,1.0}, 5.0f, name, Color{1.0,0.0,0.0}};
    REQUIRE(red == testsphere4.get_color());
    REQUIRE("Kugel" == testsphere4.get_name());
}

TEST_CASE("a case to test them all", "[box]"){
    Box testbox;
    glm::vec3 vrglpt{0.0,0.0,0.0};
    REQUIRE(vrglpt == testbox.get_max());
    REQUIRE(vrglpt == testbox.get_min());

    Box testbox2{glm::vec3{0.0,0.0,0.0}, glm::vec3{1.0,1.0,2.0}};
    glm::vec3 vrglpt2{1.0,1.0,2.0};
    Color black{ 0.0f, 0.0f, 0.0f };
    REQUIRE(vrglpt == testbox2.get_min());
    REQUIRE(vrglpt2 == testbox2.get_max());
    REQUIRE(Approx(10.0) == testbox2.area());
    REQUIRE(Approx(2.0) == testbox2.volume());
    REQUIRE(black == testbox2.get_color());
    REQUIRE("Shape" == testbox2.get_name());

	std::string name = "Quader";
    Color green{0.0,1.0,0.0};
    Box testbox3{glm::vec3{1.0,0.0,0.0}, glm::vec3{2.0,1.0,2.0}, name, Color{0.0,1.0,0.0}};
    REQUIRE(green == testbox3.get_color());
    REQUIRE("Quader" == testbox3.get_name());
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
