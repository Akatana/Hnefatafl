#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include "SDL.h"
#include "SDL_image.h"
#include "GameState.h"
#include "GameManager.h"
#include "Texture.h"
#include "Label.h"
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
};

#endif