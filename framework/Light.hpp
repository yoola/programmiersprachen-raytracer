#ifndef BUW_LIGHT_HPP
#define BUW_LIGHT_HPP

#include "color.hpp"

#include <string>
#include <glm/vec3.hpp>


struct Light{

	Light(std::string name, glm::vec3 position, Color diffuse, Color ambiente):
	 name_(name), position_(position), diffuse_(diffuse), ambiente_(ambiente){}
	Light(): name_(), position_(0,0,0), diffuse_(0,0,0), ambiente_(0,0,0){}
	~Light(){}

	std::string name_;
	glm::vec3 position_;
	Color diffuse_;
	Color ambiente_;
};

#endif