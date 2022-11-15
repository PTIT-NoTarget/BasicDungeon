#pragma once
#include "IPState.h"
#include "IPlayer.h"

class ChortSIdle :public IPState {
public:
	ChortSIdle(IPlayer* chort);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Chort;
	Animation* m_Animation;

};