#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "Shape.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "Ray.hpp"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


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


TEST_CASE("print out object of Sphere", "[print and os method]") {
    
    glm::vec3 center(5,4,1);
    double radius=3;
    Sphere s(center,radius, "Sphere2", Color(0,0,1));
    std::cout<<s<<std::endl;
 }

 TEST_CASE("print out object of Box", "[print and os method]") {
    
    glm::vec3 min(1,1,1);
    glm::vec3 max(2,2,2);
    Box b(min, max, "Box1", Color(0,1,0));
    std::cout<<b<<std::endl;
 }

 TEST_CASE("intersection of Box and Ray", "[intersect_box]")
{
    // Ray
    glm::vec3 ray_origin(0.0,0.0,0.0);
    // ray direction has to be normalized ! // you can use:
    // v = glm::normalize(some_vector) 
    glm::vec3 ray_direction(1.0,1.0,1.0);

    Ray r(ray_origin, ray_direction);

    // Box
    glm::vec3 min(0,0,0);
    glm::vec3 max(1,1,1);
    Box b(min, max, "Box1", Color(0,1,0));


    REQUIRE(b.intersect(r) == 1); 
}

TEST_CASE("intersection of Sphere and Ray", "[intersect_sphere]")
{
    // Ray
    glm::vec3 ray_origin(0.0,0.0,0.0);
    // ray direction has to be normalized ! // you can use:
    // v = glm::normalize(some_vector) 
    glm::vec3 ray_direction(0.0,0.0,1.0);
    Ray r(ray_origin, ray_direction);

    // Sphere
    glm::vec3 sphere_center(0.0,0.0,5.0); 
    float sphere_radius (1.0);
    Sphere s(sphere_center,sphere_radius, "Sphere", Color(1,1,1));

    float distance (0.0);
    auto result = glm::intersectRaySphere(
        ray_origin , ray_direction , 
        sphere_center , sphere_radius , 
        distance );
    REQUIRE(distance == Approx(4.0f)); 
    REQUIRE(s.intersect(r) == 1);
}

TEST_CASE("order of constructor call", "[calling constructors]") {
    
    Color red(255, 0, 0);
    glm::vec3 position(0,0,0);
    Sphere* s1 = new Sphere(position, 1.2, "sphere0", red);
    Shape* s2 = new Sphere(position, 1.2,"sphere1", red);
    s1->print(std::cout); 
    s2->print(std::cout);

    delete s1;
    delete s2;
 }

//Der Zeiger auf ein Objekt einer abgeleiteten Klasse kann überall verwendet werden,
// wo ein Zeiger der Basisklasse verlangt wird.

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
