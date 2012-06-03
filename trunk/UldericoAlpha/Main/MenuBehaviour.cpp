#include "MenuBehaviour.h"

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
		m_game.ChangeState(GameState_Game);
	}

	void MenuBehaviour::Render(sf::RenderWindow& window)
	{
		sf::Sprite background = m_resources.GetSprite("background");

		window.Draw(background);
	}
}