#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Enemy.hpp"
#include "GameWorld.hpp"

class Goblin : public Enemy {
public:
	Goblin();
	Goblin(int health, int damage);
	void Flee();
	void Spawn(GameWorld* gameWorld);
private:
	const int defaultHealth = 6;
	const int defaultDamage = 2;
};

#endif