#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "SDL.h"
#include "GameState.h"
#include "GameManager.h"
#include "PlayState.h"
#include "OptionsState.h"
#include "Texture.h"
#include "Button.h"
#include "Label.h"
#include "StartGameAction.h"
#include <iostream>
#include <filesystem>

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
	bool levelSelection = false;

	//elements
	std::vector<Button*> gameModes;
	Texture* backgroundTexture;
	Texture* levelSelectTexture;
	Button* playButton;
	Button* optionsButton;
	Button* quitButton;
	Label* levelSelectTitle;
};

#endif