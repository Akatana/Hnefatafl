#ifndef FIGURE_H
#define FIGURE_H

#include "GameManager.h"
#include "Texture.h"
#include "Config.h"

class Figure {
public:
	Figure() {}
	Figure(GameManager* manager, int x, int y, int type);
	Texture* getTexture() { return this->figureTexture; }
	int getType() { return this->type; }
	int getXField() { return this->xField; }
	int getYField() { return this->yField; }
	void animate(bool start);
	void setPos(int x, int y);
	void render();

private:
	GameManager* manager;
	Texture* figureTexture;
	Config* config;
	int xField;
	int yField;
	//0 = black; 1 = white; 2 = king
	int type;

	bool startAnimation = false;
	SDL_Rect startPos;
};

#endif 
