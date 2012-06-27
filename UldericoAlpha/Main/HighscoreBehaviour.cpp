#include "HighscoreBehaviour.h"
#include "Game.h"
#include "ResourcesManager.h"
#include "HighscoreList.h"
#include <sstream>

namespace UldericoAlpha
{
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
		HighscoreList& list = m_game.GetHighscore();
		list.LoadFromFile();

		highscoreItems.reserve(HighscoreList::MAX_ENTRIES);
		
		HighscoreEntry entry;
		for( int i = 0; i < HighscoreList::MAX_ENTRIES; i++ )
		{
			auto entry = list.GetEntry(i);
			std::stringstream stream;
			stream << entry.GetName() << ": " << entry.GetScore();
			auto text = m_resources.GetText(stream.str());
			highscoreItems.push_back(text);
		}
	}

	void HighscoreBehaviour::SetHighscoreItemsPosition()
	{ 
		float centerX = Game::WINDOW_WIDTH / 2.0f;
		float totalHeigth = 0.0f;

		for(auto item = highscoreItems.begin(); item != highscoreItems.end(); ++item)
			totalHeigth += item->GetGlobalBounds().Height + MARGIN;

		float top = Game::WINDOW_HEIGHT / 2 - totalHeigth / 2;

		for(auto item = highscoreItems.begin(); item != highscoreItems.end(); ++item)
		{
			item->SetPosition(centerX - item->GetGlobalBounds().Width / 2, top);
			top += item->GetGlobalBounds().Height + MARGIN;
		}
	}

	void HighscoreBehaviour::OnEvent(sf::Event const& event)
	{
		if(event.Type == sf::Event::KeyPressed)
		{
			if(event.Key.Code == sf::Keyboard::Return)
				m_game.ChangeState(GameState_Menu);
			else if (event.Key.Code == sf::Keyboard::Escape)
				m_game.ChangeState(GameState_Menu);
		}
		else if (event.Type == sf::Event::MouseButtonPressed)
			HandleMouseClick(event.MouseButton);
	}

	void HighscoreBehaviour::HandleMouseClick(sf::Event::MouseButtonEvent const& e)
	{
		// Hier muss überprüft werden ober der "BACK" Button gedrück wurde
	}

	void HighscoreBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{ 
		sf::Sprite background = m_resources.Get(Sprite_Background);
		target.Draw(background);

		auto title = m_resources.GetText("Highscore - List");
		title.SetPosition(Game::WINDOW_WIDTH / 2 - title.GetGlobalBounds().Width / 2, 30.0f);
		target.Draw(title);
		
		for (auto item = highscoreItems.begin(); item != highscoreItems.end(); item++)
			target.Draw(*item);
	}

}

