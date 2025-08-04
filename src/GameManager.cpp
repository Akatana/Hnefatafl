#include "GameManager.h"
#include "SDL_ttf.h"

GameManager::GameManager() {

}

void GameManager::initialize(const char* title, int x, int y, int w, int h, bool fullscreen) {
	int flags = 0;

	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		printf("[INFO] SDL initialised successfully!\n");
		if (TTF_Init() == 0) {
			printf("[INFO] SDL_ttf initialised successfully!\n");
		}
		this->window = SDL_CreateWindow(title, x, y, w, h, flags);
		if (this->window) {
			printf("[INFO] Game window was successfully created!\n");
		}

		this->renderer = SDL_CreateRenderer(this->window, -1, 0);
		if (this->renderer) {
			printf("[INFO] Renderer was successfully created!\n");
		}

		this->isRunning = true;
	} else {
		this->isRunning = false;
	}
}

void GameManager::clean() {
	SDL_DestroyWindow(this->window);
	SDL_DestroyRenderer(this->renderer);
	while (!this->states.empty()) {
		this->states.back()->clean();
		this->states.pop_back();
	}
	TTF_Quit();
	SDL_Quit();
	printf("[INFO] Game was cleaned!\n");
}

void GameManager::changeState(GameState* state) {
	if (!this->states.empty()) {
		this->states.back()->clean();
		this->states.pop_back();
	}

	this->states.push_back(state);
	this->states.back()->init(this);
}

void GameManager::pushState(GameState* state) {
	if (!this->states.empty()) {
		this->states.back()->pause();
	}

	this->states.push_back(state);
	this->states.back()->init(this);
}

void GameManager::popState() {
	if (!this->states.empty()) {
		this->states.back()->clean();
		this->states.pop_back();
	}

	if (!this->states.empty()) {	
		this->states.back()->resume();
	}				
}

void GameManager::handleEvents() {
	this->states.back()->handleEvents();
}

void GameManager::update() {
	this->time++;
	this->states.back()->update();
}

void GameManager::render() {
	this->states.back()->render();
}