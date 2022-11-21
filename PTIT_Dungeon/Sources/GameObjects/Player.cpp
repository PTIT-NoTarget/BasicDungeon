#include "Player.h"
#include "PSRun.h"
#include "PSIdle.h"

Player::Player()
{
	m_nextState = IPState::SNULL;
	m_runState = new PSRun(this);
	m_idleState = new PSIdle(this);
	m_currentState = m_runState;
}

Player::~Player()
{
	if (m_runState != nullptr) {
		delete m_runState;
	}
	if (m_idleState != nullptr) {
		delete m_idleState;
	}
	m_currentState = nullptr;

}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void Player::Init()
{
	curTime = 0;
	m_runState->Init();
	m_idleState->Init();
	m_HitBox = new HitBox(sf::Vector2i(32, 46));
	m_HitBox->setPosition(screenWidth/2,screenHeight/2);
	m_HitBox->Init(sf::Vector2f(200, 500));
	m_HitBox->SetTag(PLAYER);	
}

void Player::Update(float deltaTime, HitBox* modHitBox)
{
	performStateChange(deltaTime);
	for (int i = m_Bullet.size() - 1; i >= 0; i--) {
		if (m_Bullet[i]->isStop() == 1) {
			m_Bullet.erase(m_Bullet.begin() + i);
		}
	}
	if (modHitBox->isAlive()) {
		isShooting = true;
		for (int i = m_Bullet.size() - 1; i >= 0; i--) {
			if (m_Bullet[i] != nullptr) {
				m_Bullet[i]->Update(deltaTime, modHitBox);
			}
		}
	}
	else {
		isShooting = false;
	}
	m_currentState->Update(deltaTime);
}

void Player::Render(sf::RenderWindow* window)
{
	for (auto bullet : m_Bullet) {
		if (bullet != nullptr) {
			bullet->Render(window);
		}
	}
	m_currentState->Render(window);
	window->draw(*m_HitBox);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}

void Player::performStateChange(float deltaTime)
{
	curTime += deltaTime;
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::IDLE:
			m_currentState = m_idleState;
			if (curTime >= 1.f && isShooting == true) {
				curTime = 0.f;
				m_Bullet.push_back(new Bullet(m_HitBox->getPosition()));
			}
			break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}
}
