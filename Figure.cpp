#include "Figure.h"

Figure::Figure(GameManager* manager, int x, int y, int type) {
	this->manager = manager;
	this->type = type;
	this->config = new Config("assets/config/config.json");
	if (this->type == 0) {
		this->figureTexture = new Texture(this->manager->getRenderer(), this->config->getString("blackFigure").c_str(), 32, 32);
	}
	else if (this->type == 1) {
		this->figureTexture = new Texture(this->manager->getRenderer(), this->config->getString("whiteFigure").c_str(), 32, 32);
	}
	else if (this->type == 2) {
		this->figureTexture = new Texture(this->manager->getRenderer(), this->config->getString("kingFigure").c_str(), 32, 32);
	}
	this->xField = x;
	this->yField = y;
}

void Figure::handleEvents() {

}

void Figure::update() {

}

void Figure::render() {
	this->figureTexture->render();
}