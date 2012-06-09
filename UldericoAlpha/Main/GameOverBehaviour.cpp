#include "GameOverBehaviour.h"

#include "Game.h"
#include "ResourcesManager.h"

namespace UldericoAlpha
{
    GameOverBehaviour::GameOverBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		  m_resources(resources)
	{ }

    void GameOverBehaviour::Update()
	{ }

    void GameOverBehaviour::OnEvent(sf::Event const& event)
	{
		if (event.Type == sf::Event::KeyPressed)
        {
            switch (event.Key.Code)
            {
			case sf::Keyboard::Return:
                m_game.ChangeState(GameState_Menu);
                break;
            }
        }
	}

    void GameOverBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{
		sf::Text gameOverText = m_resources.GetText("Game Over");
        gameOverText.SetPosition(300.0f, 200.0f);

		sf::Text returnText = m_resources.GetText("Press Enter to return to menu");
        returnText.SetPosition(50.0f, 300.0f);
        
		target.Draw(gameOverText);
        target.Draw(returnText);
	}
}