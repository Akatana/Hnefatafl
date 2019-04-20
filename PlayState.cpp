#include "PlayState.h"
#include "Texture.h"

Texture background, shield, field;
int cnt = 0;
PlayState PlayState::playState;

void PlayState::init(GameManager* manager) {
	this->manager = manager;
	shield = Texture(this->manager->getRenderer(), "assets/images/figures/white_shield.png", 32, 32);
	background = Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	field = Texture(this->manager->getRenderer(), "assets/images/field.png", 396, 396);
	field.setPos(400, 100);
	shield.setPos(402, 102);
	printf("[INFO] PlayState was initialised\n");

}

void PlayState::clean() {
	printf("[INFO] PlayState was cleaned\n");
}

void PlayState::pause() {
	printf("[INFO] PlayState was paused\n");
}

void PlayState::resume() {
	printf("[INFO] PlayState was resumed\n");
}

void PlayState::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		this->manager->quit();
		break;

	default:
		break;
	}
}

void PlayState::update() {
	cnt++;

}

void PlayState::render() {
	SDL_RenderClear(this->manager->getRenderer());
	SDL_RenderCopy(this->manager->getRenderer(), background.getTexture(), NULL, background.getPos());
	SDL_RenderCopy(this->manager->getRenderer(), field.getTexture(), NULL, field.getPos());
	SDL_RenderCopy(this->manager->getRenderer(), shield.getTexture(), NULL, shield.getPos());
	SDL_RenderPresent(this->manager->getRenderer());
}