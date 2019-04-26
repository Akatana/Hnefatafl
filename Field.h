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
	//methods
	Field() {}
	Field(GameManager* manager, const char* file, int xPos, int yPos);
	std::map<std::vector<int>, std::vector<int>> getMoves();
	void setPos(int x, int y);
	void clean();
	void handleEvents();
	void update();
	void render();

private:
	//Variables
	GameManager* manager;
	Texture* fieldTexture;
	Config* config;
	std::vector<Figure*> figures;
	Figure* selectedFigure;
	std::map<std::vector<int>, std::vector<int>> moves;
	std::map<std::vector<int>, Figure*> field;
	int size;
	std::array<SDL_Rect,4> availableFields;

	//methods
	void checkAvailableFields();
};

#endif
