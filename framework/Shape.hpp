#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

#include <glm/glm.hpp>

class Shape{

public:
	Shape();
	~Shape();
	virtual double area() const = 0;
	virtual double volumen() const = 0;
};

#endif BUW_SHAPE_HPP