#include "GSPlay.h"
#include <iostream>

GSPlay::GSPlay() {

}

GSPlay::~GSPlay() {
}

void GSPlay::Exit() {
}

void GSPlay::Pause() {
}

void GSPlay::Resume() {
}

void GSPlay::Init() {
	m_Player.Init();
	tutorialMap.Init();
	m_Chort.Init();
	m_ModCollisionManager.addObj(m_Chort.getHitBox());
}

void GSPlay::Update(float deltaTime) {
	m_Player.Update(deltaTime);
	if(m_Chort.getHitBox()->isAlive()) m_Chort.Update(deltaTime);
	m_Wall = tutorialMap.getWall();
	m_ModCollisionManager.Update(m_Player.getHitBox());
	for(auto wall : m_Wall){
		wall->GetBlockCollider().checkBlockCollider(m_Player.GetBlockCollider());
	}
}

void GSPlay::Render(sf::RenderWindow* window) {
	tutorialMap.Render(window);
	m_Player.Render(window);
	if (m_Chort.getHitBox()->isAlive()) m_Chort.Render(window);
}
