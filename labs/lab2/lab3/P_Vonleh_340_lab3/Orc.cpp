#include "Orc.hpp"

Orc::Orc() : Enemy(this->defaultHealth, this->defaultDamage, "Orc") {

}

Orc::Orc(int health, int damage) : Enemy(health, damage, "Orc"){

}

void Orc::BullRush(){
	std::cout<<"The orc rushes!"<<std::endl;
}

void Orc::Spawn(GameWorld* gameWorld){
	gameWorld->AddEnemy(new Orc(this->defaultHealth, this->defaultDamage));
}