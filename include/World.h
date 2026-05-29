#pragma once

#include "Enemy.h"
#include "Grid.h"
#include "Tower.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
class World
{
public:
	~World() = default;
	World() = default;

	void update(float dt);
	void render(sf::RenderWindow& window);

	bool try_place_tower(const sf::Vector2f &mous_pos, TowerType);
	bool try_place_tower(const sf::Vector2i &grid_pos	, TowerType);



private:
	Grid m_grid;

private:
	void draw_tower(sf::RenderWindow& window, const sf::Vector2i& pos, Tower);
	void draw_enemy(sf::RenderWindow& window, Enemy);

	void move_enemies(float dt);
};