#ifndef OPTIONSSTATE_H
#define OPTIONSSTATE_H

#include "SDL.h"
#include "SDL_image.h"
#include "GameState.h"
#include "GameManager.h"
#include "Texture.h"
#include "Label.h"
#include "Button.h"
#include "Config.h"

class OptionsState : public GameState {
public:
	void init(GameManager* manager);
	void clean();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void render();

	static OptionsState* Instance() {
		return &optionsState;
	}

protected:
	OptionsState() {}

private:
	static OptionsState optionsState;
	GameManager* manager;
	Config* config;
	Label* title;
	Texture* backgroundTexture;
	Texture* set1Attacker;
	Texture* set1Defender;
	Texture* set1King;
	Texture* set2Attacker;
	Texture* set2Defender;
	Texture* set2King;
	Button* set1Button;
	Button* set2Button;
	Button* backButton;
};

#endif