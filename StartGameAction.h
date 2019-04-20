#ifndef STARTGAMEACTION_H
#define STARTGAMEACTION_H

#include "Action.h"
#include "GameManager.h"
#include "PlayState.h"
#include <stdio.h>

class StartGameAction : public Action {
public:
	void execute();
	void execute(GameManager* manager);

	static StartGameAction* Instance() {
		return &action;
	}

protected:
	StartGameAction() {}

private:
	static StartGameAction action;
};

#endif