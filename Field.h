#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <map>
#include <string>
#include "GameManager.h"
#include "Figure.h"
#include "Texture.h"
#include "Config.h"

class Field {
public:
	Field() {}
	Field(GameManager* manager, const char* file);
	std::map<std::vector<int>, std::vector<int>> getMoves();
	void clean();
	void handleEvents();
	void update();
	void render();

private:
	GameManager* manager;
	Texture* fieldTexture;
	Config* config;
	std::vector<Figure> figures;
	std::map<std::vector<int>, std::vector<int>> moves;
	int size;
};

#endif
