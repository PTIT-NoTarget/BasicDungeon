#include "ChortSRun.h"

ChortSRun::ChortSRun(ICreep* Chort) {
	m_Chort = Chort;
}

void ChortSRun::Init() {
	m_Animation = new Animation(*DATA->getTexture("Creep/Chort_run"), sf::Vector2i(4, 1), 0.1f);
}

void ChortSRun::Update(float deltaTime) {
	m_Animation->Update(deltaTime);
	m_Chort->changeNextState(IDLE);
	m_Animation->setPosition(m_Chort->getHitBox()->getPosition());
}

void ChortSRun::Render(sf::RenderWindow* window) {
	window->draw(*m_Animation);
}

void ChortSRun::Reset() {
	m_Animation->Reset();
}


