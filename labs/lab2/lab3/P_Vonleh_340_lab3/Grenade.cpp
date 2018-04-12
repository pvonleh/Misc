#include "Grenade.hpp"

Grenade::Grenade() : Item("Grenade", "Damages the target for 5hp.") {

}

void Grenade::Effect(CombatUnit* target){
	target->ModifyHealth(5);
}

void Grenade::Spawn(GameWorld* gameWorld){
	gameWorld->AddItem(new Grenade());
}