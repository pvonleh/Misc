#ifndef COMBATUNIT_HPP
#define COMBATUNIT_HPP
#include "Item.hpp"
#include <string>
using std::string;
// problem code


class CombatUnit {
public:
	CombatUnit(int health, int damage,string name);
	int GetHealth();
	int GetDamage();
	void ModifyHealth(int amount);
	void DealDamage(CombatUnit* target);
	void UseItem(Item* item, CombatUnit* target);
	void PrintStats();
protected:
	string name;
	int health;
	int damage;
/*
	virtual void UseItem(Item* item, CombatUnit* target) = 0;
	virtual void ModifyHealth(int amount) = 0;
	virtual void DealDamage(CombatUnit* target) = 0;
	virtual void PrintStats() = 0;
	*/

};

#endif