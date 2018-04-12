#include "Player.hpp"
#include <string>
using std::string;

Player::Player( int health, int damage,string name)
: CombatUnit( health, damage,name)
{

}
/*
//int Player::GetHealth() {
	//return this->health;
//

//int Player::GetDamage() {
//	return this->damage;
//}



void Player::ModifyHealth(int amount){
	this->health -= amount;
}

void Player::DealDamage(CombatUnit* target){
	std::cout<<this->name<<" attacks!"<<std::endl;
	target->ModifyHealth(this->damage);
}



void Player::UseItem(Item* item, CombatUnit* target){
	std::cout<<this->name<<" uses "<<item->GetName()<<std::endl;
	item->Effect(target);
}

void Player::PrintStats(){
	std::cout<<this->name<<"'s health: "<<this->health<<"\tDamage: "<<this->damage<<std::endl<<std::endl;
}

void Player::AddItemToInventory(Item* item){
	this->inventory.push_back(item);
}
*/
