#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include "SDL_image.h"

class Texture {
public:
	Texture();
	Texture(SDL_Renderer* renderer, const char* file, int w, int h);
	void setPos(int x, int y);
	void setRect(SDL_Rect* rect);
	SDL_Rect* getPos();
	SDL_Texture* getTexture();
	void render();

private:
	SDL_Renderer* renderer;
	int w;
	int h;
	SDL_Rect* pos = new SDL_Rect();
	SDL_Texture* texture;
};
#endif