#ifndef FIGURE_H
#define FIGURE_H

#include "GameManager.h"
#include "Texture.h"
#include "Field.h"
#include "Config.h"

class Figure {
public:
	Figure() {}
	Figure(GameManager* manager, int x, int y, int type);
	void handleEvents();
	void update();
	void render();

private:
	GameManager* manager;
	Texture* figureTexture;
	Config* config;
	SDL_Rect pos;
	int xField;
	int yField;
	//0 = black; 1 = white; 2 = king
	int type;
};

#endif 
