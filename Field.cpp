#include "Field.h"

Field::Field() {

}

Field::Field(GameManager* manager, const char* file) {
	this->config = new Config(file);
	std::vector<std::string> tmpField = this->config->getStringArray("field");
	this->size = tmpField.size();
	for (auto &line : tmpField) {
		for (int i = 0; i < this->size; i++) {
			//Black
			if (line.at(i) == '+') {

			}
		}
	}
}