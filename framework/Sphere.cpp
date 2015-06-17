#include "Sphere.hpp"

#include <glm/vec3.hpp>


glm::vec3 Shape::Sphere::getcenter() const{

	return center_;
}

double Shape::Sphere::getradius() const{

	return radius_;
}

double Shape::Sphere::area() const override{

	return 4*pi*radius_*radius_;
}

double Shape::Sphere::volumen() const override{

	return (4/3)*pi*radius_*radius_*radius_;
}
