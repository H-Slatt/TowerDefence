#pragma once

#include "StateManager.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>

class App
{
public:
	App();

	void run();
	void shutdown();

	void handle_events();
	void update();
	void render();

private:
	const unsigned m_win_width { 1920 };
	const unsigned m_win_height { 1080 };
	float dt;

	sf::RenderWindow m_window;
	sf::Clock m_clock;
	StateManager m_state_manager;
};