#ifndef ENEMY_HPP
#define ENEMY_HPP
//problem code
#include <string>
#include "Spawnable.hpp"
#include "CombatUnit.hpp"
#include "Item.hpp"
using std::string;

class Enemy : public Spawnable, public CombatUnit {
public:
	Enemy(int health, int damage,string name);
	//int GetHealth();
	//int GetDamage();
	//void ModifyHealth(int amount);
	//void DealDamage(CombatUnit* target);
	//void UseItem(Item* item, CombatUnit* target);
	//void PrintStats();
//private:
	//std::string type;
	//int health;
	//int damage;
};

#endif