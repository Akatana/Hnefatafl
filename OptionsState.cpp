#include "OptionsState.h"

void OptionsState::init(GameManager* manager) {
	printf("[INFO] OptionsState was initialised\n");
}

void OptionsState::clean() {
	printf("[INFO] OptionsState was cleaned\n");
}

void OptionsState::pause() {
	printf("[INFO] OptionsState was paused\n");
}

void OptionsState::resume() {
	printf("[INFO] OptionsState was resumed\n");
}

void OptionsState::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) {
		this->manager->quit();
	}
}

void OptionsState::update() {

}

void OptionsState::render() {

}