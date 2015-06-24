#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP

#include "Shape.hpp"

#include <glm/vec3.hpp>


class Box : public Shape{

private:
	glm::vec3 min_;
	glm::vec3 max_;

public:
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Color const& color);
	~Box();
	glm::vec3 getmin() const;
	glm::vec3 getmax() const;
	double getlength() const;
	double getwidth() const;
	double getheight() const;
	double area() const override;
	double volume() const override;
	std::ostream& print(std::ostream& os) const override;
	bool intersect(Ray const& r);
};
#endif