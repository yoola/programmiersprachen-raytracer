#include "Sphere.hpp"

#include <glm/vec3.hpp>

Sphere::Sphere() : Shape(), center_(0,0,0), radius_(0){}
Sphere::Sphere(glm::vec3 center, double radius) : center_(center), radius_(radius){}
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

double Sphere::volumen() const{

	return (4/3)*pi*radius_*radius_*radius_;
}
