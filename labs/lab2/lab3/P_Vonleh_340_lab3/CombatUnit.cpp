#include "CombatUnit.hpp"
#include <string>
#include <iostream>
using std::string;


CombatUnit::CombatUnit( int health, int damage,string name)
{
	this->health = health;
	this->damage = damage;
	this->name = name;


}
int CombatUnit::GetHealth()
{
	return this->health;
}

int CombatUnit::GetDamage()
{
	return this->damage;
}
void CombatUnit::ModifyHealth(int amount){
	this->health -= amount;
}
void CombatUnit::DealDamage(CombatUnit* target){
	std::cout<<this->name<<" attacks!"<<std::endl;
	target->ModifyHealth(this->damage);
}

void CombatUnit::UseItem(Item* item, CombatUnit* target){
	std::cout<<this->name<<" uses "<<item->GetName()<<std::endl;
	item->Effect(target);
}


void CombatUnit::PrintStats(){
	std::cout<<this->name<<"'s health: "<<this->health<<"\tDamage: "<<this->damage<<std::endl;
}