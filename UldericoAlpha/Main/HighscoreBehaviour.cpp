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
	{ }

    void GameOverBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{ }
}
