#pragma once

#include "Enemy.h"
#include "Tower.h"
#include <SFML/System/Vector2.hpp>
#include <array>
#include <vector>

struct Lane
{
	int row;
	std::vector<Enemy> enemies;
	std::vector<Tower> towers;
};

class Grid
{
public:
	inline static const int s_lane_count{ 5 };
	inline static const int s_col_count{ 9 };
	inline static const int s_cell_size{ 150 };

public:
	~Grid() = default;
	Grid();

	sf::Vector2i pos_to_grid(const sf::Vector2f &pos) const;
	sf::Vector2f grid_to_pos(const sf::Vector2i &grid_pos) const;
	bool is_empty(const sf::Vector2i &grid_pos) const;

	void place_tower(const sf::Vector2i &grid_pos);

	const std::array<Lane, s_lane_count> &get_lanes();

private:
	std::array<Lane, s_lane_count> m_lanes;
};