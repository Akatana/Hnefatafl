#ifndef OPTIONSSTATE_H
#define OPTIONSSTATE_H

#include "SDL.h"
#include "SDL_image.h"
#include "GameState.h"
#include "GameManager.h"
#include "Texture.h"
#include "Label.h"
#include "Field.h"

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
	Texture* backgroundTexture;
};

#endif