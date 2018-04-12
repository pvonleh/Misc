#ifndef ORC_HPP
#define ORC_HPP

#include "Enemy.hpp"
#include "GameWorld.hpp"
#include <string>

class Orc : public Enemy {
public:
	Orc();
	Orc(int health, int damage);
	void BullRush();
	void Spawn(GameWorld* gameWorld);
private:
	const int defaultHealth = 10;
	const int defaultDamage = 4;
};

#endif