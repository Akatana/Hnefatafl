#include "Field.h"

Field::Field(GameManager* manager, const char* file) {
	this->manager = manager;
	this->config = new Config(file);
	std::vector<std::string> tmpField = this->config->getStringArray("field");
	this->size = tmpField.size();
	for (auto &line : tmpField) {
		for (int i = 0; i < this->size; i++) {
			//Black
			if (line.at(i) == '+') {

			}
			//white
			else if (line.at(i) == '-') {

			}
			//king
			else if (line.at(i) == '#') {

			}
		}
	}
}

void Field::clean() {

}

void Field::handleEvents() {

}

void Field::update() {

}

void Field::render() {

}