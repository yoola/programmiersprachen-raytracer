#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include "Shape.hpp"

#include <glm/vec3.hpp>


class Box : public Shape{

public:
	Box();
	Box(glm::vec3 min, glm::vec3 max);
	~Box();
	glm::vec3 getmin() const;
	glm::vec3 getmax() const;
	double getlength() const;
	double getwidth() const;
	double getheight() const;
	double area() const override;
	double volumen() const override;



private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif BUW_BOX_HPP