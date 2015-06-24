#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP

#include "Shape.hpp"
#include "Ray.hpp"

#include <glm/vec3.hpp>


#define pi 3.14159265359

class Sphere : public Shape{

private:
	glm::vec3 center_;
	float radius_;

public:
	Sphere();
	Sphere(glm::vec3 const& center, double radius, std::string const& name, Color const& color);
	~Sphere();
	glm::vec3 getcenter() const;
	float getradius() const;
	double area() const override;
	double volume() const override;
	std::ostream& print(std::ostream& os) const override;
	bool intersect(Ray const& r);
};

#endif