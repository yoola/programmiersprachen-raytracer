#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "Shape.hpp"

#include <glm/vec3.hpp>


#define pi = 3.14159265359

class Sphere : public Shape{

public:
	Sphere() : center_(), radius_(){}
	Sphere(glm::vec3 center, double radius) : center_(center), radius_(radius){}
	~Sphere(){}
	glm::vec3 getcenter() const;
	double getradius() const;
	double area() const override;
	double volumen() const override;

private:
	glm::vec3 center_;
	double radius_;
};

#end BUW_SPHERE_HPP


