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
	void setPos(int x, int y);
	bool isFinished() { return this->finish;  }
	int getCurrentPlayer() { return this->currentPlayer; }
	std::vector<std::map<std::vector<int>, Figure*>> getMoves() { return this->moves; };
	std::string getText() { return this->text; };
	void setField(std::map<std::vector<int>, Figure*> newField) { this->field = newField; }
	void clean();
	void handleEvents();
	void update();
	void render();

private:
	//Variables
	GameManager* manager;
	Texture* fieldTexture;
	Config* config;
	Figure* selectedFigure;
	int currentPlayer = 0;
	bool finish = false;
	std::vector<std::map<std::vector<int>, Figure*>> moves;
	std::map<std::vector<int>, Figure*> field;
	std::string text;
	int size;
	std::array<SDL_Rect,4> availableFields;

	//methods
	void checkAvailableFields();
	std::array<int, 2> getFieldOnPoint(int x, int y);
	void checkSurroundingFields();
};

#endif
