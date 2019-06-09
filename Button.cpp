#include "Button.h"
#include <stdio.h>

Button::Button() {

}

Button::Button(GameManager* manager, const char* text, int w, int h, int xPos, int yPos, int spriteW, int spriteH) {
	//Setting the different tiles of the button
	clips[CLIP_MOUSEOVER].x = 0;
	clips[CLIP_MOUSEOVER].y = 0;
	clips[CLIP_MOUSEOVER].w = spriteW;
	clips[CLIP_MOUSEOVER].h = spriteH;

	clips[CLIP_MOUSEOUT].x = spriteW;
	clips[CLIP_MOUSEOUT].y = 0;
	clips[CLIP_MOUSEOUT].w = spriteW;
	clips[CLIP_MOUSEOUT].h = spriteH;

	clips[CLIP_MOUSEDOWN].x = 0;
	clips[CLIP_MOUSEDOWN].y = spriteH;
	clips[CLIP_MOUSEDOWN].w = spriteW;
	clips[CLIP_MOUSEDOWN].h = spriteH;

	clips[CLIP_MOUSEUP].x = spriteW;
	clips[CLIP_MOUSEUP].y = spriteH;
	clips[CLIP_MOUSEUP].w = spriteW;

	clips[CLIP_MOUSEUP].h = spriteH;
	this->manager = manager;
	this->texture = Texture(this->manager->getRenderer(), "assets/images/button.png", w, h);
	texture.setPos(xPos, yPos);
	this->text = text;
	this->clip = clips[CLIP_MOUSEOUT];

	this->label = Label(this->manager, "assets/fonts/viking2.ttf", this->text, 50);
	int fontSize = 50;
	while (this->label.getRect().w > w || this->label.getRect().h > h) {
		this->label = Label(this->manager, "assets/fonts/viking2.ttf", this->text, fontSize--);
	}
	SDL_Rect size = this->label.getRect();
	if (size.w > w || size.h > h) {
		this->label.setPos(xPos, yPos);
	}
	else {
		this->label.setPos(xPos + ((w - size.w) / 2), yPos + ((h - size.h) / 2));
	}
}

void Button::handleEvents(SDL_Event event, Action* action) {
	int x = 0, y = 0;
	SDL_Rect* rect = this->texture.getPos();

	if (event.type == SDL_MOUSEMOTION) {
		x = event.motion.x;
		y = event.motion.y;

		if (x > rect->x && x < rect->x + rect->w && y > rect->y && y < rect->y + rect->h) {
			this->clip = this->clips[CLIP_MOUSEOVER];
		}
		else {
			this->clip = this->clips[CLIP_MOUSEOUT];
		}

	}
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		x = event.button.x;
		y = event.button.y;
		if (x > rect->x && x < rect->x + rect->w && y > rect->y && y < rect->y + rect->h) {
			action->execute(this->manager);
		}
	}
}

void Button::handleEvents(SDL_Event event) {
	int x = 0, y = 0;
	SDL_Rect* rect = this->texture.getPos();

	if (event.type == SDL_MOUSEMOTION) {
		x = event.motion.x;
		y = event.motion.y;

		if (x > rect->x && x < rect->x + rect->w && y > rect->y && y < rect->y + rect->h) {
			this->clip = this->clips[CLIP_MOUSEOVER];
		}
		else {
			this->clip = this->clips[CLIP_MOUSEOUT];
		}

	}
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		x = event.button.x;
		y = event.button.y;
		if (x > rect->x && x < rect->x + rect->w && y > rect->y && y < rect->y + rect->h) {
			this->clicked = true;
		}
	}
}

void Button::render() {
	SDL_RenderCopy(this->manager->getRenderer(), this->texture.getTexture(), &this->clip, this->texture.getPos());
	this->label.render();
}