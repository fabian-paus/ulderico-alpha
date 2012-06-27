#include "Game.h"

#include "MenuBehaviour.h"
#include "InGameBehaviour.h"
#include "InPauseBehaviour.h"
#include "GameOverBehaviour.h"
#include "HighscoreBehaviour.h"

#include <SFML/System/Clock.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace UldericoAlpha
{
    const std::string Game::WINDOW_TITLE = "UldericoAlpha 0.1 alpha ;)";
    static const int WINDOW_STYLE = sf::Style::Titlebar | sf::Style::Close;

	Game::Game() 
        : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
                   WINDOW_TITLE, WINDOW_STYLE),
		  m_frameCount(0),
          m_currentBehaviour(GetBehaviour(GameState_Menu))
          
	{ 
        // Einmalig den Zufallszahlengenerator initialieren
        std::srand(static_cast <unsigned int> (std::time(NULL)));
    }

	void Game::StartGameLoop()
	{
		while (m_window.IsOpen())
		{
			ProcessEvents();
            ProcessLogic();
            RenderGraphic();
            CalculateFPS();
		}
	}

	void Game::ChangeState(GameStates newState)
	{
        m_currentBehaviour = GetBehaviour(newState);
	}

    void Game::Quit()
    {
        m_window.Close();
    }

	void Game::SetFinalScore(int score)
	{
		m_finalScore = score;
	}

	int Game::GetFinalScore() const
	{
		return m_finalScore;
	}

    void Game::ProcessEvents()
    {
        sf::Event event;
        while (m_window.PollEvent(event))
        {
            if (event.Type == sf::Event::Closed)
                m_window.Close();

            m_currentBehaviour->OnEvent(event);
        }
    }

    void Game::ProcessLogic()
    {
        if (m_gameTime.GetElapsedTime().AsMilliseconds() > LOGIC_TICK_MILLISECONDS)
        {
            // Die Uhr zuerst neustarten, damit die Zeit für das Logik-Update
            // mit eingerechnet wird.
            m_gameTime.Restart();

            m_currentBehaviour->Update();
        }
    }

    void Game::RenderGraphic()
    {
        float interpolation = m_gameTime.GetElapsedTime().AsMilliseconds() 
            * 1.0f / LOGIC_TICK_MILLISECONDS;
        m_window.Clear();
        m_currentBehaviour->Render(m_window, interpolation);
        m_window.Display();
    }

    void Game::CalculateFPS()
    {
        ++m_frameCount;
        if (m_frameTime.GetElapsedTime().AsSeconds() >= 2.0f)
        {
            float fps = m_frameCount / m_frameTime.GetElapsedTime().AsSeconds();
            std::cout << "FPS: " << fps << std::endl;
            m_frameTime.Restart();
            m_frameCount = 0;
        } 
    }

    Behaviour* Game::GetBehaviour(GameStates gameState)
    {
        // Die unterschiedlichen Spielverhalten werden hier einmalig angelegt,
        // um Speicherprobleme zu umgehen.
        static MenuBehaviour menuBehaviour(*this, m_resources);
        static InGameBehaviour inGameBehaviour(*this, m_resources);
		static InPauseBehaviour inPauseBehaviour(*this, m_resources);
        static GameOverBehaviour gameOverBehaviour(*this, m_resources);
        static HighscoreBehaviour highscoreBehaviour(*this, m_resources);

        switch (gameState)
        {
        case GameState_Menu:
            return &menuBehaviour;

		case GameState_InPause:
			return &inPauseBehaviour;

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