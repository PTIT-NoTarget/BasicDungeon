#pragma once
#include "IPState.h"
#include "IPlayer.h"

class ChortSRun :public IPState {
public:
	ChortSRun(IPlayer* chort);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	IPlayer* m_Chort;
	Animation* m_Animation;

};