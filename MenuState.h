#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "SDL.h"
#include "GameState.h"
#include "GameManager.h"
#include "PlayState.h"
#include "Texture.h"
#include "Button.h"
#include "StartGameAction.h"

class MenuState : public GameState {
public:
	void init(GameManager* manager);
	void clean();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void render();

	static MenuState* Instance() {
		return &menuState;
	}

protected:
	MenuState() {}

private:
	static MenuState menuState;
	GameManager* manager;

	//elements
	Texture* backgroundTexture;
	Button* button;
};

#endif