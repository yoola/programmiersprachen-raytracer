#include "Scene.hpp"

Scene::Scene(): materials_(), shapes_(), light_(), camera_(){};
Scene::Scene(std::vector<Material> materials, std::vector<Shape*> shapes, std::vector<Light> light, Camera camera): 
		materials_(materials), shapes_(shapes), light_(light), camera_(camera){}
Scene::Scene(Scene const& scene) : 
		materials_(scene.materials_), shapes_(scene.shapes_), light_(scene.light_), camera_(scene.camera_){}
Scene::~Scene(){}


void Scene::addmaterial(std::vector<std::string> const& vec){

	materials_.push_back(Material(vec[2], 
		Color(std::stof(vec[3]),std::stof(vec[4]),std::stof(vec[5])), 
		Color(std::stof(vec[6]),std::stof(vec[7]),std::stof(vec[8])), 
		Color(std::stof(vec[9]),std::stof(vec[10]),std::stof(vec[11])),
		std::stof(vec[12])));
}


void Scene::addshape(std::vector<std::string> const& vec){

		if(vec[2] == "box"){

			Material tmp = *(std::find_if(std::begin(materials_), std::end(materials_), 
				[&vec](Material i){return i.getname()== vec[10];}));
			Box* box = new Box(glm::vec3(std::stof(vec[4]),std::stof(vec[5]),std::stof(vec[6])), 
				glm::vec3(std::stof(vec[7]),std::stof(vec[8]),std::stof(vec[9])),vec[3], tmp);
		shapes_.push_back(box);
		}

		else if (vec[2] == "sphere"){

			Material tmp = *(std::find_if(std::begin(materials_), std::end(materials_),
				[&vec](Material i){return i.getname()== vec[10];}));
			Sphere* sphere = new Sphere(glm::vec3(std::stof(vec[4]),std::stof(vec[5]),std::stof(vec[6])),
				std::stof(vec[7]),vec[3], tmp);
		shapes_.push_back(sphere);
	}
}

void Scene::addlight(std::vector<std::string> const& vec){

	light_.push_back(Light(vec[2], glm::vec3(std::stof(vec[3]),std::stof(vec[4]),std::stof(vec[5])), 
		Color(std::stof(vec[6]),std::stof(vec[7]),std::stof(vec[8])), 
		Color(std::stof(vec[9]),std::stof(vec[10]),std::stof(vec[11]))));
}

void Scene::addcamera(std::vector<std::string> const& vec){
	
	Camera(vec[2], std::stof(vec[3]));
}



