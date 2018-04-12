#include "Enemy.hpp"
#include <string>
using std::string;

Enemy::Enemy( int health, int damage,string name) 
: CombatUnit( health, damage,name)
{
	//this->health = health;
	//this->damage = damage;
	//this->name = name;
}
/*

int Enemy::GetHealth() {
	return this->health;
}

int Enemy::GetDamage() {
	return this->damage;
}


void Enemy::ModifyHealth(int amount){
	this->health -= amount;
}
void Enemy::DealDamage(CombatUnit* target){
	std::cout<<this->type<<" attacks!"<<std::endl;
	target->ModifyHealth(this->damage);
}


void Enemy::UseItem(Item* item, CombatUnit* target){
	std::cout<<this->type<<" uses "<<item->GetName()<<std::endl;
	item->Effect(target);
}

void Enemy::PrintStats(){
	std::cout<<this->type<<"'s health: "<<this->health<<"\tDamage: "<<this->damage<<std::endl;
}

*/