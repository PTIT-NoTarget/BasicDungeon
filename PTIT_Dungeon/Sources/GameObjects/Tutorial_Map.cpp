#include "Tutorial_Map.h"

TutorialMap::TutorialMap() {

}

TutorialMap::~TutorialMap() {

}

void TutorialMap::Init() {
	map_ID = { {0, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 0, 0, 0, 0, 0, 0, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 0},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 0, 0, 0, 0, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 0, 0, 0, 0, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 0, 0, 0, 0, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 34, 34, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 34, 34, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 0, 0, 0, 0, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 0, 0, 0, 0, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34, 0, 0, 0, 0, 34, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 34},
			{0, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 0, 0, 0, 0, 0, 0, 34, 34, 34, 34, 34, 34, 34, 34, 34, 34, 0} };
	tutorial_map.assign(12, std::vector <Wall*>(28));
	for (int i = 0; i < map_ID.size(); i++) {
		for (int j = 0; j < map_ID[i].size(); j++) {
			tutorial_map[i][j] = new Wall("Map/tutorial/Map" + std::to_string(map_ID[i][j]), sf::Vector2f(32.f, 32.f), sf::Vector2f(50 + j * 32.f, 100 + i * 32.f));
			if (map_ID[i][j] == 34) {
				m_wall.push_back(tutorial_map[i][j]);
			}
		}
	}
}

void TutorialMap::Render(sf::RenderWindow* window) {
	for (int i = 0; i < map_ID.size(); i++) {
		for (int j = 0; j < map_ID[i].size(); j++) {
			tutorial_map[i][j]->Render(window);
		}
	}
}

std::vector <Wall*> TutorialMap::getWall() {
	return m_wall;
}
