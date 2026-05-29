#include "Grid.h"
#include "Tower.h"
#include <SFML/System/Vector2.hpp>

Grid::Grid()
{
	for (int i{}; i < s_lane_count; ++i)
	{
		m_lanes[i].row = i;
	}
}

sf::Vector2f Grid::grid_to_pos(const sf::Vector2i &grid_pos) const
{
	float x = grid_pos.x * s_cell_size + (s_cell_size / 2.f);
	float y = grid_pos.y * s_cell_size + (s_cell_size / 2.f);

	return sf::Vector2f{ x, y };
}

sf::Vector2i Grid::pos_to_grid(const sf::Vector2f &pos) const
{
	int x = static_cast<int>(pos.x / s_cell_size);
	int y = static_cast<int>(pos.y / s_cell_size);

	return sf::Vector2i{ x, y };
}

bool Grid::is_empty(const sf::Vector2i &grid_pos) const
{
	for (const auto &tower : m_lanes[grid_pos.y].towers)
	{
		if (tower.col == grid_pos.x)
		{
			return false;
		}
	}

	return true;
}

void Grid::place_tower(const sf::Vector2i &grid_pos)
{
	int lane = grid_pos.y;
	int col = grid_pos.x;

	m_lanes[lane].towers.push_back(make_tower(TowerType::Cannon, col));
}

const std::array<Lane, Grid::s_lane_count> &Grid::get_lanes()
{
	return m_lanes;
}