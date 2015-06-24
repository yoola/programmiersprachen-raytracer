#include <Shape.hpp>

Shape::Shape(): name_(), color_(0,0,0){

	std::cout<<"Constructor of class Shape. "<<std::endl;
}
Shape::Shape(std::string const& name, Color const& color) : name_(name), color_(color){

	std::cout<<"Constructor of class Shape. "<<std::endl;
}
Shape::~Shape(){

	std::cout<<"Destructor of class Shape. "<<std::endl;
}

std::string const& Shape::getname() const{

	return name_;
}

Color const& Shape::getcolor() const{

	return color_;
}

std::ostream& Shape::print(std::ostream& os) const{

	os<<"Name: " << name_<<"\n";
	os<<"Farbe: "<<color_ ;
	return os;
}

std::ostream& operator <<(std::ostream& os, Shape const& s){

	s.print(os);
	return os;
}
