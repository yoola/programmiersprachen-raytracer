#ifndef BUW_CAMERA_HPP
#define BUW_CAMERA_HPP

#include <string>
#include <glm/vec3.hpp>


struct Camera{

	Camera(): name_(), fovx_(0){}
	Camera(std::string name, float fovx) : name_(name), fovx_(fovx){}
	~Camera(){}

	std::string name_;
	glm::vec3 position_;
	glm::vec3 orientation_;
	float fovx_; //vertikaler Öffnungswinkel
};



#endif