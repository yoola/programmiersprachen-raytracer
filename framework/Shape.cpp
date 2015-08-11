#include <Shape.hpp>
#include <Material.hpp>

Shape::Shape(): name_(), material_(){

	std::cout<<"Constructor of class Shape. "<<std::endl;
}
Shape::Shape(std::string const& name, Material const& material) : name_(name), material_(material){

	std::cout<<"Constructor of class Shape. "<<std::endl;
}
Shape::~Shape(){

	std::cout<<"Destructor of class Shape. "<<std::endl;
}

std::string const& Shape::getname() const{

	return name_;
}

Material const& Shape::getmaterial() const{

	return material_;
}

std::ostream& Shape::print(std::ostream& os) const{

	os<<"Name: " << name_<<"\n";
	os<<"Farbe: "<<material_ ;
	return os;
}

std::ostream& operator <<(std::ostream& os, Shape const& s){

	s.print(os);
	return os;
}
