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
	curTime = 0.f;
	m_Player.Init();
	tutorialMap.Init();
	m_Chort.Init();
	m_Chort.getHitBox()->setHealth(5);
	m_ModCollisionManager.addObj(m_Chort.getHitBox());
	playerView.setSize(screenWidth, screenHeight);
}

void GSPlay::Update(float deltaTime) {
	playerView.setCenter(m_Player.getHitBox()->getPosition());
	m_Player.Update(deltaTime,m_Chort.getHitBox());
	if (m_Chort.getHitBox()->isAlive()) {
		//printf("%d\n",m_Chort.getHitBox()->getHealth());
		m_Chort.Update(deltaTime);
	}
	m_Wall = tutorialMap.getWall();
	curTime += deltaTime;
	if (curTime >= 0.2f) {
		curTime = 0.f;
		m_ModCollisionManager.Update(m_Player.getHitBox());
	}
	for(auto wall : m_Wall){
		wall->GetBlockCollider().checkBlockCollider(m_Player.GetBlockCollider());
	}
}

void GSPlay::Render(sf::RenderWindow* window) {
	window->setView(playerView);
	tutorialMap.Render(window);
	m_Player.Render(window);
	if (m_Chort.getHitBox()->isAlive()) {
		m_Chort.Render(window);
	}
}
