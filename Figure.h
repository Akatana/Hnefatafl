#ifndef FIGURE_H
#define FIGURE_H

#include "GameManager.h"
#include "Texture.h"
#include "Field.h"
#include "Config.h"

class Figure {
public:
	Figure();
	Figure(int x, int y, int type);
	void handleEvents();
	void update();
	void render();

private:
	SDL_Rect pos;
	int xField;
	int yField;
	int type;
};

#endif 
