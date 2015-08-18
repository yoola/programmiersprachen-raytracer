#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP

#include "Material.hpp"
#include "Shape.hpp"
#include "Light.hpp"
#include "Camera.hpp"
#include "color.hpp"
#include "Box.hpp"
#include "Sphere.hpp"

#include <string>
#include <vector>


struct Scene{

	Scene();
	Scene(std::vector<Material> materials, std::vector<Shape*> shapes, std::vector<Light> light, Camera camera);
	Scene(Scene const& scene);
	~Scene();

	void addmaterial(std::vector<std::string> const& vec);
	void addshape(std::vector<std::string> const& vec);
	void addlight(std::vector<std::string> const& vec);
	void addcamera(std::vector<std::string> const& vec);


	std::vector<Material> materials_;
	std::vector<Shape*> shapes_;  
	std::vector<Light> light_;
	Camera camera_;	
};

#endif