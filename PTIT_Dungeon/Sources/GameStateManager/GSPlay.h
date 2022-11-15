#pragma once
#include "GameStateBase.h"
#include "../GameObjects/Player.h"
#include "../GameObjects/Tutorial_Map.h"
#include "../GameObjects/Chort.h"
#include "../GameObjects/ModCollisionManager.h"

class GSPlay : public GameStateBase {
public:
	GSPlay();
	virtual ~GSPlay();

	void Exit();
	void Pause();
	void Resume();

	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::View view;
	std::vector <Wall*> m_Wall;
	ModCollisionManager m_ModCollisionManager;
	Player m_Player;
	Chort m_Chort;
	TutorialMap tutorialMap;
};