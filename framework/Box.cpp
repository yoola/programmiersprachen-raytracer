#include "Box.hpp"
#include <glm/vec3.hpp>
#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#include <string>
#include <glm/gtx/intersect.hpp>


glm::vec3 minus_vec(glm::vec3 a, glm::vec3 b) {
		return glm::vec3(a.x-b.x, a.y-b.y, a.z-b.z);
}


Box::Box() : Shape(), min_(0,0,0), max_(0,0,0){

	std::cout<<"Constructor of class Box. "<<std::endl;
}
Box::Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Material const& material) : 
Shape(name, material), min_(min), max_(max){

	std::cout<<"Constructor of class Box. "<<std::endl;
}
Box::~Box(){

	std::cout<<"Destructor of class Box. "<<std::endl;
}

glm::vec3 Box::getmin() const{ //per const reference zurückgeben!!!!

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

bool Box::intersect(Ray const& r, float& t){

	glm::vec3 ray = glm::normalize(r.direction_);

	float t1 = (min_.x - r.origin_.x)/ray.x;
	float t2 = (max_.x - r.origin_.x)/ray.x;
	float t3 = (min_.y - r.origin_.x)/ray.y;
	float t4 = (max_.y - r.origin_.x)/ray.y;
	float t5 = (min_.z - r.origin_.x)/ray.z;
	float t6 = (max_.z - r.origin_.x)/ray.z;

	float tmin = std::max(
      std::max(std::min(t1, t2), std::min(t3, t4)),
      std::min(t5, t6)
    );

  	float tmax = std::min(
      std::min(std::max(t1, t2), std::max(t3, t4)),
      std::max(t5, t6)
    );

  // if tmax < 0, ray (line) is intersecting AABB, but whole AABB is behind us
  
  if (tmax < 0) {
    t = tmax;
    return false;
  }

  // if tmin > tmax, ray doesn't intersect AABB
  if (tmin > tmax) {
    t = tmax;
    return false;
  }

  t = tmin;
  return true;
}
	


std::ostream& Box::print(std::ostream& os) const{

	Shape::print(os);
	os<<"Minimum: "<<min_.x<<", " <<min_.y<<", "<<min_.z<<"\n";
	os<<"Maximum: "<<max_.x<<", " <<max_.y<<", "<<max_.z<<"\n";
	return os;
}

