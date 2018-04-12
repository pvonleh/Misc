#ifndef GAMEWORLD_HPP
#define GAMEWORLD_HPP

#include "Player.hpp"
#include "Enemy.hpp"
#include "Potion.hpp"
#include "Grenade.hpp"
#include "Item.hpp"
#include "Orc.hpp"
#include "Goblin.hpp"
#include <vector>

class GameWorld {
public:
	GameWorld(Player* player);
	void AddEnemy(Enemy* enemy);
	void AddItem(Item* item);
	void ListEnemies();
	void ListItems();
	void SimulateExample();
private:
	Player* player;
	std::vector<Enemy*> enemiesInWorld;
	std::vector<Item*> itemsInWorld;
};

#endif