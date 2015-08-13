#include "Sphere.hpp"


#include <glm/gtx/intersect.hpp>
#include <string>

Sphere::Sphere() : Shape(), center_(0,0,0), radius_(0){

	std::cout<<"Constructor of class Sphere. "<<std::endl;
}

Sphere::Sphere(glm::vec3 const& center, double radius, std::string const& name, Material const& material) :
 Shape(name, material),
 center_(center),
 radius_(radius)
{
	std::cout<<"Constructor of class Sphere. "<<std::endl;
}

Sphere::~Sphere(){

	std::cout<<"Destructor of class Sphere. "<<std::endl;
}

glm::vec3 Sphere::getcenter() const{

	return center_;
}

float Sphere::getradius() const{

	return radius_;
}

double Sphere::area() const{

	return 4*pi*radius_*radius_;
}

double Sphere::volume() const{

	return (4/3)*pi*radius_*radius_*radius_;
}

std::ostream& Sphere::print(std::ostream& os) const{

	Shape::print(os);
	os<<"Centre: "<<center_.x<<", " <<center_.y<<", "<<center_.z<<"\n";
	os<<"Radius: "<<radius_<<"\n";
	return os;
}

bool Sphere::intersect(Ray const& r, float& t){

	glm::vec3 norm_d=glm::normalize(r.direction_);

	return glm::intersectRaySphere(
		r.origin_, norm_d,
		center_, radius_*radius_, t);
}

