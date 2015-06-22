#include "Box.hpp"
#include <glm/vec3.hpp>
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <string>

Box::Box() : Shape(), min_(0,0,0), max_(0,0,0){}
Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Color const& color) : 
Shape(name, color), min_(min), max_(max){}
Box::~Box(){}

glm::vec3 Box::getmin() const{

	return min_;
}

glm::vec3 Box::getmax() const{

	return max_;
}

double Box::getlength() const{

	return abs(min_.x - max_.x);
}

double Box::getwidth() const{

	return abs(min_.y - max_.y);
}

double Box::getheight() const{

	return abs(min_.z - max_.z);
}

double Box::area() const{

	return 2*(getlength()*getheight())+2*(getwidth()*getheight())+2*(getlength()*getwidth());
}

double Box::volume() const{

	return getlength()*getwidth()*getheight();	
}
