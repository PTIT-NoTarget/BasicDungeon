#include "PSIdle.h"

PSIdle::PSIdle(IPlayer* player) {
	m_Player = player;
}

void PSIdle::Init() {
	m_Animation = new Animation(*DATA->getTexture("Player/Adam_idle"), sf::Vector2i(4, 1), 0.1f);
}

void PSIdle::Update(float deltaTime) {
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_Player->changeNextState(RUN);
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSIdle::Render(sf::RenderWindow* window) {
	window->draw(*m_Animation);
}

void PSIdle::Reset() {
	m_Animation->Reset();
}


