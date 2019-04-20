#include "Config.h"

Config::Config() {

}

Config::Config(const char* file) {
	this->file = file;
	std::ifstream i(file);
	if (i.good()) {
		i >> this->j;
	}
	else {
		std::ofstream o(file);
		o << "{}" << std::endl;
		printf("[INFO] Config file did not exist, created an empty one!");
	}
}

std::string Config::getString(const char* key) {
	return j.at(key).get<std::string>();
}

std::vector<std::string> Config::getStringArray(const char* key) {
	return j.at(key).get<std::vector<std::string>>();
}

void Config::setString(const char* key, const char* value) {
	j[key] = value;
	std::ofstream o(this->file);
	o << j.dump(4) << std::endl;
}

void Config::setStringArray(const char* key, std::vector<std::string> value) {
	j[key] = value;
	std::ofstream o(this->file);
	o << j.dump(4) << std::endl;
}