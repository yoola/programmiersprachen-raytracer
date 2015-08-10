#include "Ray.hpp"

Ray::Ray(): origin_(0,0,0), direction_(0,0,0){}
Ray::Ray(glm::vec3 origin, glm::vec3 direction): origin_(origin), direction_(direction){}
Ray::~Ray(){}


glm::vec3 Ray::getorigin() const{

	return origin_;
};


glm::vec3 Ray::getdirection() const{

	return direction_;
};