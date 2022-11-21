#include "ModCollisionManager.h"

ModCollisionManager::ModCollisionManager() {
	
}

ModCollisionManager::~ModCollisionManager() {

}

void ModCollisionManager::addObj(HitBox* hitBox) {

	m_listObj.push_back(hitBox);
}

bool ModCollisionManager::checkCollision(HitBox* a, HitBox* b) {
	return a->getGlobalBounds().intersects(b->getGlobalBounds());;
}

void ModCollisionManager::Update(HitBox* player) {
	for (auto a : m_listObj) {
		if (a->isAlive() == false) continue;
		if (checkCollision(a, player) == 1) {
			a->setHealth(a->getHealth() - 1);
		}
	}
}