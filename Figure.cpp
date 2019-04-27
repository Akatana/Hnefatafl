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

void Figure::setPos(int x, int y) {
	this->xField = x;
	this->yField = y;
}

void Figure::render() {
	if (this->startAnimation) {
		if (this->startPos.x == 0) {
			this->startPos = *this->figureTexture->getPos();
			this->figureTexture->setPos(this->figureTexture->getPos()->x, this->figureTexture->getPos()->y - 5);
		}
		//this->figureTexture->setPos(this->figureTexture->getPos()->x, this->figureTexture->getPos()->y + (int)(sin(this->manager->getTime() * 0.33) * 2));
	}
	else {
		if (this->startPos.x != 0) {
			this->figureTexture->setPos(this->startPos.x, this->startPos.y);
			this->startPos = { 0,0,0,0 };
		}
	}
	if (this->moving) {
		int x = this->figureTexture->getPos()->x;
		int y = this->figureTexture->getPos()->y;
		printf("{%i, %i}, {%i, %i}\n", x, y, destX, destY);
		if (this->figureTexture->getPos()->x == this->destX && this->figureTexture->getPos()->y == this->destY) {
			this->moving = false;
		}
		if (x < this->destX) {
			this->figureTexture->setPos(x+=1, y);
		}
		if (x > this->destX) {
			this->figureTexture->setPos(x-=1, y);
		}
		if (y < this->destY) {
			this->figureTexture->setPos(x, y += 1);
		}
		if (y > this->destY) {
			this->figureTexture->setPos(x, y -= 1);
		}
	}
	this->figureTexture->render();
}

void Figure::animate(bool start) {
	this->startAnimation = start;
}

void Figure::move(int destX, int destY) {
	this->destX = destX;
	this->destY = destY;
	this->moving = true;
}