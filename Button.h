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
	void handleEvents(SDL_Event event, Action* action);
	void handleEvents(SDL_Event event);
	void render();
	bool isClicked() { return this->clicked; }
	void setClicked(bool state) { this->clicked = state; }
	void setText(std::string text) { this->title = text; }
	std::string getText() { return this->title; }
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
	bool clicked = false;
	const char* text;
	std::string title;
	SDL_Rect clips[4];
	SDL_Rect clip;
	Texture texture;
};

#endif