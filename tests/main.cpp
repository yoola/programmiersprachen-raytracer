#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "Shape.hpp"
#include "Sphere.hpp"
#include "Box.hpp"
#include "Ray.hpp"
#include "Material.hpp"
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


TEST_CASE("Box_Constructor", "[Box_Constructor]") {
    
    Box b1;
    glm::vec3 Null(0,0,0);
    glm::vec3 min(1,2,3);
    glm::vec3 max(4,4,5);

    Color ka(1,0,0);
    Color kd(0,1,0);
    Color ks(1,1,1);
    float m = 3.0f;
    std::string name_material("Plastik");
    Material material(name_material,ka,kd,ks,m);

	Box b2(min,max, "Box1", material);
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

    Box b2(min, max, "Box1", Material());

    REQUIRE( b1.area() == 0);
    REQUIRE( b1.volume() == 0);
    REQUIRE( b2.area() == 6);
    REQUIRE( b2.volume() == 1);
 }

 TEST_CASE("get length, width, height", "[other getters]") {
    
    glm::vec3 min(1,1,1);
    glm::vec3 max(2,2,2);

    Color ka(1,0,0);
    Color kd(0,1,0);
    Color ks(1,1,1);
    float m = 3.0f;
    std::string name_material("Plastik");
    Material material(name_material,ka,kd,ks,m);

    Box b1(min, max, "Box1", material);

    REQUIRE( b1.getlength() == 1);
    REQUIRE( b1.getwidth() == 1);
    REQUIRE( b1.getheight() == 1);
 }

 TEST_CASE("returning area or volume of a Sphere", "[area and volume of a Sphere]") {
    
    Sphere s1;
    glm::vec3 Null(0,0,0);
    glm::vec3 center(1,1,1);
    double radius=2;
    Sphere s2(center,radius, "Sphere2", Material());

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
    
    glm::vec3 Null(0,0,0);
    Box b(Null,Null,"Box1",Material());

    REQUIRE( b.getname() == "Box1");
 }


TEST_CASE("print out object of Sphere", "[print and os method]") {
    
    glm::vec3 center(5,4,1);
    double radius=3;
    Sphere s(center,radius, "Sphere2", Material());
    std::cout<<s<<std::endl;
 }

 TEST_CASE("print out object of Box", "[print and os method]") {
    
    glm::vec3 min(1,1,1);
    glm::vec3 max(2,2,2);
    Box b(min, max, "Box1", Material());
    std::cout<<b<<std::endl;
 }

 TEST_CASE("intersection of Box and Ray", "[intersect_box]")
{
    // Ray
    glm::vec3 ray_origin(0.0,0.0,0.0);
    // ray direction has to be normalized ! // you can use:
    // v = glm::normalize(some_vector) 
    glm::vec3 ray_direction(0.0,0.0,1.0);

    Ray r(ray_origin, ray_direction);

    // Box
    glm::vec3 min(-1,-1,5);
    glm::vec3 max(1,1,4);
    Box b(min, max, "Box1", Material());
    float t = 5.0f;

    auto result = b.intersect(r,t);
    REQUIRE(result == 1); 
    REQUIRE(t == 4.0f); 
}


TEST_CASE("Difference of two vectors", "[minus_vec]"){

    glm::vec3 a(1,2,3);
    glm::vec3 b(2,2,2);
    auto result = minus_vec(a,b);

    REQUIRE(result.x == -1); 
    REQUIRE(result.y ==  0);
    REQUIRE(result.z ==  1);

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
    Sphere s(sphere_center,sphere_radius, "Sphere", Material());

    float t (0.0);
    auto result = glm::intersectRaySphere(
        ray_origin , ray_direction , 
        sphere_center , sphere_radius , 
        t );
    REQUIRE(t == 4.0f); 
    REQUIRE(s.intersect(r,t) == 1);
}

// TEST_CASE("order of constructor call", "[calling constructors]") {
    
//     Color red(255, 0, 0);
//     glm::vec3 position(0,0,0);
//     Sphere* s1 = new Sphere(position, 1.2, "sphere0", red);
//     Shape* s2 = new Sphere(position, 1.2,"sphere1", red);
//     s1->print(std::cout); 
//     s2->print(std::cout);

//     delete s1;
//     delete s2;
//  }

TEST_CASE("print out object of Material", "[print and os method_material]") {

    float m_ = 3.0f;
    
    Material m("Plastik", Color(0,1,0), Color(0,0,1), Color(1,1,1), m_);
    std::cout<<m<<std::endl;
 }

//Der Zeiger auf ein Objekt einer abgeleiteten Klasse kann überall verwendet werden,
// wo ein Zeiger der Basisklasse verlangt wird.

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
