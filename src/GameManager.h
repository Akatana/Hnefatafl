#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "SDL.h"
#include <stdio.h>
#include <vector>
#include "GameState.h"

class GameState;

class GameManager {

public:
	GameManager();

	void initialize(const char* title, int x, int y, int w, int h, bool fullscreen);
	void clean();

	void changeState(GameState* state);
	void pushState(GameState* state);
	void popState();
	
	void handleEvents();
	void update();
	void render();

	bool running() {
		return isRunning;
	}

	void quit() {
		this->isRunning = false;
	}

	SDL_Renderer* getRenderer() {
		return this->renderer;
	}

	int getTime() { return this->time; }

	void setLevelFile(std::string file) {
		this->levelFile = file;
	}

	std::string getLevelFile() {
		return this->levelFile;
	}

private:
	std::vector<GameState*> states;
	int time;
	bool isRunning;
	std::string levelFile;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

#endif