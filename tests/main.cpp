#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "Shape.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include <glm/vec3.hpp>


TEST_CASE("Box_Constructor", "[Box_Constructor]") {
    
    Box b1;
    glm::vec3 Null(0,0,0);
    glm::vec3 min(1,2,3);
    glm::vec3 max(4,4,5);
	Box b2(min,max, "Box1", Color(1,1,1));
    REQUIRE( b1.getmin() == Null);
    REQUIRE( b1.getmax() == Null);
    REQUIRE( b2.getmin() == min);
    REQUIRE( b2.getmax() == max);
 }

 TEST_CASE("returning area or volume of a Box", "[area and volume of a Box]") {
    
    Box b1;
    glm::vec3 Null(0,0,0);
    glm::vec3 min(1,1,1);
    glm::vec3 max(2,2,2);
    Box b2(min, max, "Box1", Color(1,1,1));

    REQUIRE( b1.area() == 0);
    REQUIRE( b1.volume() == 0);
    REQUIRE( b2.area() == 6);
    REQUIRE( b2.volume() == 1);
 }

 TEST_CASE("get length, width, height", "[other getters]") {
    
    glm::vec3 min(1,1,1);
    glm::vec3 max(2,2,2);
    Box b1(min, max, "Box1", Color(1,1,1));

    REQUIRE( b1.getlength() == 1);
    REQUIRE( b1.getwidth() == 1);
    REQUIRE( b1.getheight() == 1);
 }

 TEST_CASE("returning area or volume of a Sphere", "[area and volume of a Sphere]") {
    
    Sphere s1;
    glm::vec3 Null(0,0,0);
    glm::vec3 center(1,1,1);
    double radius=2;
    Sphere s2(center,radius, "Sphere2", Color(1,1,1));

    REQUIRE( s1.area() == 0);
    REQUIRE( s1.volume() == 0);
    REQUIRE( s1.getcenter() == Null);
    REQUIRE( s1.getradius() == 0);

    REQUIRE( s2.area() == Approx(50.26548));
    REQUIRE( s2.volume() == Approx(25.13274));
    REQUIRE( s2.getcenter() == center);
    REQUIRE( s2.getradius() == 2);
 }

 TEST_CASE("get name and color of class Shape", "[name and color getters]") {
    
    Color c(0,1,0);
    glm::vec3 Null(0,0,0);
    Box b(Null,Null,"Box1",c);

    REQUIRE( b.getcolor() == c);
    REQUIRE( b.getname() == "Box1");
 }


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
