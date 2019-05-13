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
	std::map<std::vector<int>, Figure*> getLastMove() { return this->lastMove; }
	int getTurns() { return this->turns; }
	SDL_Rect* getPos() { return this->fieldTexture->getPos(); }
	std::string getText() { return this->text; };
	void setField(std::map<std::vector<int>, Figure*> newField) { this->field = newField; }
	void clean();
	void handleEvents(SDL_Event event);
	void update();
	void render();

private:
	//Variables
	GameManager* manager;
	Texture* fieldTexture;
	Config* config;
	Figure* selectedFigure;
	int currentPlayer = 0;
	int turns = 0;
	bool finish = false;
	std::map<std::vector<int>, Figure*> lastMove;
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
