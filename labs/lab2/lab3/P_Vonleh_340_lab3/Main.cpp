#include "Player.hpp"
#include "GameWorld.hpp"
#include "Potion.hpp"
#include "Grenade.hpp"

int main(){
	GameWorld gw(new Player(20, 5,"Finn"));

	Spawnable* spawnables[4];// = new Spawnable*[4];
	spawnables[0] = new Potion();
	spawnables[1] = new Grenade();
	spawnables[2] = new Orc();
	spawnables[3] = new Goblin();

	int counters[4] = {1, 1, 1, 1};

	int currSpawnable = 0;
	for(Spawnable* spawner : spawnables){
		for(int i = 0; i < counters[currSpawnable]; i++){
			spawner->Spawn(&gw);
		}
		currSpawnable++;
	}

	gw.SimulateExample();
}