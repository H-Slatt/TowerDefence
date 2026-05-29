#pragma once

#include "State.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <vector>

enum class StateType
{
	PlayState = 0,
	MainMenu,
	Pause
};

enum class Change
{
	Push = 0,
	Pop
};

struct PendingChange
{
	Change change;
	StateType state;
};

class StateManager
{
public:
	StateManager() = default;
	~StateManager() = default;

	void push_state(StateType);
	void pop_state();
	void apply_changes();

	void handle_event(const sf::Event &event);
	void update(float dt);
	void render(sf::RenderWindow &window);

private:
	std::vector<std::unique_ptr<State>> m_states;
	std::vector<PendingChange> m_pending;

	std::unique_ptr<State> create_state(StateType state);
};