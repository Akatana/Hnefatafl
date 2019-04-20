#ifndef ACTION_H
#define ACTION_H

#include "GameManager.h"

class Action {
public:
	virtual void execute() = 0;
	virtual void execute(GameManager* manager) = 0;

protected:
	Action() {}
};

#endif