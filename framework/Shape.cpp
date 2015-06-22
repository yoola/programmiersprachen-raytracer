#include <Shape.hpp>

Shape::Shape(): name_(), color_(0,0,0){}
Shape::Shape(std::string const& name, Color const& color) : name_(name), color_(color){}
Shape::~Shape(){}

std::string const& Shape::getname() const{

	return name_;
}

Color const& Shape::getcolor() const{

	return color_;
}

std::ostream& Shape::print(std::ostream& os) const{

	os<<"Name: " << name_;
	os<<"Farbe: "<<color_ ;
	return os;
}

std::ostream& operator <<(std::ostream& os, Shape const& s){

	s.print(os);
	return os;
}
