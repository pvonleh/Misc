#ifndef GRENADE_HPP
#define GRENADE_HPP

#include "Item.hpp"
#include "CombatUnit.hpp"
#include "GameWorld.hpp"

class Grenade : public Item {
public:
	Grenade();
	void Effect(CombatUnit* target);
	void Spawn(GameWorld* gameWorld);
};

#endif