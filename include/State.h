#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>



class State
{
public:
	virtual ~State() = default;
	State() = default;

	virtual void handle_event(const sf::Event &event) = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderWindow &window) = 0;

};
