#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include <glm/glm.hpp>
#include "color.hpp"
#

class Shape{

private:
	std::string name_;
	Color color_;
	

public:
	Shape();
	Shape(std::string const& name, Color const& color);
	virtual ~Shape();
	std::string const& getname() const;
	Color const& getcolor() const;
	virtual double area() const = 0;
	virtual double volume() const= 0;
	virtual std::ostream& print(std::ostream& os) const; 
};

std::ostream& operator <<(std::ostream& os, Shape const& s);

#endif