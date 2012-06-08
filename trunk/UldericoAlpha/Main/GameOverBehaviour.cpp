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
		sf::Font gameFont = m_resources.GetFont("game-font");

		sf::Text gameOverText("Game Over", gameFont);
        gameOverText.SetPosition(300.0f, 200.0f);

        sf::Text returnText("Press Enter to return to menu", gameFont);
        returnText.SetPosition(50.0f, 300.0f);
        
		target.Draw(gameOverText);
        target.Draw(returnText);
	}
}