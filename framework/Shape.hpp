#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include "Material.hpp"
#include "Ray.hpp"

#include <glm/glm.hpp>
#include <string>


class Shape{

private:
	std::string name_;
	Material material_;
	

public:
	Shape();
	Shape(std::string const& name, Material const& material);
	virtual ~Shape();
	std::string const& getname() const;
	Material const& getmaterial() const;
	virtual double area() const = 0;
	virtual double volume() const= 0;
	virtual std::ostream& print(std::ostream& os) const; 
	virtual bool intersect(Ray const& ray, float& t) = 0;
};

std::ostream& operator <<(std::ostream& os, Shape const& s);

#endif