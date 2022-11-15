#include "Wall.h"

Wall::Wall() {

}

Wall::Wall(std::string link, sf::Vector2f size, sf::Vector2f position) {
	m_HitBox.setTexture(DATA->getTexture(link));
	m_HitBox.setOrigin(size / 2.f);
	m_HitBox.setSize(size);
	m_HitBox.setPosition(position);
}

Wall::~Wall() {
}

void Wall::Render(sf::RenderWindow* window) {
	window->draw(m_HitBox);
}
