#include "Bullet.h"

Bullet::Bullet() {
	
}

Bullet::Bullet(sf::Vector2f point) {
	m_Stop = false;
	m_HitBox = new HitBox(sf::Vector2i(16, 16));
	m_HitBox->Init(sf::Vector2f(200, 500));
	m_HitBox->setTexture(DATA->getTexture("Player/bullet"));
	m_HitBox->setHealth(1);
	m_HitBox->setPosition(point);
	m_HitBox->SetTag(BULLET);
}

Bullet::~Bullet() {

}

void Bullet::Update(float deltaTime, HitBox* m_Creep) {
	printf("%f %f\n", m_Creep->getPosition().x, m_Creep->getPosition().y);
	if (m_Collison.checkCollision(m_Creep, m_HitBox) == 0) {
		m_HitBox->move(-100*deltaTime, -100*deltaTime);
	}
	else {
		m_Stop = true;
		m_Creep->setHealth(m_Creep->getHealth() - 1);
	}
}

void Bullet::Render(sf::RenderWindow* window) {
	window->draw(*m_HitBox);
}

HitBox* Bullet::getHitBox() {
	return m_HitBox;
}

bool Bullet::isStop() {
	return m_Stop;
}
