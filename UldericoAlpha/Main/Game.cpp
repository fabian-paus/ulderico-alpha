#include "Game.h"

#include "MenuBehaviour.h"
#include "InGameBehaviour.h"
#include "Shield.h"
#include "Bullet.h"

namespace UldericoAlpha
{
	Game::Game() 
		: m_window(sf::VideoMode(775, 572), "SFML window"),
		m_gameState(GameState_Menu)
	{
		std::vector<Behaviour*>::iterator behaviour_it;
		behaviour_it = m_behaviours.begin();
		behaviour_it = m_behaviours.insert(behaviour_it, new MenuBehaviour(*this, m_resources));
		
		behaviour_it = m_behaviours.insert(behaviour_it, new InGameBehaviour(*this, m_resources));

		//Nur zu Testzwecke später eventuell andere Implementierung
		std::vector<Element*>::iterator element_it;
		element_it = m_elements.begin();

		element_it = m_elements.insert(element_it, new Shield(80, 420));
		element_it = m_elements.insert(element_it, new Shield(260, 420));
		element_it = m_elements.insert(element_it, new Shield(440, 420));
		element_it = m_elements.insert(element_it, new Shield(620, 420));
		
		srand(time(NULL));
		for(int i = 0; i < 40; i++)
		{
			int speed = (rand() % 9 + 1) + 1;
			speed = (rand() % 1 + 1) == 1 ? speed : -speed;
			element_it = m_elements.insert(element_it, new Bullet(rand() % 775, rand() % 572, speed));
		}
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

				m_behaviours.at(m_gameState)->OnEvent(event);
			}

			// TODO: Logik-Ticks einbauen
			m_behaviours.at(m_gameState)->Update();

			// Clear screen
			m_window.Clear();

			m_behaviours.at(m_gameState)->Render(m_window);

			// Update the window
			m_window.Display();
		}
	}

	void Game::ChangeState(GameStates newState)
	{

	}
}