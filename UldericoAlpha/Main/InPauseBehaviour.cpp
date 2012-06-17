#include "InPauseBehaviour.h"

#include "Game.h"
#include "ResourcesManager.h"

namespace UldericoAlpha
{
	InPauseBehaviour::InPauseBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		  m_resources(resources)
	{
	}

	void InPauseBehaviour::Update()
	{
	}

	void InPauseBehaviour::OnEvent(sf::Event const& event)
	{
		if (event.Key.Code == sf::Keyboard::P)
			m_game.ChangeState(GameState_InGame);
	}

	void InPauseBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{	
		auto pause = m_resources.GetText("PAUSE");

		float top = Game::WINDOW_HEIGHT / 2.0f - pause.GetGlobalBounds().Height;
		float left = Game::WINDOW_WIDTH / 2.0f - pause.GetGlobalBounds().Width / 2.0f;

		pause.SetPosition(left, top);
		target.Draw(pause);
	}
}