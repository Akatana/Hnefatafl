#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class Config {
public:
	Config();
	Config(const char* file);
	std::string getString(const char* key);
	int getInt(const char* key);
	float getFloat(const char* key);
	std::vector<std::string> getStringArray(const char* key);
	std::vector<int> getIntArray(const char* key);
	std::vector<float> getFloatArray(const char* key);
	auto test(const char* key);

	void setString(const char* key, const char* value);
	void setInt(const char* key, int value);
	void setFloat(const char* key, float value);
	void setStringArray(const char* key, std::vector<std::string> array);
	void setIntArray(const char* key, std::vector<int> array);
	void setFloatArray(const char* key, std::vector<float> array);

private:
	const char* file;
	json j;
};

#endif