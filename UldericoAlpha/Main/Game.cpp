#include "Game.h"

#include "MenuBehaviour.h"

using namespace UldericoAlpha;

Game::Game() 
	: m_window(sf::VideoMode(775, 572), "SFML window")
{
	m_behaviour = new MenuBehaviour(*this, m_resources);
}

void Game::StartGameLoop()
{
	// Start the game loop
	while (m_window.IsOpen())
	{
		// Process events
		sf::Event event;
		while (m_window.PollEvent(event))
		{
			// Close window : exit
			if (event.Type == sf::Event::Closed)
				m_window.Close();

			m_behaviour->OnEvent(event);
		}

		// TODO: Logik-Ticks einbauen
		m_behaviour->Update();

		// Clear screen
		m_window.Clear();

		m_behaviour->Render(m_window);

		// Update the window
		m_window.Display();
	}
}

void Game::ChangeState(GameStates newState)
{

}
