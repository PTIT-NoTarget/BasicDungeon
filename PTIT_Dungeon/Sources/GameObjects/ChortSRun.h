#pragma once
#include "IPState.h"
#include "ICreep.h"

class ChortSRun :public IPState {
public:
	ChortSRun(ICreep* chort);
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	void Reset();

private:
	ICreep* m_Chort;
	Animation* m_Animation;

};