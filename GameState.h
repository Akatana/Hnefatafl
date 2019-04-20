#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "GameManager.h"

class GameManager;

class GameState {
public:
	virtual void init(GameManager* manager) = 0;
	virtual void clean() = 0;

	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	/*void switchState(GameManager* manager, GameState* state) {
		manager->changeState(state);
	}*/

protected:
	GameState(){}

};

#endif