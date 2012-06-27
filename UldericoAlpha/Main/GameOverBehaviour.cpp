#include "GameOverBehaviour.h"

#include "Game.h"
#include "ResourcesManager.h"

#include <cassert>
#include <sstream>

namespace UldericoAlpha
{
    GameOverBehaviour::GameOverBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		  m_resources(resources)
	{ }

    void GameOverBehaviour::Update()
	{
		m_score = m_game.GetFinalScore();

		// TODO: Hier die Highscore-Liste abfragen
		m_isHighscore = true; 
	}

    void GameOverBehaviour::OnEvent(sf::Event const& event)
	{
		if (event.Type == sf::Event::KeyPressed)
			HandleKeyInput(event.Key.Code);
	}

    void GameOverBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{
		sf::Text gameOverText = m_resources.GetText("Game Over");
        gameOverText.SetPosition(300.0f, 50.0f);

		std::ostringstream scoreStream;
		scoreStream << "You have scored " << m_score << " points.";
		sf::Text scoreText = m_resources.GetText(scoreStream.str());
		scoreText.SetPosition(50.0f, 100.0f);

		sf::Text enterNameText = m_resources.GetText("Enter Name:");
		enterNameText.SetPosition(130.0f, 200.0f);

		sf::Text nameText = m_resources.GetText(m_name);
		nameText.SetPosition(150.0f + enterNameText.GetGlobalBounds().Width, 200.0f);

		sf::Text returnText = m_resources.GetText("Press Enter to return to menu");
        returnText.SetPosition(50.0f, 300.0f);
        
		target.Draw(scoreText);
		target.Draw(enterNameText);
		target.Draw(nameText);
		target.Draw(gameOverText);
        target.Draw(returnText);
	}

	void GameOverBehaviour::LeaveGameOver()
	{
		m_score = 0;
		m_name.clear();

		if (m_isHighscore)
			m_game.ChangeState(GameState_Highscore);
		else
			m_game.ChangeState(GameState_Menu);
	}

	void GameOverBehaviour::HandleKeyInput(sf::Keyboard::Key key)
	{
		if (AwaitsNameInput() && IsPartOfName(key))
			AppendToName(key);
		
		if (key == sf::Keyboard::Return)
			LeaveGameOver();
	}

	bool GameOverBehaviour::AwaitsNameInput() const
	{
		return m_isHighscore && m_name.length() < MAX_NAME_LENGTH;
	}

	bool GameOverBehaviour::IsPartOfName(sf::Keyboard::Key key) const
	{
		return sf::Keyboard::A <= key && key <= sf::Keyboard::Z
			|| key == sf::Keyboard::Back;
	}

	void GameOverBehaviour::AppendToName(sf::Keyboard::Key key)
	{
		if (key == sf::Keyboard::Back)
			m_name.pop_back();
		else
		{
			char character = key - sf::Keyboard::A + 'A';
			m_name.push_back(character);
		}
	}
}