#include "Player.h"
#include "PSRun.h"
#include "PSIdle.h"

Player::Player()
{
	m_nextState = IPState::SNULL;
	m_runState = new PSRun(this);
	m_idleState = new PSIdle(this);
	//m_attackState;
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
	//if (m_attackState != nullptr) {
	//	delete m_attackState;
	//}
	m_currentState = nullptr;

}

void Player::changeNextState(IPState::STATE nextState)
{
	m_nextState = nextState;
}

void Player::Init()
{
	m_runState->Init();
	m_idleState->Init();
	//m_attackState->Init();

	m_HitBox = new HitBox(sf::Vector2i(32, 46));
	m_HitBox->setPosition(screenWidth/2,screenHeight/2);
	m_HitBox->Init(sf::Vector2f(200, 500));
	m_HitBox->SetTag(PLAYER);
	
}

void Player::Update(float deltaTime)
{
	performStateChange();
	m_currentState->Update(deltaTime);
}

void Player::Render(sf::RenderWindow* window)
{
	m_currentState->Render(window);
	window->draw(*m_HitBox);
}

HitBox* Player::getHitBox()
{
	return m_HitBox;
}

void Player::performStateChange()
{
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState)
		{
		case IPState::RUN:
			m_currentState = m_runState;
			break;
		case IPState::IDLE:
			m_currentState = m_idleState;
			break;
		//case IPState::ATTACK:
		//	m_currentState = m_attackState;
			//break;
		default:
			break;
		}
		m_nextState = IPState::SNULL;
		m_currentState->Reset();
	}
}
