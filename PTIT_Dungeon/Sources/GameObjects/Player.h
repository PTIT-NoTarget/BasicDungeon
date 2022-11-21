#pragma once
#include "IPlayer.h"
#include "Bullet.h"

class Player: public IPlayer
{
public:
	Player();
	~Player();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime, HitBox* modHitBox);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox();
	BlockCollisionManager GetBlockCollider() { return BlockCollisionManager(*m_HitBox); }
private:
	void performStateChange(float deltaTime);
	HitBox* m_HitBox;
	
	IPState::STATE m_nextState;
	IPState* m_currentState;
	IPState* m_idleState;
	IPState* m_runState;
	IPState* m_attackState;

	bool isShooting;
	float curTime;
	std::vector <Bullet*> m_Bullet;
};