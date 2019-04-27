#include "PlayState.h"

PlayState PlayState::playState;

void PlayState::init(GameManager* manager) {
	this->manager = manager;
	this->background = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	this->field = new Field(this->manager, "assets/levels/Hnefatafl.json", 100, 100);
	//field.setPos(400, 100);
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
	this->field->handleEvents();

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
	this->field->update();
}

void PlayState::render() {
	SDL_RenderClear(this->manager->getRenderer());
	this->background->render();
	this->field->render();
	SDL_RenderPresent(this->manager->getRenderer());
}