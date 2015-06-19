#include "Box.hpp"
#include <glm/vec3.hpp>
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>

glm::vec3 Shape::Box::getmin() const{

	return min_;
}

glm::vec3 Shape::Box::getmax() const{

	return max_;
}

double Shape::Box::getlength() const{

	return abs(min_.x - max_.x);
}

double Shape::Box::getwidth() const{

	return abs(min_.y - max_.y);
}

double Shape::Box::getheight() const{

	return abs(min_.z - max_.z);
}

double Shape::Box::area() const override{

	return 2*(length_*height_)+2*(width_*height_)+2*(length_*width_);
}

double Shape::Box::volumen() const override{

	return length_*width_*height_;	
}
