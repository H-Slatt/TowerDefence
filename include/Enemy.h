#pragma once

#include <SFML/System/Vector2.hpp>

enum class EnemyType
{
	Basic,
	Fast,
	Tank
};

struct Enemy
{
	sf::Vector2f pos;
	float speed;
	float hp;
	float maxHp;
	EnemyType type;
};

Enemy make_enemy(EnemyType type, float start_x);
