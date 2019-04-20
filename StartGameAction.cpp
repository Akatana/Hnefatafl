#include "StartGameAction.h"

StartGameAction StartGameAction::action;

void StartGameAction::execute() {

}

void StartGameAction::execute(GameManager* manager) {
	manager->changeState(PlayState::Instance());
}