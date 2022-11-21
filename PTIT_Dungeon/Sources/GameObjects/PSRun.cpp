#include "PSRun.h"

PSRun::PSRun(IPlayer* player) {
	m_Player = player;
}

void PSRun::Init() {
	currentAnimation = 0;
	m_Animation[0] = new Animation(*DATA->getTexture("Player/Adam_run_up"), sf::Vector2i(6, 1), 0.1f);
	m_Animation[1] = new Animation(*DATA->getTexture("Player/Adam_run_right"), sf::Vector2i(6, 1), 0.1f);
	m_Animation[2] = new Animation(*DATA->getTexture("Player/Adam_run_down"), sf::Vector2i(6, 1), 0.1f);
	m_Animation[3] = new Animation(*DATA->getTexture("Player/Adam_run_left"), sf::Vector2i(6, 1), 0.1f);
}

void PSRun::Update(float deltaTime) {
	m_Animation[currentAnimation]->Update(deltaTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		float x = m_Player->getHitBox()->getVelocity().x * deltaTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			currentAnimation = 3;
			m_Player->getHitBox()->move(-x, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			currentAnimation = 1;
			m_Player->getHitBox()->move(x, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			currentAnimation = 0;
			m_Player->getHitBox()->move(0, -x);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			currentAnimation = 2;
			m_Player->getHitBox()->move(0, x);
		}
	}
	else {
		m_Player->changeNextState(IDLE);
	}
	m_Animation[currentAnimation]->setPosition(m_Player->getHitBox()->getPosition());
	//if (m_Player->getHitBox()->getPosition().x - screenWidth / 2 <= 0) {
	//	playerView->setCenter(screenWidth / 2, screenHeight / 2);
	//}
	//else playerView->setCenter(m_Player->getHitBox()->getPosition().x, screenHeight / 2);
}

void PSRun::Render(sf::RenderWindow* window) {
	window->draw(*m_Animation[currentAnimation]);
}

void PSRun::Reset() {
	m_Animation[currentAnimation]->Reset();
}


