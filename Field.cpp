#include "Field.h"

Field::Field(GameManager* manager, const char* file, int xPos, int yPos) {
	this->manager = manager;
	this->config = new Config(file);
	this->fieldTexture = new Texture(this->manager->getRenderer(), this->config->getString("fieldImg").c_str(), 396, 396);
	this->fieldTexture->setPos(xPos, yPos);
	std::vector<std::string> tmpField = this->config->getStringArray("field");
	this->size = tmpField.size();
	int y = 0;
	for (auto &line : tmpField) {
		for (int x = 0; x < this->size; x++) {
			//Black
			if (line.at(x) == '+') {
				Figure* fig = new Figure(this->manager, x, y, 0);
				fig->getTexture()->setPos(this->fieldTexture->getPos()->x + (fig->getXField() * 36) + 2, this->fieldTexture->getPos()->y + (fig->getYField() * 36) + 2);
				this->field.insert(std::pair<std::vector<int>, Figure*>({x,y}, fig));
				this->figures.push_back(fig);
			}
			//white
			else if (line.at(x) == '-') {
				Figure* fig = new Figure(this->manager, x, y, 1);
				fig->getTexture()->setPos(this->fieldTexture->getPos()->x + (fig->getXField() * 36) + 2, this->fieldTexture->getPos()->y + (fig->getYField() * 36) + 2);
				this->field.insert(std::pair<std::vector<int>, Figure*>({ x,y }, fig));
				this->figures.push_back(fig);
			}
			//king
			else if (line.at(x) == '#') {
				Figure* fig = new Figure(this->manager, x, y, 2);
				fig->getTexture()->setPos(this->fieldTexture->getPos()->x + (fig->getXField() * 36) + 2, this->fieldTexture->getPos()->y + (fig->getYField() * 36) + 2);
				this->field.insert(std::pair<std::vector<int>, Figure*>({ x,y }, fig));
				this->figures.push_back(fig);
			}
			else {
				this->field.insert(std::pair<std::vector<int>, Figure*>({ x,y }, nullptr));
			}
		}
		y++;
	}
}

void Field::setPos(int x, int y) {
	this->fieldTexture->setPos(x, y);
}

void Field::clean() {

}

void Field::checkAvailableFields() {
	if (this->selectedFigure == nullptr) {
		return;
	}
	this->availableFields.fill({ 0,0,0,0 });
	int x = this->selectedFigure->getXField();
	int y = this->selectedFigure->getYField();
	//Fields left to the selected figure
	for (int xNeg = x-1; xNeg >= 0; xNeg--) {
		//ignore corners
		if (((xNeg == 0 && y == 0) || (xNeg == 0 && y == this->size - 1)) && this->selectedFigure->getType() != 2) {
			break;
		}
		if (this->field.at({ xNeg, y }) == nullptr) {
			this->availableFields[0].w += 36;
		}
		else {
			break;
		}
	}
	this->availableFields[0].h = 36;
	this->availableFields[0].x = this->fieldTexture->getPos()->x + (x*36) - this->availableFields[0].w;
	this->availableFields[0].y = this->fieldTexture->getPos()->y + (y*36);
	//Fields right to the selected figure
	for (int xPos = x + 1; xPos < this->size; xPos++) {
		//ignore corners if the king is not selected
		if (((xPos == this->size-1 && y == this->size-1) || (xPos == this->size - 1 && y == 0)) && this->selectedFigure->getType() != 2) {
			break;
		}
		if (this->field.at({ xPos, y }) == nullptr) {
			this->availableFields[1].w += 36;
		}
		else {
			break;
		}
	}
	this->availableFields[1].h = 36;
	this->availableFields[1].x = this->fieldTexture->getPos()->x + (x * 36) + 36;
	this->availableFields[1].y = this->fieldTexture->getPos()->y + (y * 36);
	//Fields above to the selected figure
	for (int yNeg = y - 1; yNeg >= 0; yNeg--) {
		//ignore corners if the king is not selected
		if (((x == 0 && yNeg == 0) || (x == this->size - 1 && yNeg == 0)) && this->selectedFigure->getType() != 2) {
			break;
		}
		if (this->field.at({ x, yNeg }) == nullptr) {
			this->availableFields[2].h += 36;
		}
		else {
			break;
		}
	}
	this->availableFields[2].w = 36;
	this->availableFields[2].x = this->fieldTexture->getPos()->x + (x * 36);
	this->availableFields[2].y = this->fieldTexture->getPos()->y + (y * 36) - this->availableFields[2].h;
	//Fields below to the selected figure
	for (int yPos = y + 1; yPos < this->size; yPos++) {
		//ignore corners if the king is not selected
		if (((x == 0 && yPos == this->size - 1) || (x == this->size - 1 && yPos == this->size - 1)) && this->selectedFigure->getType() != 2) {
			break;
		}
		if (this->field.at({ x, yPos }) == nullptr) {
			this->availableFields[3].h += 36;
		}
		else {
			break;
		}
	}
	this->availableFields[3].w = 36;
	this->availableFields[3].x = this->fieldTexture->getPos()->x + (x * 36);
	this->availableFields[3].y = this->fieldTexture->getPos()->y + (y * 36) + 36;
}

std::array<int, 2> Field::getFieldOnPoint(int x, int y) {
	x -= this->fieldTexture->getPos()->x;
	y -= this->fieldTexture->getPos()->y;
	int xField = 0;
	int yField = 0;
	std::array<int, 2> result;
	while (yField < y) {
		yField += 36;
		while (xField < x) {
			xField += 36;
		}
	}
	result[0] = (xField / 36) - 1;
	result[1] = (yField / 36) - 1;
	return result;
}

void Field::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	if (this->selectedFigure != nullptr && this->selectedFigure->isMoving()) {
		return;
	}

	//track mouse movement for the figure animation
	if (event.type == SDL_MOUSEMOTION) {
		int x = event.motion.x;
		int y = event.motion.y;
		for (Figure* &figure : this->figures) {
			if (x > this->fieldTexture->getPos()->x + figure->getXField() * 36 && x < this->fieldTexture->getPos()->x + figure->getXField() * 36 + 36 &&
				y > this->fieldTexture->getPos()->y + figure->getYField() * 36 && y < this->fieldTexture->getPos()->y + figure->getYField() * 36 + 36) {
				figure->animate(true);
			}
			else {
				figure->animate(false);
			}
		}
	}

	//check if a figure is selected or deselected
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			int x = event.button.x;
			int y = event.button.y;

			if (this->selectedFigure != nullptr) {
				for (SDL_Rect &field : this->availableFields) {
					if (x > field.x && x < field.x + field.w && y > field.y && y < field.y + field.h) {
						std::array<int, 2> field = this->getFieldOnPoint(x, y);
						this->selectedFigure->move(this->fieldTexture->getPos()->x + (field[0] * 36 + 2), this->fieldTexture->getPos()->y + (field[1] * 36 + 2));
						//this->field.erase({ this->selectedFigure->getXField(), this->selectedFigure->getYField() });
						//this->field.erase({ field[0], field[1] });
						printf("%i, %i - %i, %i\n", this->selectedFigure->getXField(), this->selectedFigure->getYField(), field[0], field[1]);
						this->field[{ this->selectedFigure->getXField(), this->selectedFigure->getYField() }] = nullptr;
						this->selectedFigure->setPos(field[0], field[1]);
						this->field[{ field[0], field[1] }] = this->selectedFigure;
						this->selectedFigure = nullptr;
					}
				}
				this->selectedFigure = nullptr;
				this->availableFields.fill({ 0,0,0,0 });
				return;
			}
			for (Figure* &figure : this->figures) {
				if (x > this->fieldTexture->getPos()->x + figure->getXField() * 36 && x < this->fieldTexture->getPos()->x + figure->getXField() * 36 + 36 &&
						y > this->fieldTexture->getPos()->y + figure->getYField() * 36 && y < this->fieldTexture->getPos()->y + figure->getYField() * 36 + 36) {
					this->selectedFigure = figure;
					this->checkAvailableFields();
				}
			}
		}
		if (event.button.button == SDL_BUTTON_RIGHT) {
			this->selectedFigure = nullptr;
			this->availableFields.fill({ 0,0,0,0 });
		}
	}
}

void Field::update() {
}

void Field::render() {
	this->fieldTexture->render();
	for (Figure* &figure : this->figures) {
		figure->render();
	}
	SDL_SetRenderDrawBlendMode(this->manager->getRenderer(), SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(this->manager->getRenderer(), 0, 255, 0, 150);
	for (SDL_Rect &field : this->availableFields) {
		SDL_RenderFillRect(this->manager->getRenderer(), &field);
	}
}