#include "PauseState.h"

PauseState PauseState::pauseState;

void PauseState::init(GameManager* manager) {
	this->manager = manager;
	this->backgroundTexture = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	printf("[INFO] PauseState was initialised\n");
}

void PauseState::clean() {
	printf("[INFO] PauseState was cleaned\n");
}

void PauseState::pause() {
	printf("[INFO] PauseState was paused\n");
}

void PauseState::resume() {
	printf("[INFO] PauseState was resumed\n");
}

void PauseState::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) {
		this->manager->quit();
	}
}

void PauseState::update() {

}

void PauseState::render() {
	SDL_RenderClear(this->manager->getRenderer());
	this->backgroundTexture->render();
	SDL_RenderPresent(this->manager->getRenderer());
}