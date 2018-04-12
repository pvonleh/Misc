#ifndef POTION_HPP
#define POTION_HPP

#include "Item.hpp"
#include "CombatUnit.hpp"
#include "GameWorld.hpp"

class Potion : public Item {
public:
	Potion();
	void Effect(CombatUnit* target);
	void Spawn(GameWorld* gameWorld);
};

#endif