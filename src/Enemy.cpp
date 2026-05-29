#include "Enemy.h"

Enemy make_enemy(EnemyType type, float start_x)
{
	switch (type)
	{
	case EnemyType::Basic:
		return Enemy{ .pos = { start_x, 0.f },
									.speed = 60.f,
									.hp = 100.f,
									.maxHp = 100.f,
									.type = EnemyType::Basic };
	case EnemyType::Fast:
		return Enemy{ .pos = { start_x, 0.f },
									.speed = 120.f,
									.hp = 50.f,
									.maxHp = 50.f,
									.type = EnemyType::Fast };
	case EnemyType::Tank:
		return Enemy{ .pos = { start_x, 0.f },
									.speed = 30.f,
									.hp = 300.f,
									.maxHp = 300.f,
									.type = EnemyType::Tank };
	}
}