#include "StartGameAction.h"

StartGameAction StartGameAction::action;

void StartGameAction::execute() {
	printf("asdasd");
}

void StartGameAction::execute(GameManager* manager) {
	manager->changeState(PlayState::Instance());
}