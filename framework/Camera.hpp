#ifndef BUW_CAMERA_HPP
#define BUW_CAMERA_HPP

#include <string>
#include <glm/vec3.hpp>


struct Camera{

	Camera(): name_(), fovx_(0), position_(0,0,0), orientation_(0,0,-1){}
	Camera(std::string name, float fovx) : 
		name_(name), fovx_(fovx), position_(0,0,0), orientation_(0,0,-1){}
	~Camera(){}

	std::ostream& printcamera(std::ostream& os) const{

	//Shape::print(os);
	os<<"Name der Kamera: "<<name_<<"\n";
	os<<"Vertikaler Öffnungswinkel: "<<fovx_<<"\n";
	os<<"Position: ("<<position_.x<<","<<position_.y<<","<<position_.z<<")\n";
	os<<"Ausrichtung: ("<<orientation_.x<<","<<orientation_.y<<","<<orientation_.z<<")\n";

	return os;
	}

	friend std::ostream& operator <<(std::ostream& os, Camera const& l){

	l.printcamera(os);
	return os;
	}

	std::string getname(){return name_;};
	std::string name_;
	glm::vec3 position_;
	glm::vec3 orientation_;
	float fovx_; //vertikaler Öffnungswinkel
};



#endif