#include "HighscoreBehaviour.h"

#include "Game.h"
#include "ResourcesManager.h"

namespace UldericoAlpha
{
    HighscoreBehaviour::HighscoreBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		  m_resources(resources)
	{ }

    void HighscoreBehaviour::Update()
	{ }

    void HighscoreBehaviour::OnEvent(sf::Event const& event)
	{ }

    void HighscoreBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{ }
}

