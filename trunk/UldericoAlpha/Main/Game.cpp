#include "Game.h"

#include "MenuBehaviour.h"
#include "InGameBehaviour.h"
#include "GameOverBehaviour.h"
#include "HighscoreBehaviour.h"

#include "Shield.h"
#include "Bullet.h"

#include <SFML/System/Clock.hpp>
#include <iostream>
#include <cstdlib>

namespace UldericoAlpha
{
    const std::string Game::WINDOW_TITLE = "UldericoAlpha 0.1 alpha ;)";

	Game::Game() 
		: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
          m_currentBehaviour(GetBehaviour(GameState_Menu))
	{ 
        // Einmalig den Zufallszahlengenerator initialieren
        std::srand(static_cast <unsigned int> (std::time(NULL)));
    }

	void Game::StartGameLoop()
	{
        sf::Clock clock;

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

                m_currentBehaviour->OnEvent(event);
			}

            sf::Time elapsedTime = clock.GetElapsedTime();
			// Logik-Ticks einteilen
            if (elapsedTime.AsMilliseconds() > LOGIC_TICK_MILLISECONDS)
            {
                // Die Uhr zuerst neustarten, damit die Zeit für das Logik-Update
                // mit eingerechnet wird.
                clock.Restart();

                m_currentBehaviour->Update();
            }

			// Clear screen
			m_window.Clear();

			m_currentBehaviour->Render(m_window);

			// Update the window
			m_window.Display();
		}
	}

	void Game::ChangeState(GameStates newState)
	{
        m_currentBehaviour = GetBehaviour(newState);
	}

    Behaviour* Game::GetBehaviour(GameStates gameState)
    {
        static MenuBehaviour menuBehaviour(*this, m_resources);
        static InGameBehaviour inGameBehaviour(*this, m_resources);
        static GameOverBehaviour gameOverBehaviour(*this, m_resources);
        static HighscoreBehaviour highscoreBehaviour(*this, m_resources);

        switch (gameState)
        {
        case GameState_Menu:
            return &menuBehaviour;

        case GameState_InGame:
            return &inGameBehaviour;

        case GameState_GameOver:
            return &gameOverBehaviour;

        case GameState_Highscore:
            return &highscoreBehaviour;

        default:
            return nullptr;
        }
    }
}