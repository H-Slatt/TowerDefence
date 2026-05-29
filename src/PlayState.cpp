#include "PlayState.h"
#include "Tower.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

PlayState::PlayState()
{

	for (int y{}; y <= 4; ++y)
	{
		m_world.try_place_tower(sf::Vector2i{ 0, y }, TowerType::Cannon);
		m_world.try_place_tower(sf::Vector2i{ 9, y }, TowerType::Cannon);
	}

	for (int x{ 1 }; x <= 8; ++x)
	{
		m_world.try_place_tower(sf::Vector2i{ x, 0 }, TowerType::Cannon);
		m_world.try_place_tower(sf::Vector2i{ x, 4 }, TowerType::Cannon);
	}

	for (int y{}; y < 4; ++y)
	{
		for (int x{}; x < 9; ++x)
		{
			m_world.try_place_tower(sf::Vector2i{ x, y }, TowerType::Cannon);
		}
	}
}

void PlayState::handle_event(const sf::Event &event)
{
}

void PlayState::update(float dt)
{
	m_world.update(dt);
}

void PlayState::render(sf::RenderWindow &winodow)
{
	m_world.render(winodow);
}