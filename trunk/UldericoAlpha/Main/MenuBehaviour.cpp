#include "MenuBehaviour.h"
#include "Game.h"

namespace UldericoAlpha
{
	const sf::String MenuBehaviour::STR_GAME_START("Start Game");
	const sf::String MenuBehaviour::STR_HIGHSCORE("Highscore");
	const sf::String MenuBehaviour::STR_QUIT("Quit");

	MenuBehaviour::MenuBehaviour(Game& game, ResourcesManager& resources)
		: m_game(game),
		m_resources(resources)
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
		m_menuItems.push_back(m_resources.GetText(STR_GAME_START));
		m_menuItems.push_back(m_resources.GetText(STR_HIGHSCORE));
		m_menuItems.push_back(m_resources.GetText(STR_QUIT));
	}

	void MenuBehaviour::SetMenuItemsPosition()
	{
		float centerX = Game::WINDOW_WIDTH / 2.0f;
		float totalHeight = 0.0f;

		for (auto item = m_menuItems.begin(); item != m_menuItems.end(); ++item)
			totalHeight += item->GetGlobalBounds().Height + MARGIN;

		float top = Game::WINDOW_HEIGHT / 2 - totalHeight / 2;

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
			if (bounds.Contains(static_cast<float>(e.X), static_cast<float>(e.Y)))
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
		sf::Sprite background = m_resources.Get(Sprite_Background);
		target.Draw(background);

		auto title = m_resources.GetText("Ulderico - Alpha");
		title.SetPosition(Game::WINDOW_WIDTH / 2 - title.GetGlobalBounds().Width / 2, 40.0f);
		target.Draw(title);
		
		for (auto item = m_menuItems.begin(); item != m_menuItems.end(); ++item)
			target.Draw(*item);
	}
}