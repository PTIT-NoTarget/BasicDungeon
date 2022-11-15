#pragma once
#include "../GameManager/ResourceManager.h"
#include "BlockCollisionManager.h";

class Wall {
private:
	HitBox m_HitBox;
public:
	Wall();
	Wall(std::string link,sf::Vector2f size, sf::Vector2f position);
	~Wall();
	void Render(sf::RenderWindow* window);
	BlockCollisionManager GetBlockCollider() { return BlockCollisionManager(m_HitBox); }
};