#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "Shape.hpp"

#include <glm/vec3.hpp>


#define pi 3.14159265359

class Sphere : public Shape{

public:
	Sphere();
	Sphere(glm::vec3 const& center, double radius, std::string const& name, Color const& color);
	~Sphere();
	glm::vec3 getcenter() const;
	double getradius() const;
	double area() const override;
	double volume() const override;
	//std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 center_;
	double radius_;
};

#endif