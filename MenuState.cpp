#include "MenuState.h"

MenuState MenuState::menuState;

void MenuState::init(GameManager* manager) {
	this->manager = manager;
	this->playButton = new Button(this->manager, "Spielen", 192, 64, 200, 200, 192, 64);
	this->optionsButton = new Button(this->manager, "Optionen", 192, 64, 200, 280, 192, 64);
	this->quitButton = new Button(this->manager, "Beenden", 192, 64, 200, 360, 192, 64);
	this->backgroundTexture = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	this->levelSelectTexture = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 200, 600);
	this->levelSelectTexture->setPos(400, 0);

	//Set up gamemodes
	int yPos = 30;
	for (const auto &entry : std::filesystem::directory_iterator("assets/levels")) {
		Button* button = new Button(this->manager, entry.path().stem().string().c_str(), 150, 40, 425, yPos, 192, 64);
		button->setText(entry.path().stem().string());
		this->gameModes.push_back(button);
		yPos += 45;
	}

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
	
	if (this->levelSelection) {
		for (const auto &button : this->gameModes) {
			button->handleEvents(event);
			if (button->isClicked()) {
				button->setClicked(false);
				this->manager->setLevelFile("assets/levels/" + button->getText() + ".json");
				this->manager->changeState(PlayState::Instance());
			}
		}
	}
	else {
		this->playButton->handleEvents(event);
		this->optionsButton->handleEvents(event);
		this->quitButton->handleEvents(event);

		//check for button presses
		if (this->playButton->isClicked()) {
			this->playButton->setClicked(false);
			this->levelSelection = true;
		}
		else if (this->optionsButton->isClicked()) {
			this->optionsButton->setClicked(false);
		}
		else if (this->quitButton->isClicked()) {
			this->quitButton->setClicked(false);
			this->manager->quit();
		}
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
	
}

void MenuState::render() {
	SDL_RenderClear(this->manager->getRenderer());
	if (this->levelSelection) {
		this->backgroundTexture->render();
		this->levelSelectTexture->render();
		for (const auto &button : this->gameModes) {
			button->render();
		}
	}
	else {
		this->backgroundTexture->render();
		this->playButton->render();
		this->optionsButton->render();
		this->quitButton->render();
	}
	SDL_RenderPresent(this->manager->getRenderer());
}