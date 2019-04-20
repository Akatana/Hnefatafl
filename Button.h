#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"
#include "SDL_image.h"
#include "Action.h"
#include "GameManager.h"
#include "Texture.h"
#include "Label.h"

const int CLIP_MOUSEOVER = 0;
const int CLIP_MOUSEOUT = 1;
const int CLIP_MOUSEDOWN = 2;
const int CLIP_MOUSEUP = 3;

class Button {
public:
	Button();
	Button(GameManager* manager, const char* text, int w, int h, int xPos, int yPos, int spriteW, int spriteH);
	void handleEvents(Action* action);
	void render();
	void show() {
		this->visible = true;
	}
	void hide() {
		this->visible = false;
	}

private:
	GameManager* manager;
	Label label;
	bool visible = true;
	const char* text;
	SDL_Rect clips[4];
	SDL_Rect clip;
	Texture texture;
};

#endif