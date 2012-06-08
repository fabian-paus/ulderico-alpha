#include "MenuBehaviour.h"
#include "Game.h"

namespace UldericoAlpha
{
	MenuBehaviour::MenuBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		m_resources(resources)
	{ }

	void MenuBehaviour::Update()
	{
	}

	void MenuBehaviour::OnEvent(sf::Event const& event)
	{
        if (event.Type == sf::Event::KeyPressed)
        {
            switch (event.Key.Code)
            {
            case sf::Keyboard::Space:
                m_game.ChangeState(GameState_InGame);
                break;

            case sf::Keyboard::Escape:
                m_game.Quit();
                break;
            }
        }
	}

	void MenuBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{
		sf::Sprite background = m_resources.GetSprite("background");

		target.Draw(background);

        sf::Font gameFont = m_resources.GetFont("game-font");
        sf::Text startGameText("Press Space to start the game", gameFont);
        startGameText.SetPosition(60.0f, Game::WINDOW_HEIGHT / 2.0f);
        
        target.Draw(startGameText);
	}
}