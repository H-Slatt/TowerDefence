#include "StateManager.h"
#include "PlayState.h"
#include "State.h"
#include <SFML/Window/Event.hpp>
#include <memory>

void StateManager::push_state(StateType type)
{
	m_pending.push_back(PendingChange{ .change = Change::Push, .state = type });

}

void StateManager::pop_state()
{
	m_pending.push_back(PendingChange{ .change = Change::Pop });
}

void StateManager::apply_changes()
{
	if (m_pending.empty())
		return;

	for (auto &change : m_pending)
	{
		switch (change.change)
		{
		case Change::Push:
			m_states.push_back(create_state(change.state));

			break;

		case Change::Pop:
			m_states.pop_back();
			break;
		}
	}
}

void StateManager::handle_event(const sf::Event &event)
{
	for (auto &state : m_states)
	{
		state->handle_event(event);
	}
}

void StateManager::update(float dt)
{
	for (auto &state : m_states)
	{
		state->update(dt);
	}
}

void StateManager::render(sf::RenderWindow &window)
{
	for (auto &state : m_states)
	{
		state->render(window);
	}
}

std::unique_ptr<State> StateManager::create_state(StateType state)
{
	switch (state)
	{
	case StateType::PlayState:
		return std::make_unique<PlayState>();
	case StateType::MainMenu:
		return std::make_unique<PlayState>();
	case StateType::Pause:
		return std::make_unique<PlayState>();
	}
}