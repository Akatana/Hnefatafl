#include "MenuState.h"

MenuState MenuState::menuState;

void MenuState::init(GameManager* manager) {
	this->manager = manager;
	this->button = new Button(this->manager, "Start", 192, 64, 200, 200, 192, 64);
	this->backgroundTexture = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	printf("[INFO] MenuState was initialised\n");
}

void MenuState::clean() {
	free(this->button);
	free(this->backgroundTexture);
	free(this->config);
	printf("[INFO] MenuState was cleaned\n");
}

void MenuState::pause() {
	printf("[INFO] MenuState was paused\n");
}

void MenuState::resume() {
	printf("[INFO] MenuState was resumed\n");
}

void MenuState::handleEvents() {
	this->button->handleEvents(StartGameAction::Instance());

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

void MenuState::update() {
	//this->manager->changeState(PlayState::Instance());
}

void MenuState::render() {
	SDL_RenderClear(this->manager->getRenderer());
	backgroundTexture->render();
	this->button->render();
	SDL_RenderPresent(this->manager->getRenderer());
}