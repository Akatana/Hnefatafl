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

	this->field->handleEvents(event);
	if (event.type == SDL_QUIT) {
		this->manager->quit();
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
	SDL_RenderPresent(this->manager->getRenderer());
}