#pragma once

#include "State.h"
#include "World.h"

class PlayState : public State
{
public:
	PlayState();

	void handle_event(const sf::Event &event) override;
	void update(float dt) override;
	void render(sf::RenderWindow &window) override;


private:
	World m_world;

};