#include "World.h"
#include "Tower.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>

void World::update(float dt)
{
}

void World::render(sf::RenderWindow &window)
{
	auto &lanes = m_grid.get_lanes();

	for (const auto &lane : lanes)
	{
		for (auto tower : lane.towers)
		{
			draw_tower(window, { tower.col, lane.row }, tower);
		}

		for (auto &enemy : lane.enemies)
		{
			draw_enemy(window, enemy);
		}
	}
}

bool World::try_place_tower(const sf::Vector2f &mous_pos, TowerType)
{
	return true;
}

bool World::try_place_tower(const sf::Vector2i &grid_pos, TowerType)
{
	m_grid.place_tower(grid_pos);
	return true;
}

void World::draw_tower(sf::RenderWindow &window,
											 const sf::Vector2i &pos,
											 Tower tower)
{
	sf::CircleShape circle(10);
	switch (tower.type)
	{
	case TowerType::Cannon:
		circle.setFillColor(sf::Color::Red);
		circle.setOrigin({ 10, 10 });
		circle.setPosition(m_grid.grid_to_pos(pos));
		window.draw(circle);
		break;
	case TowerType::Minigunner:
		break;
	case TowerType::Mortar:
		break;
	}
}

void World::draw_enemy(sf::RenderWindow &window, Enemy)
{
}