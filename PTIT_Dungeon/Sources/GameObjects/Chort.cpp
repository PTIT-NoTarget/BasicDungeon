#include "Chort.h"
#include "ChortSRun.h"
#include "ChortSIdle.h"

Chort::Chort() {
	m_nextState = IPState::SNULL;
	m_runState = new ChortSRun(this);
	m_idleState = new ChortSIdle(this);
	//m_attackState;
	m_currentState = m_runState;
}

Chort::~Chort() {
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

void Chort::changeNextState(IPState::STATE nextState) {
	m_nextState = nextState;
}

void Chort::Init() {
	printf("===============");
	m_runState->Init();
	m_idleState->Init();
	//m_attackState->Init();

	m_HitBox = new HitBox(sf::Vector2i(22, 42));
	m_HitBox->setPosition(screenWidth / 2, screenHeight / 2 - 100);
	m_HitBox->Init(sf::Vector2f(200, 500));
	m_HitBox->SetTag(CHORT);

}

void Chort::Update(float deltaTime) {
	performStateChange();
	m_currentState->Update(deltaTime);
}

void Chort::Render(sf::RenderWindow* window) {
	m_currentState->Render(window);
	window->draw(*m_HitBox);
}

HitBox* Chort::getHitBox() {
	return m_HitBox;
}

void Chort::performStateChange() {
	if (m_nextState != IPState::SNULL) {
		switch (m_nextState) {
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
