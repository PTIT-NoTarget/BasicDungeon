#pragma once
#include "../GameManager/ResourceManager.h"
enum TAG
{
	PLAYER,
	CHORT,
	BULLET
};
class HitBox :public sf::RectangleShape{
public:
	HitBox();
	HitBox(sf::Vector2i size);
	~HitBox();
	void Init(sf::Vector2f velocity);

	sf::Vector2f getVelocity();
	void setVelocity(sf::Vector2f velocity);

	bool isAlive();
	int getHealth();
	void setHealth(int health);
	
	TAG getTag() { return m_Tag; };
	void SetTag(TAG tag) { m_Tag = tag; }
private:
	int m_isHealth;
	sf::Vector2f m_Velocity;
	TAG m_Tag;
};