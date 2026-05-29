#pragma once

enum class TowerType
{
	Cannon = 0,
	Minigunner,
	Mortar,
};

struct Tower
{
  int col;
  int hp;
  float range;
	float max_cooldown;
  int damage;
  TowerType type;
  float fire_cooldown = max_cooldown;
};

Tower make_tower(TowerType type, int col);
int tower_cost(TowerType type);