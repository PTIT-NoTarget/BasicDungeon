#pragma once
#include "../GameManager/ResourceManager.h"
#include "Wall.h"
#include <vector>
#include <iostream>
#include <cstring>

class TutorialMap {
private:
	std::vector <std::vector<int>> map_ID;
	std::vector <std::vector<Wall*>> tutorial_map;
	std::vector <Wall*> m_wall;
public:
	TutorialMap();
	~TutorialMap();
	void Init();
	void Render(sf::RenderWindow* window);
	std::vector <Wall*> getWall();
};