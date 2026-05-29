#include "App.h"
#include "StateManager.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <optional>

App::App() :
		m_window(sf::VideoMode({ m_win_width, m_win_height }), "Tower Defence Game")
{
	m_clock.restart();
}

void App::run()
{
	m_state_manager.push_state(StateType::PlayState);

	while (m_window.isOpen())
	{
		dt = m_clock.restart().asSeconds();

		m_window.clear();

		handle_events();
		update();
		render();

		m_window.display();
	}
}

void App::shutdown()
{
	m_window.close();
}

void App::handle_events()
{
	while (const auto &event = m_window.pollEvent())
	{
		if (event->is<sf::Event::Closed>())
		{
			shutdown();
		}

		if (event.has_value())
		{
			m_state_manager.handle_event(*event);
		}
	}
}

void App::update()
{
	m_state_manager.update(dt);
	m_state_manager.apply_changes();
}

void App::render()
{
	m_state_manager.render(m_window);
}