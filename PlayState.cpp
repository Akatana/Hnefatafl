#include "PlayState.h"

PlayState PlayState::playState;

void PlayState::init(GameManager* manager) {
	this->manager = manager;
	this->background = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	this->field = new Field(this->manager, this->manager->getLevelFile().c_str(), 100, 100);
	this->gameOverText = new Label(this->manager, "assets/fonts/viking2.ttf", "0", 50);
	this->gameOverText->setPos(100, 100);
	this->currentPlayer = new Label(this->manager, "assets/fonts/arial.ttf", "0", 30);
	this->currentPlayer->setPos(this->field->getPos()->x, this->field->getPos()->y - 30);
	this->moveAmount = new Label(this->manager, "assets/fonts/arial.ttf", "0", 30);
	this->moveAmount->setPos(this->field->getPos()->x + this->field->getPos()->w - 70, this->field->getPos()->y - 30);
	this->infoText = new Label(this->manager, "assets/fonts/arial.ttf", "0", 25);
	this->infoText->setPos(this->field->getPos()->x + this->field->getPos()->w + 15, this->field->getPos()->y);
	this->infoBackground.x = this->field->getPos()->x + this->field->getPos()->w + 10;
	this->infoBackground.y = this->field->getPos()->y;
	this->infoBackground.w = 396;
	this->infoBackground.h = 396;
	this->pauseTexture = new Texture(this->manager->getRenderer(), "assets/images/levelSelect.png", 200, 600);
	this->pauseTexture->setPos(400, 0);
	this->pauseText = new Label(this->manager, "assets/fonts/viking2.ttf", "Pause", 40);
	this->pauseText->setPos(500 - (this->pauseText->getRect().w / 2), 16);
	
	this->returnButton = new Button(this->manager, "Weiter", 150, 40, 425, 70, 192, 64);
	this->menuButton = new Button(this->manager, "Hauptmenü", 150, 40, 425, 115, 192, 64);
	this->saveButton = new Button(this->manager, "Speichern", 150, 40, 425, 160, 192, 64);
	this->loadButton = new Button(this->manager, "Laden", 150, 40, 425, 205, 192, 64);
	this->exitButton = new Button(this->manager, "Beenden", 150, 40, 425, 250, 192, 64);
	printf("[INFO] PlayState was initialised\n");
}

void PlayState::clean() {
	this->field->clean();
	SDL_DestroyTexture(this->background->getTexture());
	SDL_DestroyTexture(this->pauseTexture->getTexture());
	free(this->background);
	free(this->pauseTexture);
	this->returnButton->clean();
	this->menuButton->clean();
	this->saveButton->clean();
	this->loadButton->clean();
	this->exitButton->clean();
	free(this->returnButton);
	free(this->menuButton);
	free(this->saveButton);
	free(this->loadButton);
	free(this->exitButton);
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

	if (this->paused) {
		this->returnButton->handleEvents(event);
		this->menuButton->handleEvents(event);
		this->saveButton->handleEvents(event);
		this->loadButton->handleEvents(event);
		this->exitButton->handleEvents(event);

		//Buttons überprüfen
		if (this->returnButton->isClicked()) {
			this->returnButton->setClicked(false);
			this->paused = false;
		}
		else if (this->menuButton->isClicked()) {
			this->menuButton->setClicked(false);
			this->paused = false;
			this->manager->changeState(MenuState::Instance());
		}
		else if (this->saveButton->isClicked()) {
			this->saveButton->setClicked(false);
			this->field->saveGame();
			this->paused = false;
		}
		else if (this->loadButton->isClicked()) {
			this->loadButton->setClicked(false);
			this->field->loadGame();
			this->paused = false;
		}
		else if (this->exitButton->isClicked()) {
			this->exitButton->setClicked(false);
			this->manager->quit();
		}
	}
	else {
		this->field->handleEvents(event);
	}
	

	if (event.type == SDL_QUIT) {
		this->manager->quit();
	}
	else if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			if (this->paused) {
				this->paused = false;
			}
			else {
				this->paused = true;
			}
		}
	}
}

void PlayState::update() {
	std::string currentPlayer;
	if (this->field->getCurrentPlayer() == 0) {
		currentPlayer = "Schwarz";
	}
	else {
		currentPlayer = "Weiß";
	}
	if (this->field->isFinished()) {
		//Invert the current player to get the winner
		if (currentPlayer == "Weiß") {
			currentPlayer = "Schwarz";
		}
		else {
			currentPlayer = "Weiß";
		}
		this->gameOverText->setText("assets/fonts/viking2.ttf", (currentPlayer + " hat gewonnen!").c_str(), 50);
	}
	
	//this->field->getText().c_str()"a\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\na\nende\n"
	this->infoText->setText("assets/fonts/arial.ttf", (this->field->getText()).c_str(), 20);
	this->currentPlayer->setText("assets/fonts/arial.ttf", ("Am Zug: " + currentPlayer).c_str(), 25);
	this->moveAmount->setText("assets/fonts/arial.ttf", ("Zug: " + std::to_string(this->field->getTurns())).c_str(), 25);
	this->field->update();
}

void PlayState::render() {
	SDL_RenderClear(this->manager->getRenderer());
	this->background->render();
	if (this->paused) {
		this->pauseTexture->render();
		this->pauseText->render();
		this->returnButton->render();
		this->menuButton->render();
		this->saveButton->render();
		this->loadButton->render();
		this->exitButton->render();
	}
	else {
		//Game is running
		if (!this->field->isFinished()) {
			this->field->render();
			this->currentPlayer->render();
			this->moveAmount->render();
			SDL_SetRenderDrawBlendMode(this->manager->getRenderer(), SDL_BLENDMODE_BLEND);
			SDL_SetRenderDrawColor(this->manager->getRenderer(), 255, 255, 255, 70);
			SDL_RenderFillRect(this->manager->getRenderer(), &this->infoBackground);
			this->infoText->render();
		}
		//Game is over
		else {
			this->gameOverText->render();
		}
	}
	SDL_RenderPresent(this->manager->getRenderer());
}