#pragma once
#include "../GameManager/ResourceManager.h"
#include "Hitbox.h"
#include "ModCollisionManager.h"

class Bullet {
public:
	Bullet();
	Bullet(sf::Vector2f point);
	~Bullet();
	void Update(float deltaTime, HitBox* m_Creep);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox();
	bool isStop();
private:
	bool m_Stop;
	ModCollisionManager m_Collison;
	sf::Vector2f startPoint;
	HitBox* m_HitBox;
	Animation* m_currentState;
	Animation* m_startState;
	Animation* m_runState;
	Animation* m_endState;
};