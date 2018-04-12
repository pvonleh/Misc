#ifndef SPAWNABLE_HPP
#define SPAWNABLE_HPP

#include <iostream>

class GameWorld;

class Spawnable {
public:
	virtual void Spawn(GameWorld* gameWorld) = 0;
};

#endif