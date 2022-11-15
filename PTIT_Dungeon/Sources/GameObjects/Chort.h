#pragma once
#include "IPlayer.h"

class Chort : public IPlayer {
public:
	Chort();
	~Chort();
	void changeNextState(IPState::STATE nextState);

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	HitBox* getHitBox();
	BlockCollisionManager GetCollider() { return BlockCollisionManager(*m_HitBox); }
private:
	void performStateChange();
	HitBox* m_HitBox;

	IPState::STATE m_nextState;
	IPState* m_currentState;
	IPState* m_idleState;
	IPState* m_runState;
	IPState* m_attackState;
};