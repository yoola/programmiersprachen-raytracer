#include "Box.hpp"
#include <glm/vec3.hpp>

glm::vec3 Shape::Box::getmin() const{

	return min_;
}

double Shape::Box::getmax() const{

	return max_;
}

double Shape::Box::area() const override{

	double d = max - min;

	

	return 4*pi*radius_*radius_;
}

double Shape::Box::volumen() const override{

	return (4/3)*pi*radius_*radius_*radius_;
}
