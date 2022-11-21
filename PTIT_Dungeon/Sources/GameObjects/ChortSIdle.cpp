#include "ChortSIdle.h"

ChortSIdle::ChortSIdle(ICreep* chort) {
	m_Chort = chort;
}

void ChortSIdle::Init() {
	m_Animation = new Animation(*DATA->getTexture("Creep/Chort_idle"), sf::Vector2i(4, 1), 0.1f);
}

void ChortSIdle::Update(float deltaTime) {
	m_Animation->Update(deltaTime);
	m_Chort->changeNextState(IDLE);
	m_Animation->setPosition(m_Chort->getHitBox()->getPosition());
}

void ChortSIdle::Render(sf::RenderWindow* window) {
	window->draw(*m_Animation);
}

void ChortSIdle::Reset() {
	m_Animation->Reset();
}


