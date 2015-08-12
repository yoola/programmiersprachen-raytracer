#ifndef BUW_SDF_LOADER_HPP
#define BUW_SDF_LOADER_HPP

#include "Scene.hpp"

#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdlib>


class SDFLoader{

public:

	SDFLoader();
	SDFLoader(std::string const& filename);
	~SDFLoader();

	std::vector<std::string>& split(std::string const& s, char delim, std::vector<std::string>& elems);
	Scene& load(Scene& scene);

private:

	std::string filename_;
	std::ifstream objects_;
};

#endif