#include "MenuBehaviour.h"
#include "Game.h"

namespace UldericoAlpha
{
	const sf::String MenuBehaviour::STR_GAME_START("Start Game");
	const sf::String MenuBehaviour::STR_HIGHSCORE("Highscore");
	const sf::String MenuBehaviour::STR_QUIT("Quit");

	MenuBehaviour::MenuBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		m_resources(resources),
		m_gameFont(m_resources.GetFont("game-font"))
	{ 
		InitializeMenuItems();
		SetMenuItemsPosition();
	}

	void MenuBehaviour::Update()
	{
	}

	void MenuBehaviour::InitializeMenuItems()
	{
		m_menuItems.reserve(3);
		m_menuItems.push_back(sf::Text(STR_GAME_START, m_gameFont));
		m_menuItems.push_back(sf::Text(STR_HIGHSCORE, m_gameFont));
		m_menuItems.push_back(sf::Text(STR_QUIT, m_gameFont));
	}

	void MenuBehaviour::SetMenuItemsPosition()
	{
		int top = 0;
		int centerX = Game::WINDOW_WIDTH / 2;
		int totalHeight = 0;

		for (auto item = m_menuItems.begin(); item != m_menuItems.end(); ++item)
			totalHeight += item->GetGlobalBounds().Height + MARGIN;

		top = Game::WINDOW_HEIGHT / 2 - totalHeight / 2;

		for (auto item = m_menuItems.begin(); item != m_menuItems.end(); ++item)
		{
			item->SetPosition(centerX - item->GetGlobalBounds().Width / 2, top);
			top += item->GetGlobalBounds().Height + MARGIN;
		}
	}

	void MenuBehaviour::OnEvent(sf::Event const& event)
	{
        if (event.Type == sf::Event::KeyPressed)
        {
			if (event.Key.Code == sf::Keyboard::Space)
				m_game.ChangeState(GameState_InGame);
			else if (event.Key.Code == sf::Keyboard::Escape)
				m_game.Quit();
        }
		else if (event.Type == sf::Event::MouseButtonPressed)
			HandleMouseClick(event.MouseButton);
	}

	void MenuBehaviour::HandleMouseClick(sf::Event::MouseButtonEvent const& e)
	{
		for (auto item = m_menuItems.begin(); item != m_menuItems.end(); ++item)
		{
			auto bounds = item->GetGlobalBounds();
			auto text = item->GetString();
			if (bounds.Contains(e.X, e.Y))
			{
				if (text == STR_GAME_START)
					m_game.ChangeState(GameState_InGame);
				else if(text == STR_HIGHSCORE)
					m_game.ChangeState(GameState_Highscore);
				else if(text == STR_QUIT)
					m_game.Quit();
				break;
			}
		}		
	}

	void MenuBehaviour::Render(sf::RenderTarget& target, float interpolation)
	{
		sf::Sprite background = m_resources.GetSprite("background");
		target.Draw(background);

		auto title = sf::Text("Ulderico - Alpha", m_gameFont);
		title.SetPosition(Game::WINDOW_WIDTH / 2 - title.GetGlobalBounds().Width / 2, 40.0f);
		target.Draw(title);
		
		for (auto item = m_menuItems.begin(); item != m_menuItems.end(); ++item)
			target.Draw(*item);
	}
}