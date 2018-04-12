#ifndef PLAYER_HPP
#define PLAYER_HPP

// problem code

#include "Item.hpp"
#include "CombatUnit.hpp"
#include <vector>
#include <string>
using std::string;

class Player : public CombatUnit {
public:
	Player( int health, int damage,string name);
	//int GetHealth();
	//int GetDamage();
	//void AddItemToInventory(Item* item);
	//void UseItem(Item* item, CombatUnit* target);
	//void ModifyHealth(int amount);
	//void DealDamage(CombatUnit* target);
	//void PrintStats();
private:
	//std::string name;
	//int health;
	//int damage;
	std::vector<Item*> inventory;
};

#endif