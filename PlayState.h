#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "SDL.h"
#include "SDL_image.h"
#include "GameState.h"
#include "MenuState.h"
#include "GameManager.h"
#include "Texture.h"
#include "Label.h"
#include "Button.h"
#include "Field.h"

class PlayState : public GameState {
public:
	void init(GameManager* manager);
	void clean();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void render();

	static PlayState* Instance() {
		return &playState;
	}

protected:
	PlayState() {}

private:
	static PlayState playState;
	GameManager* manager;
	Field* field;
	Texture* background;
	Texture* pauseTexture;
	Label* gameOverText;
	Label* currentPlayer;
	Label* moveAmount;
	Label* infoText;
	Label* pauseText;
	Button* menuButton;
	Button* returnButton;
	Button* saveButton;
	Button* loadButton;
	Button* exitButton;
	Button* endButton;
	bool paused = false;

	SDL_Rect infoBackground = { 0, 0, 0, 0 };
};

#endif