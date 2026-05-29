#include "Tower.h"

Tower make_tower(TowerType type, int col)
{
	switch (type)
	{
	case TowerType::Cannon:
		return Tower{ .col = col,
									.hp = 100,
									.range = 0.7f,
									.max_cooldown = 5.f,
									.damage = 100,
									.type = type };
	case TowerType::Minigunner:
		return Tower{ .col = col,
									.hp = 4,
									.range = 0.5f,
									.max_cooldown = 0.3333f,
									.damage = 30,
									.type = type };
	case TowerType::Mortar:
		return Tower{ .col = 0, .max_cooldown = 10.f, .damage = 20, .type = type };
	}

	return Tower{};
}