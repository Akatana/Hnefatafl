#ifndef LABEL_H
#define LABEL_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "GameManager.h"

class Label {
public:
	Label();
	Label(GameManager* manager);
	Label(GameManager* manager, const char* file, const char* text, int size);
	void clean();
	void setText(const char* file, const char* text, int size);

	const char* getText() {
		return this->text;
	}

	void setPos(int x, int y) {
		this->rect.x = x;
		this->rect.y = y;
	}

	void setSize(int w, int h) {
		this->rect.w = w;
		this->rect.h = h;
	}

	SDL_Rect getRect() {
		return this->rect;
	}

	void setView(SDL_Rect rect) {
		this->viewableArea = rect;
	}

	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha);

	void render();

private:
	GameManager* manager;
	const char* textFile = "assets/fonts/arial.ttf";
	const char* text = "Text";
	int textSize = 21;
	SDL_Rect rect;
	SDL_Rect viewableArea = { 0,0,0,0 };
	SDL_Color color = { 0, 0, 0, 255 };
	SDL_Texture* textTexture;
};

#endif