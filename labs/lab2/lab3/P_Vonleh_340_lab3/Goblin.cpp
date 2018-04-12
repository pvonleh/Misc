#include "Goblin.hpp"

Goblin::Goblin() : Enemy(this->defaultHealth, this->defaultDamage, "Goblin"){

}

Goblin::Goblin(int health, int damage) : Enemy(health, damage, "Goblin"){

}

void Goblin::Flee(){
	std::cout<<"The goblin flees!"<<std::endl;
}

void Goblin::Spawn(GameWorld* gameWorld){
	gameWorld->AddEnemy(new Goblin(this->defaultHealth, this->defaultDamage));
}