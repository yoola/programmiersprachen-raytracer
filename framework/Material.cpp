#include "Material.hpp"

Material::Material(): name_(), ka_(0,0,0), kd_(0,0,0), ks_(0,0,0), m_(0.0f){}
Material::Material(std::string name, Color ka, Color kd, Color ks, float m): name_(name), ka_(ka), kd_(kd), ks_(ks), m_(m){}
Material::~Material(){}


std::string Material::getname() const{

	return name_;
};

Color Material::getka() const{

	return ka_;
};

Color Material::getkd() const{

	return kd_;
};

Color Material::getks() const{

	return ks_;
};

float Material::getm() const{

	return m_;
};

std::ostream& Material::print(std::ostream& os) const{

	//Shape::print(os);
	os<<"Name des Materials: "<<name_<<"\n";
	os<<"Ambiente Reflexion: "<<ka_<<"\n";
	os<<"Diffuse Reflexion: "<<kd_<<"\n";
	os<<"Spiegelnde Reflexion: "<<ks_<<"\n";
	os<<"Exponent der spiegelnden Reflexion: "<<m_<<"\n";
	return os;
}

std::ostream& operator <<(std::ostream& os, Material const& m){

	m.print(os);
	return os;
}





