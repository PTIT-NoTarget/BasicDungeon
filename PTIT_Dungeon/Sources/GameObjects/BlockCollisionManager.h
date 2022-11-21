#pragma once
#include "HitBox.h"

class BlockCollisionManager {
public:
	BlockCollisionManager(HitBox &hitBox);
	~BlockCollisionManager();
	void Move(float dx, float dy) { hitBox.move(dx, dy); }
	bool checkBlockCollider(BlockCollisionManager other);
	sf::Vector2f GetPosition() { return hitBox.getPosition(); }
	sf::Vector2f GetHalfSize() { return hitBox.getSize() / 2.f; }
private:
	HitBox& hitBox;
};