#include "HighscoreBehaviour.h"
#include "Game.h"
#include "ResourcesManager.h"
#include "HighscoreList.h"

namespace UldericoAlpha
{
	const sf::String HighscoreBehaviour::STR_HIGHSCORELISTE("Highscore List");
	const sf::String HighscoreBehaviour::STR_BACK("Back");
	
	HighscoreBehaviour::HighscoreBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		m_resources(resources)
	{ 
		InitializeHighscoreItems();
		SetHighscoreItemsPosition();
	}

	void HighscoreBehaviour::Update()
	{ 
	}

	void HighscoreBehaviour::InitializeHighscoreItems()
	{
		HighscoreList list;
		list.LoadFromFile();

		HighscoreEntry tmp;
		for( int i = 0; i < HighscoreList::MAX_ENTRIES; i++ )
		{
			tmp = list.GetEntry(i);
			
		}
	}

	void HighscoreBehaviour::SetHighscoreItemsPosition()
	{

	}

	void HighscoreBehaviour::OnEvent(sf::Event const& event)
	{ }

	void HighscoreBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{ }
}

