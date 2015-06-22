#include "Sphere.hpp"

#include <glm/vec3.hpp>
#include <string>

Sphere::Sphere() : Shape(), center_(0,0,0), radius_(0){}

Sphere::Sphere(glm::vec3 const& center, double radius, std::string const& name, Color const& color) :
 Shape(name, color),
 center_(center),
 radius_(radius)
{}

Sphere::~Sphere(){}

glm::vec3 Sphere::getcenter() const{

	return center_;
}

double Sphere::getradius() const{

	return radius_;
}

double Sphere::area() const{

	return 4*pi*radius_*radius_;
}

double Sphere::volume() const{

	return (4/3)*pi*radius_*radius_*radius_;
}

