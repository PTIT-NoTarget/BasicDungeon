#pragma once
#include "HitBox.h"

class ModCollisionManager {
public:
	ModCollisionManager();
	~ModCollisionManager();
	void addObj(HitBox* hitBox);
	bool checkCollision(HitBox* a, HitBox* b);
	void Update(HitBox* player);
private:
	std::vector<HitBox*> m_listObj;
};