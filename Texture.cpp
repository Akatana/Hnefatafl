#include "Texture.h"

Texture::Texture() {

}

Texture::Texture(SDL_Renderer* renderer, const char* file, int w, int h) {
	this->renderer = renderer;
	SDL_Surface* surface = IMG_Load(file);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
	this->texture = tex;
	this->pos->w = w;
	this->pos->h = h;

	SDL_FreeSurface(surface);
}

void Texture::setPos(int x, int y) {
	this->pos->x = x;
	this->pos->y = y;
}

void Texture::setRect(SDL_Rect* rect) {
	this->pos = rect;
}

SDL_Rect* Texture::getPos() {
	return this->pos;
}

SDL_Texture* Texture::getTexture() {
	return this->texture;
}

void Texture::render() {
	SDL_RenderCopy(this->renderer, this->texture, NULL, this->pos);
}