#include "Potion.hpp"

Potion::Potion() : Item("Potion", "Restores 5hp to the target.") {

}

void Potion::Effect(CombatUnit* target){
	target->ModifyHealth(-5);
}

void Potion::Spawn(GameWorld* gameWorld){
	gameWorld->AddItem(new Potion());
}