#include "PSAttack.h"

PSAttack::PSAttack(IPlayer* player) {
	m_Player = player;
}

void PSAttack::Init() {
	m_Animation = new Animation(*DATA->getTexture("Player/adam_attack"), sf::Vector2i(5, 1), 0.1f);
}

void PSAttack::Update(float deltaTime) {
	m_Animation->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		m_Player->changeNextState(RUN);
	}
	m_Animation->setPosition(m_Player->getHitBox()->getPosition());
}

void PSAttack::Render(sf::RenderWindow* window) {
	window->draw(*m_Animation);
}

void PSAttack::Reset() {
	m_Animation->Reset();
}


