#include "MenuState.h"

MenuState MenuState::menuState;

void MenuState::init(GameManager* manager) {
	this->manager = manager;
	this->playButton = new Button(this->manager, "Spielen", 192, 64, 200, 200, 192, 64);
	this->optionsButton = new Button(this->manager, "Optionen", 192, 64, 200, 280, 192, 64);
	this->quitButton = new Button(this->manager, "Beenden", 192, 64, 200, 360, 192, 64);
	this->backgroundTexture = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	printf("[INFO] MenuState was initialised\n");
}

void MenuState::clean() {
	free(this->playButton);
	free(this->optionsButton);
	free(this->quitButton);
	free(this->backgroundTexture);
	printf("[INFO] MenuState was cleaned\n");
}

void MenuState::pause() {
	printf("[INFO] MenuState was paused\n");
}

void MenuState::resume() {
	printf("[INFO] MenuState was resumed\n");
}

void MenuState::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	
	this->playButton->handleEvents(event);
	this->optionsButton->handleEvents(event);
	this->quitButton->handleEvents(event);
	
	//check for button presses
	if (this->playButton->isClicked()) {
		this->manager->changeState(PlayState::Instance());
		this->playButton->setClicked(false);
	}
	else if (this->optionsButton->isClicked()) {
		printf("clicked on options\n");
		this->optionsButton->setClicked(false);
	}
	else if (this->quitButton->isClicked()) {
		this->manager->quit();
		this->quitButton->setClicked(false);
	}

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
	this->playButton->render();
	this->optionsButton->render();
	this->quitButton->render();
	SDL_RenderPresent(this->manager->getRenderer());
}