#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

#include "Shape.hpp"
#include "Sphere.hpp"
#include "Box.hpp"


TEST_CASE("Box_Constructor", "[Box_Constructor]") {
    
    Box b1;
	//Box b2(1,2,3);
	b1.getmin();
	b1.getmax();

    REQUIRE( min_.x == 0);
    REQUIRE( min_.y == 0);
    REQUIRE( min_.z == 0);
 }

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
