#include "GameManager.h"
#include "MenuState.h"

int main(int argc, char *argv[]) {
	const int targetFPS = 60;
	const int frameDelay = 1000 / targetFPS;
	
	Uint32 frameStart;
	int frameTime;

	GameManager manager;
	manager.initialize("Hnefatafl v1.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600, false);

	manager.changeState(MenuState::Instance());

	while (manager.running()) {
		frameStart = SDL_GetTicks();

		manager.handleEvents();
		manager.update();
		manager.render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	manager.clean();
	return 0;
}