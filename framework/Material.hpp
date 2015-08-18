#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP

#include "Ray.hpp"
#include "color.hpp"

#include <glm/vec3.hpp>
#include <string>

class Material{

private:
	std::string name_;
	Color ka_; // ambiente Reflexion
	Color kd_; // diffuse Reflexion
	Color ks_; // spiegelnde Reflexion
	float m_; // Exponent für spiegelnde Reflexion

public:
	Material();
	Material(std::string name, Color ka, Color kd, Color ks, float m);
	~Material();
	std::string getname() const;
	Color getka() const;
	Color getkd() const;
	Color getks() const;
	float getm() const;
	std::ostream& print(std::ostream& os) const;
	friend std::ostream& operator <<(std::ostream& os, Material const& s);
};

	
#endif