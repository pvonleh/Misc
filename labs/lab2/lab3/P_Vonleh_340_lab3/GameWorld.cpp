#include "GameWorld.hpp"

GameWorld::GameWorld(Player* player) {
	this->player = player;
}

void GameWorld::AddEnemy(Enemy* enemy) {
	this->enemiesInWorld.push_back(enemy);
}

void GameWorld::AddItem(Item* item) {
	this->itemsInWorld.push_back(item);
}

void GameWorld::ListEnemies() {
	int counter = 1;
	for (Enemy* enemy : this->enemiesInWorld) {
		std::cout << "Enemy " << counter << ": ";
		enemy->PrintStats();
		counter++;
	}
	std::cout << std::endl;
}

void GameWorld::ListItems() {
	int counter = 1;
	for (Item* item : this->itemsInWorld) {
		std::cout << "Item " << counter << ": ";
		item->PrintData();
		counter++;
	}
	std::cout << std::endl;
}

void GameWorld::SimulateExample() {
	std::cout << "\t\tPlayer & Lists" << std::endl;
	this->player->PrintStats();
	this->ListItems();
	this->ListEnemies();

	std::cout << "\t\tBegin Simulation" << std::endl<<std::endl;

	//Player attacks Enemy 1
	this->player->DealDamage(this->enemiesInWorld[0]);

	this->ListEnemies();

	//Player grenades Enemy 2
	this->player->UseItem(this->itemsInWorld[1], this->enemiesInWorld[1]);

	this->ListEnemies();

	//Enemy 1 grenades the player
	this->enemiesInWorld[0]->UseItem(this->itemsInWorld[1], this->player);

	this->player->PrintStats();

	//Enemy 2 Potions Enemy 1
	this->enemiesInWorld[1]->UseItem(this->itemsInWorld[0], this->enemiesInWorld[0]);

	this->ListEnemies();

	//Enemy 1 attacks the player
	this->enemiesInWorld[0]->DealDamage(this->player);

	this->player->PrintStats();

	//Enemy 2 attacks the player
	this->enemiesInWorld[1]->DealDamage(this->player);

	this->player->PrintStats();

	//Player uses potion on himself
	this->player->UseItem(this->itemsInWorld[0], this->player);

	this->player->PrintStats();

}