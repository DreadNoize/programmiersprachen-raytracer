#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"


TEST_CASE("test all the spheres!", "[sphere]"){
    using namespace std;
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
    cout << testsphere4 << endl;
}

TEST_CASE("a case to test them all", "[box]"){
    using namespace std;
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
    cout << testbox3 << endl;
}

TEST_CASE("intersectRaySphere", "[intersect]"){
    // Ray
    glm::vec3 ray_origin(0.0, 0.0, 0.0);
    // ray direction has to be normalized !
    // you can use :
    // v = glm::normalize( some_vector )
    glm::vec3 ray_direction(0.0, 0.0, 1.0);
    // Sphere
    glm::vec3 sphere_center(0.0, 0.0, 5.0);
    float sphere_radius(1.0);
    float distance(0.0);
    auto result = glm::intersectRaySphere(ray_origin, ray_direction, sphere_center, sphere_radius, distance);
    REQUIRE ( distance == Approx (4.0f));
}

TEST_CASE("intersect", "[intersect]"){
    Ray strahl{glm::vec3{0.0,0.0,0.0}, glm::vec3{1.0,0.0,0.0}};
    float distance(0.0);
    std::string name = "Peter";
    Sphere testsphere{glm::vec3{0.0,0.0,0.0}, 2.3f, name, Color{1.0,0.0,0.0}};
    REQUIRE(testsphere.intersect(strahl, distance));
    std::cout << testsphere;
}

TEST_CASE("constructor and destructor", "[constructordestructor]"){
    Color red (255, 0, 0);
    glm::vec3 position(0.0, 0.0, 0.0);
    Sphere* s1 = new Sphere( position , 1.2 , "sphere0" , red);
    Shape* s2 = new Sphere( position , 1.2 , "sphere1" , red);
    s1->print(std::cout );
    s2->print(std::cout );
    delete s1;
    delete s2;
    /* Mit viuellem Destruktor:
    Sphere class destructor
    Shape class destructor
    Sphere class destructor
    Shape class destructor*/
    // Der dynamische Datentyp von s2 ist Sphere. Ist der Shape destructor deshalb virtuell, wird der Sphere destructor aufgerufen.
    /*Mit normalem Destructor:
    Sphere class destructor
    Shape class destructor
    Shape class destructor*/
    // Der destructor ist nicht mehr virtuell. Somit wird der destructor des statischen Datentyps (Shape) aufgerufen
}



int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
