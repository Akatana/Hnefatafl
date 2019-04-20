#include "Label.h"

Label::Label() {

}

Label::Label(GameManager* manager) {
	TTF_Font* font = TTF_OpenFont(this->textFile, this->textSize);
	SDL_Surface* surface = TTF_RenderText_Solid(font, this->text, this->color);
	this->textTexture = SDL_CreateTextureFromSurface(manager->getRenderer(), surface);
	SDL_FreeSurface(surface);

	this->manager = manager;
}

Label::Label(GameManager* manager, const char* file, const char* text, int size) {
	TTF_Font* font = TTF_OpenFont(file, size);
	SDL_Surface* surface = TTF_RenderText_Blended_Wrapped(font, text, this->color, 1000);
	this->textTexture = SDL_CreateTextureFromSurface(manager->getRenderer(), surface);
	SDL_FreeSurface(surface);
	int textW = 0;
	int textH = 0;
	SDL_QueryTexture(this->textTexture, NULL, NULL, &textW, &textH);
	this->rect.w = textW;
	this->rect.h = textH;

	this->textSize = size;
	this->manager = manager;
	this->text = text;
	this->textFile = file;
}

void Label::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha) {
	this->color = { r, g, b, alpha };
	TTF_Font* font = TTF_OpenFont(this->textFile, this->textSize);
	SDL_Surface* surface = TTF_RenderText_Solid(font, this->text, this->color);
	this->textTexture = SDL_CreateTextureFromSurface(this->manager->getRenderer(), surface);
	SDL_FreeSurface(surface);
}

void Label::render() {
	SDL_RenderCopy(this->manager->getRenderer(), this->textTexture, NULL, &this->rect);
}