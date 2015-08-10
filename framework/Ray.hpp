#ifndef BUW_RAY_HPP
#define BUW_RAY_HPP

#include <glm/vec3.hpp>

struct Ray{

	Ray();
	Ray(glm::vec3 origin, glm::vec3 direction);
	~Ray();
	glm::vec3 origin_;
	glm::vec3 direction_;
	glm::vec3 getorigin() const;
	glm::vec3 getdirection() const;
};

#endif