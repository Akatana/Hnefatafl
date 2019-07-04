#ifndef PAUSESTATE_H
#define PAUSESTATE_H

#include "SDL.h"
#include "SDL_image.h"
#include "GameState.h"
#include "GameManager.h"
#include "Texture.h"
#include "Label.h"
#include "Field.h"

class PauseState : public GameState {
public:
	void init(GameManager* manager);
	void clean();

	void pause();
	void resume();

	void handleEvents();
	void update();
	void render();

	static PauseState* Instance() {
		return &pauseState;
	}

protected:
	PauseState() {}

private:
	static PauseState pauseState;
	GameManager* manager;
	Texture* backgroundTexture;
};


#endif