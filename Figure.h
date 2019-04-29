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
	int getPlayer() { return this->player; }
	int getXField() { return this->xField; }
	int getYField() { return this->yField; }
	void animate(bool start);
	void move(int destX, int destY);
	void setPos(int x, int y);
	void render();
	bool isMoving() { return this->moving; }

private:
	GameManager* manager;
	Texture* figureTexture;
	Config* config;
	int xField, yField;
	//0 = black; 1 = white; 2 = king
	int type;
	//0 = black; 1 = white
	int player;

	//hover animation
	bool startAnimation = false;
	SDL_Rect startPos;

	//move animation
	int destX, destY;
	bool moving = false;
};

#endif 
