#include "sdf_loader.hpp"

SDFLoader::SDFLoader(){}
SDFLoader::SDFLoader(std::string const& filename) : filename_(filename) {

  objects_.open (filename_, std::ifstream::in);

  if(!objects_.is_open()){
    std::cout<<"Cannot open file"<<filename_<<"."<<std::endl;
  }
  else{
    std::cout<<"Opened file "<<filename_<<"."<<std::endl;
  }
}

SDFLoader::~SDFLoader(){

  objects_.close();
  std::cout<<"Closed file "<<filename_<<"."<<std::endl;

}


std::vector<std::string>& SDFLoader::split(const std::string &s, char delim, std::vector<std::string> &elems){
  //delim = delimiter bzw. Trennzeichen
 	std::stringstream ss(s);
 	std::string item;

 	while (std::getline(ss, item, delim)) { 
 		if ( !item.empty() )
 			elems.push_back(item);
 	}
 	return elems;
 }

 Scene& SDFLoader::load(Scene& scene) {
  std::string line;
  std::vector<std::string> v;

  while ( getline(objects_, line) ) {
    v = split(line, ' ', v);

    if ( !line.empty() ) {
      if ( v[0] == "define" ) {
        if ( v[1] == "material" ) {
          scene.addmaterial(v);
        } else if ( v[1] == "shape" ) {
          scene.addshape(v);
        } else if ( v[1] == "light" ) {
          scene.addlight(v);
        } else if ( v[1] == "camera" ) {
          scene.addcamera(v);
        }
      }
    }
    v.clear();

  }
  return scene;
}
