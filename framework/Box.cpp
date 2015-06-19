#include "Box.hpp"
#include <glm/vec3.hpp>
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>

Box::Box() : Shape(), min_(0,0,0), max_(0,0,0){}
Box::Box(glm::vec3 min, glm::vec3 max) : min_(min), max_(max){}
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

	return 2*(length_*height_)+2*(width_*height_)+2*(length_*width_);
}

double Box::volumen() const{

	return length_*width_*height_;	
}
