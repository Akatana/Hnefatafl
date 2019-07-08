#include "OptionsState.h"

OptionsState OptionsState::optionsState;

void OptionsState::init(GameManager* manager) {
	this->manager = manager;
	this->config = new Config("assets/config/config.json");
	this->backgroundTexture = new Texture(this->manager->getRenderer(), "assets/images/bg_brown.png", 1000, 600);
	this->title = new Label(this->manager, "assets/fonts/viking2.ttf", "Optionen", 40);
	this->title->setPos(500 - (this->title->getRect().w / 2), 70);
	int xPos = 500;
	this->set1Button = new Button(this->manager, "Set 1", 150, 40, xPos + 10, 130, 192, 64);
	this->set2Button = new Button(this->manager, "Set 2", 150, 40, xPos + 10, 200, 192, 64);
	this->backButton = new Button(this->manager, "Zurück", 150, 40, 425, 500, 192, 64);

	this->set1Attacker = new Texture(this->manager->getRenderer(), "assets/images/figures/set1_attacker.png", 40, 40);
	this->set1Attacker->setPos(xPos - 50, 130);
	this->set1Defender = new Texture(this->manager->getRenderer(), "assets/images/figures/set1_defender.png", 40, 40);
	this->set1Defender->setPos(xPos - 90, 130);
	this->set1King = new Texture(this->manager->getRenderer(), "assets/images/figures/set1_king.png", 40, 40);
	this->set1King->setPos(xPos - 130, 130);

	this->set2Attacker = new Texture(this->manager->getRenderer(), "assets/images/figures/set2_attacker.png", 40, 40);
	this->set2Attacker->setPos(xPos - 50, 200);
	this->set2Defender = new Texture(this->manager->getRenderer(), "assets/images/figures/set2_defender.png", 40, 40);
	this->set2Defender->setPos(xPos - 90, 200);
	this->set2King = new Texture(this->manager->getRenderer(), "assets/images/figures/set2_king.png", 40, 40);
	this->set2King->setPos(xPos - 130, 200);
	printf("[INFO] OptionsState was initialised\n");
}

void OptionsState::clean() {
	this->backButton->clean();
	this->set1Button->clean();
	this->set2Button->clean();
	free(this->backButton);
	free(this->set1Button);
	free(this->set2Button);
	SDL_DestroyTexture(this->set1Attacker->getTexture());
	SDL_DestroyTexture(this->set2Attacker->getTexture());
	SDL_DestroyTexture(this->set1Defender->getTexture());
	SDL_DestroyTexture(this->set2Defender->getTexture());
	SDL_DestroyTexture(this->set1King->getTexture());
	SDL_DestroyTexture(this->set2King->getTexture());

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
	this->set1Button->handleEvents(event);
	this->set2Button->handleEvents(event);
	this->backButton->handleEvents(event);

	if (this->set1Button->isClicked()) {
		this->set1Button->setClicked(false);
		this->config->setString("blackFigure", "assets/images/figures/set1_attacker.png");
		this->config->setString("whiteFigure", "assets/images/figures/set1_defender.png");
		this->config->setString("kingFigure", "assets/images/figures/set1_king.png");
	} else if(this->set2Button->isClicked()) {
		this->set2Button->setClicked(false);
		this->config->setString("blackFigure", "assets/images/figures/set2_attacker.png");
		this->config->setString("whiteFigure", "assets/images/figures/set2_defender.png");
		this->config->setString("kingFigure", "assets/images/figures/set2_king.png");
	} else if (this->backButton->isClicked()) {
		this->backButton->setClicked(false);
		this->manager->popState();
	}

	if (event.type == SDL_QUIT) {
		this->manager->quit();
	}
}

void OptionsState::update() {

}

void OptionsState::render() {
	SDL_RenderClear(this->manager->getRenderer());
	this->backgroundTexture->render();
	this->title->render();
	this->set1Attacker->render();
	this->set1Defender->render();
	this->set1King->render();
	this->set2Attacker->render();
	this->set2Defender->render();
	this->set2King->render();
	this->set1Button->render();
	this->set2Button->render();
	this->backButton->render(),
	SDL_RenderPresent(this->manager->getRenderer());
}